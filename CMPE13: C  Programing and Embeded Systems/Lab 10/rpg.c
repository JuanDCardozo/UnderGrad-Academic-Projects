// **** Include libraries here ****
// Standard libraries
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdbool.h>

// Microchip libraries
#include <xc.h>
#include <plib.h>

// User libraries
#include "HardwareDefs.h"
#include "Game.h"
#include "Player.h"
#include "Leds.h"
#include "Common.h"
#include "Oled.h"
#include "Adc.h"
#include "Buttons.h"



// **** Set any macros or preprocessor directives here ****


// **** Declare any data types here ****

// **** Define any global or external variables here ****
static bool adcEventFlag = false;
static bool buttonEventFlag = false;
static uint8_t buttonEvents = 0;

// **** Declare any function prototypes here ****

// Configuration Bit settings
// SYSCLK = 80 MHz (8MHz Crystal/ FPLLIDIV * FPLLMUL / FPLLODIV)
// PBCLK = 20 MHz
// Primary Osc w/PLL (XT+,HS+,EC+PLL)
#pragma config FPLLIDIV   = DIV_2     // Set the PLL input divider to 2
#pragma config FPLLMUL    = MUL_20    // Set the PLL multiplier to 20
#pragma config FPLLODIV   = DIV_1     // Don't modify the PLL output.
#pragma config FNOSC      = PRIPLL    // Set the primary oscillator to internal RC w/ PLL
#pragma config FSOSCEN    = OFF       // Disable the secondary oscillator
#pragma config IESO       = OFF       // Internal/External Switch O
#pragma config POSCMOD    = XT        // Primary Oscillator Configuration
#pragma config OSCIOFNC   = OFF       // Disable clock signal output
#pragma config FPBDIV     = DIV_4     // Set the peripheral clock to 1/4 system clock
#pragma config FCKSM      = CSECMD    // Clock Switching and Monitor Selection
#pragma config WDTPS      = PS1       // Specify the watchdog timer interval (unused)
#pragma config FWDTEN     = OFF       // Disable the watchdog timer
#pragma config ICESEL     = ICS_PGx2  // Allow for debugging with the Uno32
#pragma config PWP        = OFF       // Keep the program flash writeable
#pragma config BWP        = OFF       // Keep the boot flash writeable
#pragma config CP         = OFF       // Disable code protect

int main()
{
    // Configure the device for maximum performance but do not change the PBDIV
    // Given the options, this function will change the flash wait states, RAM
    // wait state and enable prefetch cache but will not change the PBDIV.
    // The PBDIV value is already set via the pragma FPBDIV option above..
    SYSTEMConfig(F_SYS, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);

    // Auto-configure the PIC32 for optimum performance at the specified operating frequency.
    SYSTEMConfigPerformance(F_SYS);

    // osc source, PLL multipler value, PLL postscaler , RC divisor
    OSCConfig(OSC_POSC_PLL, OSC_PLL_MULT_20, OSC_PLL_POST_1, OSC_FRC_POST_1);

    // Configure the PB bus to run at 1/4th the CPU frequency, so 20MHz.
    OSCSetPBDIV(OSC_PB_DIV_4);

    // Enable multi-vector interrupts
    INTEnableSystemMultiVectoredInt();
    INTEnableInterrupts();

    // Configure Timer 2 using PBCLK as input. We configure it using a 1:16 prescalar, so each timer
    // tick is actually at F_PB / 16 Hz, so setting PR2 to F_PB / 16 / 100 yields a .01s timer.
    OpenTimer2(T2_ON | T2_SOURCE_INT | T2_PS_1_16, F_PB / 16 / 100);

    // Set up the timer interrupt with a medium priority of 4.
    INTClearFlag(INT_T2);
    INTSetVectorPriority(INT_TIMER_2_VECTOR, INT_PRIORITY_LEVEL_4);
    INTSetVectorSubPriority(INT_TIMER_2_VECTOR, INT_SUB_PRIORITY_LEVEL_0);
    INTEnable(INT_T2, INT_ENABLED);

    /******************************** Your custom code goes below here ********************************/
    //Define Variables
    uint16_t adcValue = 0;
    int i = 0, j = 0;
    char title[GAME_MAX_ROOM_TITLE_LENGTH];
    char desc[GAME_MAX_ROOM_DESC_LENGTH];
    char buffer[OLED_CHARS_PER_LINE * OLED_NUM_LINES];
    char line1[OLED_CHARS_PER_LINE];
    char line2[OLED_CHARS_PER_LINE];
    char line3[OLED_CHARS_PER_LINE];
    char line4[OLED_CHARS_PER_LINE];

    //Initialize the necesarry I/O
    OledInit();
    ButtonsInit();
    AdcInit();
    LEDS_INIT();


    //Initialize the Game, if error then FATAL_ERROR.
    if (!GameInit()) {
        FATAL_ERROR();
    }

    // Get the Title of the Starting Room and update OLED
    GameGetCurrentRoomTitle(title);
    GameGetCurrentRoomDescription(desc);

    sprintf(buffer, "%s", title);


    while (1) {


        //Set the leds of current room exits
        LEDS_SET(GameGetCurrentRoomExits());

        if (buttonEventFlag == true) {
            buttonEventFlag = false;
            if (buttonEvents & BUTTON_EVENT_4DOWN) {
                if (GameGoNorth() == STANDARD_ERROR) {
                    FATAL_ERROR();
                }
            } else if (buttonEvents & BUTTON_EVENT_3DOWN) {
                if (GameGoEast() == STANDARD_ERROR) {
                    FATAL_ERROR();
                }
            } else if (buttonEvents & BUTTON_EVENT_2DOWN) {
                if (GameGoSouth() == STANDARD_ERROR) {
                    FATAL_ERROR();
                }
            } else if (buttonEvents & BUTTON_EVENT_1DOWN) {
                if (GameGoWest() == STANDARD_ERROR) {
                    FATAL_ERROR();
                }
            }

            //Update the Room's Title
            GameGetCurrentRoomTitle(title);

            // Update the Room's Description
            GameGetCurrentRoomDescription(desc);
            //            sprintf(buffer, "%s", title);
            //            i = 0;
            //            j =0;
        }

        if (adcEventFlag == true) {
            adcEventFlag = false;
            //            if(adcValue != AdcRead()){
            //
            //            adcValue = AdcRead();
            //            }
            if (adcValue < 255) {
                i = 0;
                while (i < OLED_CHARS_PER_LINE) {
                    line1[i] = title[i];
                    ++i;
                }
                j = 0;
                while (j < OLED_CHARS_PER_LINE) {
                    line2[j++] = desc[i++];
                }
                j = 0;
                while (j < OLED_CHARS_PER_LINE) {
                    line3[j++] = desc[i++];
                }
                j = 0;
                while (j < OLED_CHARS_PER_LINE) {
                    line4[j++] = desc[i++];
                }

            } else if ((adcValue > 256) && (adcValue < 512)) {
                j = 0;
                while (j < OLED_CHARS_PER_LINE) {
                    line1[j] = line2[j];
                    ++j;
                }
                j = 0;
                while (j < OLED_CHARS_PER_LINE) {
                    line2[j] = line3[j];
                    ++j;
                }
                j = 0;
                while (j < OLED_CHARS_PER_LINE) {
                    line3[j] = line4[j];
                }
                j = 0;
                while (j < OLED_CHARS_PER_LINE) {
                    line4[j++] = desc[i++];
                }

            } else if ((adcValue > 512) && (adcValue < 768)) {
                j = 0;
                while (j < OLED_CHARS_PER_LINE) {
                    line1[j] = line3[j];
                    ++j;
                }
                j = 0;
                while (j < OLED_CHARS_PER_LINE) {
                    line2[j] = line4[j];
                    ++j;
                }

                j = 0;
                while (j < OLED_CHARS_PER_LINE) {
                    line3[j++] = desc[i++];
                }

                j = 0;
                while (j < OLED_CHARS_PER_LINE) {
                    line4[j++] = desc[i++];
                }


            } else if ((adcValue > 768) && (adcValue < 1024)) {
                j = 0;
                while (j < OLED_CHARS_PER_LINE) {
                    line1[j] = line4[j];
                    ++j;
                }
                j = 0;
                while (j < OLED_CHARS_PER_LINE) {
                    line2[j++] = desc[i++];
                }

                j = 0;
                while (j < OLED_CHARS_PER_LINE) {
                    line3[j++] = desc[i++];
                }

                j = 0;
                while (j < OLED_CHARS_PER_LINE) {
                    line4[j++] = desc[i++];
                }


            }
            sprintf(buffer, "%s\n%s\n%s\n%s", line1, line2, line3, line4);
        }
        OledClear(OLED_COLOR_BLACK);
        OledDrawString(buffer);
        OledUpdate();
    }

    /**************************************************************************************************/
    while (1);
}

/**
 * Timer2 interrupt. Checks for button events.
 */
void __ISR(_TIMER_2_VECTOR, ipl4auto) TimerInterrupt100Hz(void)
{
    // Clear the interrupt flag.
    IFS0CLR = 1 << 8;

    // Check button event and set flag
    buttonEvents = ButtonsCheckEvents();
    if (buttonEvents) {
        buttonEventFlag = true;
    }

    //Check Adc event and set flag
    if (AdcChanged()) {
        adcEventFlag = true;
    }


}