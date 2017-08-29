// Standard Libraries
#include <stdlib.h>

// User Libraries
#include "Protocol.h"
#include "Field.h"
#include "Oled.h"
#include "Buttons.h"
#include "Ascii.h"
#include "FieldOled.h"
#include "Agent.h"

// My Data
Field myField;
NegotiationData nDataMine;
GuessData gDataMine;

// Enemy's Data
Field enemyField;
NegotiationData nDataOpp;
GuessData gDataOpp;

/**
 * The Init() function for an Agent sets up everything necessary for an agent before the game
 * starts. This can include things like initialization of the field, placement of the boats,
 * etc. The agent can assume that stdlib's rand() function has been seeded properly in order to
 * use it safely within.
 */
void AgentInit(void)
{
    // Initialize the enemys field with unknown
    FieldInit(&enemyField, FIELD_POSITION_UNKNOWN);

    // Initialize my field with empty
    FieldInit(&myField, FIELD_POSITION_EMPTY);

    // Add a small boat randomly
    while (!FieldAddBoat(&myField, rand() % FIELD_ROWS, rand() % FIELD_COLS, rand() % 4,
            FIELD_BOAT_SMALL));

    // Add a medium boat randomly
    while (!FieldAddBoat(&myField, rand() % FIELD_ROWS, rand() % FIELD_COLS, rand() % 4,
            FIELD_BOAT_MEDIUM));

    // Add a large boat randomly
    while (!FieldAddBoat(&myField, rand() % FIELD_ROWS, rand() % FIELD_COLS, rand() % 4,
            FIELD_BOAT_LARGE));

    // Add a huge boat randomly
    while (!FieldAddBoat(&myField, rand() % FIELD_ROWS, rand() % FIELD_COLS, rand() % 4,
            FIELD_BOAT_HUGE));
}

/**
 * The Run() function for an Agent takes in a single character. It then waits until enough
 * data is read that it can decode it as a full sentence via the Protocol interface. This data
 * is processed with any output returned via 'outBuffer', which is guaranteed to be 255
 * characters in length to allow for any valid NMEA0183 messages. The return value should be
 * the number of characters stored into 'outBuffer': so a 0 is both a perfectly valid output and
 * means a successful run.
 * @param in The next character in the incoming message stream.
 * @param outBuffer A string that should be transmit to the other agent. NULL if there is no
 *                  data.
 * @return The length of the string pointed to by outBuffer (excludes \0 character).
 */
int AgentRun(char in, char *outBuffer)
{
    AgentState state = AGENT_STATE_GENERATE_NEG_DATA;
    FieldOledTurn turn = FIELD_OLED_TURN_NONE;
    switch (state) {
    case AGENT_STATE_GENERATE_NEG_DATA:
        //Generate random data to send
        ProtocolGenerateNegotiationData(&nDataMine);

        // Encode de Data generated above
        ProtocolEncodeChaMessage(outBuffer, &nDataMine);

        // Go to next state
        state = AGENT_STATE_SEND_CHALLENGE_DATA;
        break;

    case AGENT_STATE_SEND_CHALLENGE_DATA:
        // Decode de Negotion Data from oponent and store it
        ProtocolDecode(in, &nDataOpp, &gDataOpp);

        // Go to next state
        state = AGENT_STATE_DETERMINE_TURN_ORDER;
        break;

    case AGENT_STATE_DETERMINE_TURN_ORDER:
        // Decode determine data
        ProtocolDecode(in, &nDataOpp, &gDataOpp);

        // Check if if the data received is valid
        if (ProtocolValidateNegotiationData(&nDataOpp)) {
            // Send message to determine order
            ProtocolEncodeDetMessage(outBuffer, &nDataMine);

            // Get whose turn is it
            if (ProtocolGetTurnOrder(&nDataMine, &nDataOpp) == TURN_ORDER_START) {
                turn = FIELD_OLED_TURN_MINE;
                FieldOledDrawScreen(&myField, &enemyField, turn);
                state = AGENT_STATE_SEND_GUESS;
            } else if (ProtocolGetTurnOrder(&nDataMine, &nDataOpp) == TURN_ORDER_DEFER) {
                turn = FIELD_OLED_TURN_THEIRS;
                FieldOledDrawScreen(&myField, &enemyField, turn);
                state = AGENT_STATE_WAIT_FOR_GUESS;
            } else {
                // Clear Oled
                OledClear(OLED_COLOR_BLACK);
                OledUpdate();

                // Print Error
                OledDrawString("ERROR_STRING_ORDERING");
                OledUpdate();

                //Go to Next State
                state = AGENT_STATE_INVALID;
            }

        } else {

            // Clear Oled
            OledClear(OLED_COLOR_BLACK);
            OledUpdate();

            // Print Error
            OledDrawString("ERROR_STRING_NEG_DATA");
            OledUpdate();

            // If it is not valid go to invalid state
            state = AGENT_STATE_INVALID;
        }
        break;

    case AGENT_STATE_SEND_GUESS:

        // Encode Coordinate message
        ProtocolEncodeCooMessage(outBuffer, &gDataMine);

        // Go to next state
        state = AGENT_STATE_INVALID;
        break;

    case AGENT_STATE_WAIT_FOR_HIT:
        //Record Hit Message
        ProtocolDecode(in, &nDataOpp, &gDataOpp);

        if (FieldGetBoatStates(&enemyField) == 0) {
            turn = FIELD_OLED_TURN_NONE;
            FieldOledDrawScreen(&myField, &enemyField, turn);
            state = AGENT_STATE_WON;
        } else {
            FieldUpdateKnowledge(&enemyField, &gDataOpp);
            turn = FIELD_OLED_TURN_THEIRS;
            FieldOledDrawScreen(&myField, &enemyField, turn);
            state = AGENT_STATE_WAIT_FOR_GUESS;
        }

        break;
    case AGENT_STATE_WAIT_FOR_GUESS:
        // Decode determine data
        ProtocolDecode(in, &nDataOpp, &gDataOpp);


        if (AgentGetStatus() == 0) {
            // Set turn to none
            turn = FIELD_OLED_TURN_NONE;

            //Send hit message
            ProtocolEncodeHitMessage(outBuffer, &gDataMine);

            //Go to next state
            state = AGENT_STATE_WON;
        } else {
            // Set turn to mine
            turn = FIELD_OLED_TURN_MINE;

            // Register attack and update the field
            FieldRegisterEnemyAttack(&myField, &gDataOpp);
            FieldOledDrawScreen(&myField, &enemyField, turn);

            // Send hit message
            ProtocolEncodeHitMessage(outBuffer, &gDataMine);

            //Go to next state
            state = AGENT_STATE_WAIT_FOR_HIT;
        }

        break;
    case AGENT_STATE_INVALID:
        break;
    case AGENT_STATE_LOST:
        break;
    case AGENT_STATE_WON:
        break;
    }
    return (strlen(outBuffer));
}

/**
 * StateCheck() returns a 4-bit number indicating the status of that agent's ships. The smallest
 * ship, the 3-length one, is indicated by the 0th bit, the medium-length ship (4 tiles) is the
 * 1st bit, etc. until the 3rd bit is the biggest (6-tile) ship. This function is used within
 * main() to update the LEDs displaying each agents' ship status. This function is similar to
 * Field::FieldGetBoatStates().
 * @return A bitfield indicating the sunk/unsunk status of each ship under this agent's control.
 *
 * @see Field.h:FieldGetBoatStates()
 * @see Field.h:BoatStatus
 */
uint8_t AgentGetStatus(void)
{
    return FieldGetBoatStates(&myField);
}

/**
 * This function returns the same data as `AgentCheckState()`, but for the enemy agent.
 * @return A bitfield indicating the sunk/unsunk status of each ship under the enemy agent's
 *         control.
 *
 * @see Field.h:FieldGetBoatStates()
 * @see Field.h:BoatStatus
 */
uint8_t AgentGetEnemyStatus(void)
{
    return FieldGetBoatStates(&enemyField);
}
