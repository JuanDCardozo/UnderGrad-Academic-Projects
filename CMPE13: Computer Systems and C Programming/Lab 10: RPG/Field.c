// Standard Libraries
#include <stdbool.h>

// User Libraries
#include "Field.h"
#include "Protocol.h"

/**
 * FieldInit() will fill the passed field array with the data specified in positionData. Also the
 * lives for each boat are filled according to the `BoatLives` enum.
 * @param f The field to initialize.
 * @param p The data to initialize the entire field to, should be a member of enum
 *                     FieldPosition.
 */
void FieldInit(Field *f, FieldPosition p)// Working
{
    int i = 0, j = 0;

    // This loops populates the field with p
    for (i = 0; i < FIELD_ROWS; i++) {
        for (j = 0; j < FIELD_COLS; j++) {
            f->field[i][j] = p;
        }
    }

    // Initialize the lives of the boats
    f->smallBoatLives = FIELD_BOAT_LIVES_SMALL;
    f->mediumBoatLives = FIELD_BOAT_LIVES_MEDIUM;
    f->largeBoatLives = FIELD_BOAT_LIVES_LARGE;
    f->hugeBoatLives = FIELD_BOAT_LIVES_HUGE;
}

/**
 * Retrieves the value at the specified field position.
 * @param f The Field being referenced
 * @param row The row-component of the location to retrieve
 * @param col The column-component of the location to retrieve
 * @return
 */
FieldPosition FieldAt(const Field *f, uint8_t row, uint8_t col)//Working
{
    return f->field[row][col];
}

/**
 * This function provides an interface for setting individual locations within a Field struct. This
 * is useful when FieldAddBoat() doesn't do exactly what you need. For example, if you'd like to use
 * FIELD_POSITION_CURSOR, this is the function to use.
 *
 * @param f The Field to modify.
 * @param row The row-component of the location to modify
 * @param col The column-component of the location to modify
 * @param p The new value of the field location
 * @return The old value at that field location
 */
FieldPosition FieldSetLocation(Field *f, uint8_t row, uint8_t col, FieldPosition p)// Working
{
    // Temporary variable to hold the previous value of field
    FieldPosition tmp = f->field[row][col];

    // Set field to the new value
    f->field[row][col] = p;
    return tmp;

}

/**
 * FieldAddBoat() places a single ship on the player's field based on arguments 2-5. Arguments 2, 3
 * represent the x, y coordinates of the pivot point of the ship.  Argument 4 represents the
 * direction of the ship, and argument 5 is the length of the ship being placed. All spaces that
 * the boat would occupy are checked to be clear before the field is modified so that if the boat
 * can fit in the desired position, the field is modified as SUCCESS is returned. Otherwise the
 * field is unmodified and STANDARD_ERROR is returned. There is no hard-coded limit to how many
 * times a boat can be added to a field within this function.
 *
 * So this is valid test code:
 * {
 *   Field myField;
 *   FieldInit(&myField);
 *   FieldAddBoat(&myField, 0, 0, FIELD_BOAT_DIRECTION_EAST, FIELD_BOAT_SMALL);
 *   FieldAddBoat(&myField, 1, 0, FIELD_BOAT_DIRECTION_EAST, FIELD_BOAT_MEDIUM);
 *   FieldAddBoat(&myField, 1, 0, FIELD_BOAT_DIRECTION_EAST, FIELD_BOAT_HUGE);
 *   FieldAddBoat(&myField, 0, 6, FIELD_BOAT_DIRECTION_SOUTH, FIELD_BOAT_SMALL);
 * }
 *
 * should result in a field like:
 *  _ _ _ _ _ _ _ _
 * [ 3 3 3       3 ]
 * [ 4 4 4 4     3 ]
 * [             3 ]
 *  . . . . . . . .
 *
 * @param f The field to grab data from.
 * @param row The row that the boat will start from, valid range is from 0 and to FIELD_ROWS - 1.
 * @param col The column that the boat will start from, valid range is from 0 and to FIELD_COLS - 1.
 * @param dir The direction that the boat will face once places, from the BoatDirection enum.
 * @param boatType The type of boat to place. Relies on the FIELD_POSITION_*_BOAT values from the
 * FieldPosition enum.
 * @return true for success, false for failure
 */
bool FieldAddBoat(Field *f, uint8_t row, uint8_t col, BoatDirection dir, BoatType type)
{
    // Function-Scope Variables
    int i = row, j = col;
    FieldPosition p = FIELD_POSITION_EMPTY;
    bool successFlag = true;
    int lifeCounter = 0;

    // Add the number of lives and set position depeding on the boat type
    switch (type) {
    case FIELD_BOAT_SMALL:
        lifeCounter = FIELD_BOAT_LIVES_SMALL;
        p = FIELD_POSITION_SMALL_BOAT;
        break;
    case FIELD_BOAT_MEDIUM:
        lifeCounter = FIELD_BOAT_LIVES_MEDIUM;
        p = FIELD_POSITION_MEDIUM_BOAT;
        break;
    case FIELD_BOAT_LARGE:
        lifeCounter = FIELD_BOAT_LIVES_LARGE;
        p = FIELD_POSITION_LARGE_BOAT;
        break;
    case FIELD_BOAT_HUGE:
        lifeCounter = FIELD_BOAT_LIVES_HUGE;
        p = FIELD_POSITION_HUGE_BOAT;
        break;
    }

    // Set the boat on the field
    switch (dir) {
    case FIELD_BOAT_DIRECTION_NORTH:

        // Check if it is withing the limits of the field and then adds the boat
        if ((row - lifeCounter) < 0) {
            successFlag = false;
        } else {
            // Adds the boat
            for (; lifeCounter > 0; lifeCounter--) {
                // Set flag to false if there is another boat at that place
                if (f->field[i][j] != FIELD_POSITION_EMPTY) {
                    successFlag = false;
                    break;
                } else {
                    FieldSetLocation(f, i--, j, p);
                }

            }// For-Loop
        }
        break;

    case FIELD_BOAT_DIRECTION_EAST:
        // Check if it is withing the limits of the field and then adds the boat
        if ((col + lifeCounter) > (FIELD_COLS - 1)) {
            successFlag = false;
        } else {
            // Adds boat
            for (; lifeCounter > 0; lifeCounter--) {

                // Set flag to false if there is another boat at that place
                if (f->field[i][j] != FIELD_POSITION_EMPTY) {
                    successFlag = false;
                    break;
                } else {
                    FieldSetLocation(f, i, j++, p);
                }

            }// For-Loop
        }
        break;

    case FIELD_BOAT_DIRECTION_SOUTH:
        // Check if it is withing the limits of the field and then adds the boat
        if ((row + lifeCounter) > (FIELD_ROWS - 1)) {
            successFlag = false;
        } else {
            // Adds Boat
            for (; lifeCounter > 0; lifeCounter--) {
                // Set flag to false if there is another boat at that place
                if (f->field[i][j] != FIELD_POSITION_EMPTY) {
                    successFlag = false;
                    break;
                } else {
                    FieldSetLocation(f, i++, j, p);
                }

            }// For-Loop
        }
        break;

    case FIELD_BOAT_DIRECTION_WEST:
        // Check if it is withing the limits of the field and then adds the boat
        if ((row - lifeCounter) < 0) {
            successFlag = false;
        } else {
            // Adds Boat
            for (; lifeCounter > 0; lifeCounter--) {
                // Set flag to false if there is another boat at that place
                if (f->field[i][j] != FIELD_POSITION_EMPTY) {
                    successFlag = false;
                    break;
                } else {
                    FieldSetLocation(f, i, j--, p);
                }
            }// For-Loop
        }
        break;

    default:
        // Sets flag to flase to represent FAILURE
        successFlag = false;
        break;
    }

    return successFlag;
}

/**
 * This function registers an attack at the gData coordinates on the provided field. This means that
 * 'state' is updated with a FIELD_POSITION_HIT or FIELD_POSITION_MISS depending on what was at the
 * coordinates indicated in 'gData'. 'gData' is also updated with the proper HitStatus value
 * depending on what happened. Finally this function also reduces the lives for any boat that was
 * hit from this attack.
 * @param f The field to check against and update.
 * @param gData The coordinates that were guessed. The HIT result is stored in gData->hit as an
 *               output.
 * @return The data that was stored at the field position indicated by gData.
 */
FieldPosition FieldRegisterEnemyAttack(Field *f, GuessData *gData)
{
    // Set Default hit message to HIT_HIT
    gData->hit = HIT_HIT;

    // Choose what to do depending on what is at the specified position on the field
    switch (f->field[gData->row][gData->col]) {
    case FIELD_POSITION_SMALL_BOAT:
        // Decrements lives and sends Small boat sunk message if life 0
        if (--f->smallBoatLives == 0) {
            gData->hit = HIT_SUNK_SMALL_BOAT;
        }
        break;

    case FIELD_POSITION_MEDIUM_BOAT:
        // Decrements lives and sends Medium boat sunk message if life 0
        if (--f->mediumBoatLives == 0) {
            gData->hit = HIT_SUNK_MEDIUM_BOAT;
        }
        break;

    case FIELD_POSITION_LARGE_BOAT:
        // Decrements lives and sends Large boat sunk message if life 0
        if (--f->largeBoatLives == 0) {
            gData->hit = HIT_SUNK_LARGE_BOAT;
        }
        break;

    case FIELD_POSITION_HUGE_BOAT:
        // Decrements lives and sends Huge boat sunk message if life 0
        if (--f->hugeBoatLives == 0) {
            gData->hit = HIT_SUNK_HUGE_BOAT;
        }
        break;

    default:
        // Default Message of MISS
        gData->hit = HIT_MISS;
        break;
    }

    // Check how to update the field
    if (gData->hit == HIT_HIT) {
        FieldSetLocation(f, gData->row, gData->col, FIELD_POSITION_HIT);
    } else {
        FieldSetLocation(f, gData->row, gData->col, FIELD_POSITION_MISS);
    }

    return gData->hit;
}

/**
 * This function updates the FieldState representing the opponent's game board with whether the
 * guess indicated within gData was a hit or not. If it was a hit, then the field is updated with a
 * FIELD_POSITION_HIT at that position. If it was a miss, display a FIELD_POSITION_EMPTY instead, as
 * it is now known that there was no boat there. The FieldState struct also contains data on how
 * many lives each ship has. Each hit only reports if it was a hit on any boat or if a specific boat
 * was sunk, this function also clears a boats lives if it detects that the hit was a
 * HIT_SUNK_*_BOAT.
 * @param f The field to grab data from.
 * @param gData The coordinates that were guessed along with their HitStatus.
 * @return The previous value of that coordinate position in the field before the hit/miss was
 * registered.
 */
FieldPosition FieldUpdateKnowledge(Field *f, const GuessData *gData)
{
    // Temprary Variable with the previous data of that coordinate
    FieldPosition tmp = f->field[gData->row][gData->col];

    // Check how to update the Field
    if (gData->hit == HIT_MISS) {
        FieldSetLocation(f, gData->row, gData->col, FIELD_POSITION_EMPTY);
    } else {
        FieldSetLocation(f, gData->row, gData->col, FIELD_POSITION_HIT);

        // Check if a sunk message was received and clear that boat's life
        if (gData->hit == HIT_SUNK_SMALL_BOAT) {
            f->smallBoatLives = 0;
        }

        if (gData->hit == HIT_SUNK_MEDIUM_BOAT) {
            f->mediumBoatLives = 0;

        }

        if (gData->hit == HIT_SUNK_LARGE_BOAT) {
            f->largeBoatLives = 0;
        }

        if (gData->hit == HIT_SUNK_HUGE_BOAT) {
            f->hugeBoatLives = 0;
        }
    }
    return tmp;
}

/**
 * This function returns the alive states of all 4 boats as a 4-bit bitfield (stored as a uint8).
 * The boats are ordered from smallest to largest starting at the least-significant bit. So that:
 * 0b00001010 indicates that the small boat and large boat are sunk, while the medium and huge boat
 * are still alive. See the BoatStatus enum for the bit arrangement.
 * @param f The field to grab data from.
 * @return A 4-bit value with each bit corresponding to whether each ship is alive or not.
 */
uint8_t FieldGetBoatStates(const Field *f)
{
    uint8_t bitfield = 0;
    // Check if the boat is still alive and then OR's its value
    if (f->smallBoatLives != 0) {
        bitfield |= FIELD_BOAT_SMALL;
    }
    if (f->mediumBoatLives != 0) {
        bitfield |= FIELD_BOAT_MEDIUM;
    }
    if (f->largeBoatLives != 0) {
        bitfield |= FIELD_BOAT_LARGE;
    }
    if (f->hugeBoatLives != 0) {
        bitfield |= FIELD_BOAT_HUGE;
    }
    return bitfield;
}
