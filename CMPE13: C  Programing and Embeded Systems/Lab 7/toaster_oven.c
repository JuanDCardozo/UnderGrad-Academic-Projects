// **** Include libraries here ****
// Standard libraries
#include <stdbool.h>

// Microchip libraries
#include <xc.h>
#include <plib.h>

// User libraries
#include "HardwareDefs.h"
#include "Oled.h"
#include "Ascii.h"
#include "Leds.h"
#include "Adc.h"
#include "Buttons.h"


// **** Set any macros or preprocessor directives here ****
// Set a macro for resetting the timers, makes the code a little clearer.
#define TIMER_2HZ_RESET() (TMR1 = 0)
#define TIMER_5HZ_RESET() (TMR3 = 0)

// Define Long Press
#define LONG_PRESS 5

//Oven States Picture
#define BAKE \
"|\x01\x01\x01\x01\x01|  Mode: Bake\n"\
"|     |  Time: %2d:%02d\n"\
"|-----|  Temp: %d\xF8 F\n"\
"|\x03\x03\x03\x03\x03|"

#define TEMP_OFF \
"|\x02\x02\x02\x02\x02|  Mode: Bake\n"\
"|     |  Time: %2d:%02d\n"\
"|-----| >Temp: %d\xF8 F\n"\
"|\x04\x04\x04\x04\x04|"

#define TIME_OFF \
"|\x02\x02\x02\x02\x02|  Mode: Bake\n"\
"|     | >Time: %2d:%02d\n"\
"|-----|  Temp: %d\xF8 F\n"\
"|\x04\x04\x04\x04\x04|"

#define TOAST \
"|\x02\x02\x02\x02\x02|  Mode: Toast\n"\
"|     |  Time: %2d:02%d\n"\
"|-----|\n"\
"|\x03\x03\x03\x03\x03|"

#define TOAST_OFF \
"|\x02\x02\x02\x02\x02|  Mode: Toast\n"\
"|     |  Time: %2d:02%d\n"\
"|-----|\n"\
"|\x04\x04\x04\x04\x04|"

#define BROIL \
"|\x01\x01\x01\x01\x01|  Mode: Bake\n"\
"|     |  Time: %2d:02%d\n"\
"|-----|  Temp: 500\xF8 F\n"\
"|\x03\x03\x03\x03\x03|"

#define BROIL_OFF \
"|\x02\x02\x02\x02\x02|  Mode: Bake\n"\
"|     |  Time: %2d:02%d\n"\
"|-----|  Temp: 500\xF8 F\n"\
"|\x04\x04\x04\x04\x04|"
// **** Declare any datatypes here ****

typedef struct ovenStateData {
    int cookingTimeLeft;
    int initCookingTime;
    int temp;
    int ovenState;
    int cookingMode;
    int buttonCounter;
    int inputSelection;
} ovenStateData;

// **** Define any module-level, global, or external variables here ****
static ovenStateData ovenData;
static uint8_t bEvent = 0;
static bool buttonEventFlag3 = false;
static bool buttonEventFlag4 = false;

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

    // Set up the UART peripheral so we can send serial data.
    UARTConfigure(UART_USED, UART_ENABLE_PINS_TX_RX_ONLY);
    UARTSetFifoMode(UART_USED, UART_INTERRUPT_ON_TX_NOT_FULL | UART_INTERRUPT_ON_RX_NOT_EMPTY);
    UARTSetLineControl(UART_USED, UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1);
    UARTSetDataRate(UART_USED, F_PB, UART_BAUD_RATE);
    UARTEnable(UART_USED, UART_ENABLE_FLAGS(UART_TX));

    // And configure printf/scanf to use UART_USED if it's different from the default of UART2.
    if (UART_USED == UART1) {
        __XC_UART = 1;
    }

    // Configure Timer 1 using PBCLK as input. We configure it using a 1:256 prescalar, so each timer
    // tick is actually at F_PB / 256 Hz, so setting PR1 to F_PB / 256 / 2 yields a 0.5s timer.
    OpenTimer1(T1_ON | T1_SOURCE_INT | T1_PS_1_256, F_PB / 256 / 2);

    // Set up the timer interrupt with a medium priority of 4.
    INTClearFlag(INT_T1);
    INTSetVectorPriority(INT_TIMER_1_VECTOR, INT_PRIORITY_LEVEL_4);
    INTSetVectorSubPriority(INT_TIMER_1_VECTOR, INT_SUB_PRIORITY_LEVEL_0);
    INTEnable(INT_T1, INT_ENABLED);

    // Configure Timer 2 using PBCLK as input. We configure it using a 1:16 prescalar, so each timer
    // tick is actually at F_PB / 16 Hz, so setting PR2 to F_PB / 16 / 100 yields a .01s timer.
    OpenTimer2(T2_ON | T2_SOURCE_INT | T2_PS_1_16, F_PB / 16 / 100);

    // Set up the timer interrupt with a medium priority of 4.
    INTClearFlag(INT_T2);
    INTSetVectorPriority(INT_TIMER_2_VECTOR, INT_PRIORITY_LEVEL_4);
    INTSetVectorSubPriority(INT_TIMER_2_VECTOR, INT_SUB_PRIORITY_LEVEL_0);
    INTEnable(INT_T2, INT_ENABLED);

    // Configure Timer 3 using PBCLK as input. We configure it using a 1:256 prescalar, so each timer
    // tick is actually at F_PB / 256 Hz, so setting PR3 to F_PB / 256 / 5 yields a .2s timer.
    OpenTimer3(T3_ON | T3_SOURCE_INT | T3_PS_1_256, F_PB / 256 / 5);

    // Set up the timer interrupt with a medium priority of 4.
    INTClearFlag(INT_T3);
    INTSetVectorPriority(INT_TIMER_3_VECTOR, INT_PRIORITY_LEVEL_4);
    INTSetVectorSubPriority(INT_TIMER_3_VECTOR, INT_SUB_PRIORITY_LEVEL_0);
    INTEnable(INT_T3, INT_ENABLED);

    /***************************************************************************************************
     * Your code goes in between this comment and the following one with asterisks.
     **************************************************************************************************/

    // State Machine States

    enum {
        RESET,
        START,
        PENDING_SELECTOR_CHANGE,
        COUNTDOWN,
        PENDING_RESET
    };

    // Input Selection States

    enum {
        TIME,
        TEMP
    };

    //Baking Modes

    enum {
        BAKE_MODE,
        TOAST_MODE,
        BROIL_MODE
    };

    //Initialize all the required Hardware
    ButtonsInit();
    LEDS_INIT();
    OledInit();
    AdcInit();

    //Define Variables
    char oven[60];
    ovenData.ovenState = RESET;

    // State Machine
    while (1) {
        switch (ovenData.ovenState) {
        case RESET:
            // Set Values to Default
            ovenData.inputSelection = TIME;
            ovenData.temp = 350;
            ovenData.initCookingTime = 1;
            ovenData.cookingMode = BAKE_MODE;

            //Update OLED
            sprintf(oven, TIME_OFF, ovenData.initCookingTime / 60,
                    ovenData.initCookingTime % 60, ovenData.temp);
            ovenData.ovenState = START;
            break;

        case START:
            if (ovenData.cookingMode == BAKE_MODE) {//Bake Mode
                if (AdcChanged() && (ovenData.inputSelection == TIME)) {
                    ovenData.initCookingTime = (AdcRead() >> 2) + 1;
                    ovenData.ovenState = START;
                    sprintf(oven, TIME_OFF, ovenData.initCookingTime / 60,
                            ovenData.initCookingTime % 60, ovenData.temp);
                } else if (AdcChanged() && (ovenData.inputSelection == TEMP)) {
                    ovenData.temp = (AdcRead() >> 2) + 300;
                    ovenData.ovenState = START;
                    sprintf(oven, TEMP_OFF, ovenData.initCookingTime / 60,
                            ovenData.initCookingTime % 60, ovenData.temp);
                }

            } else if (ovenData.cookingMode == TOAST_MODE) { //Toast Mode
                if (AdcChanged()) {
                    ovenData.initCookingTime = (AdcRead() >> 2) + 1;
                    ovenData.ovenState = START;
                    sprintf(oven, TOAST_OFF, ovenData.initCookingTime / 60,
                            ovenData.initCookingTime % 60);
                }

            } else if (ovenData.cookingMode == BROIL_MODE) {//Broil Mode
                if (AdcChanged()) {
                    ovenData.initCookingTime = (AdcRead() >> 2) + 1;
                    ovenData.ovenState = START;
                }
                sprintf(oven, BROIL_OFF, ovenData.initCookingTime / 60,
                        ovenData.initCookingTime % 60);
            }

            // Change Baking Mode or input selection
            if ((bEvent & BUTTON_EVENT_3DOWN) && buttonEventFlag3) {
                buttonEventFlag3 = false;
                ovenData.buttonCounter = 0;
                ovenData.ovenState = PENDING_SELECTOR_CHANGE;
                TIMER_5HZ_RESET();
            }

            // Turn On Oven
            if ((bEvent & BUTTON_EVENT_4DOWN) && buttonEventFlag4) {
                buttonEventFlag4 = false;
                ovenData.ovenState = COUNTDOWN;
                ovenData.cookingTimeLeft = ovenData.initCookingTime;
                TIMER_2HZ_RESET();
                if (ovenData.cookingMode == BAKE_MODE) {//Bake Mode
                    sprintf(oven, BAKE, ovenData.initCookingTime / 60,
                            ovenData.initCookingTime % 60, ovenData.temp);
                } else if (ovenData.cookingMode == TOAST_MODE) { //Toast Mode
                    sprintf(oven, TOAST, ovenData.initCookingTime / 60,
                            ovenData.initCookingTime % 60);
                } else if (ovenData.cookingMode == BROIL_MODE) {//Broil Mode
                    sprintf(oven, BROIL, ovenData.initCookingTime / 60,
                            ovenData.initCookingTime % 60);
                }
            }

            break;

        case PENDING_SELECTOR_CHANGE:

            if ((ovenData.buttonCounter < LONG_PRESS)) {
                if (ovenData.cookingMode == BAKE_MODE) {
                    ovenData.cookingMode = TOAST_MODE;
                } else if (ovenData.cookingMode == TOAST_MODE) {
                    ovenData.cookingMode = BROIL_MODE;
                } else if (ovenData.cookingMode == BROIL_MODE) {
                    ovenData.cookingMode = BAKE_MODE;
                }
            } else {
                ovenData.inputSelection = TEMP;
            }
            ovenData.ovenState = START;
            break;
        case COUNTDOWN:
            LEDS_SET(0xFF);
            ovenData.ovenState = START;
            break;
        case PENDING_RESET:
            break;
        }

        OledDrawString(oven);
        OledUpdate();
    }
    /***************************************************************************************************
     * Your code goes in between this comment and the preceding one with asterisks
     **************************************************************************************************/
    while (1);
}

void __ISR(_TIMER_1_VECTOR, ipl4auto) TimerInterrupt2Hz(void)
{
    // Clear the interrupt flag.
    IFS0CLR = 1 << 4;

    //Check for buttonEvent 4
    if (BUTTON_STATES() & BUTTON_STATE_4) {
        buttonEventFlag4 = true;
    }



}

void __ISR(_TIMER_3_VECTOR, ipl4auto) TimerInterrupt5Hz(void)
{
    // Clear the interrupt flag.
    IFS0CLR = 1 << 12;
    ++ovenData.buttonCounter;
    if (BUTTON_STATES() & BUTTON_STATE_3) {
        buttonEventFlag3 = true;
    }

}

void __ISR(_TIMER_2_VECTOR, ipl4auto) TimerInterrupt100Hz(void)
{
    // Clear the interrupt flag.
    IFS0CLR = 1 << 8;

    //Check for Button Events
    bEvent = ButtonsCheckEvents();
}