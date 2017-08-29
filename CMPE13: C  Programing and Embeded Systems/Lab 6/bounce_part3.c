// **** Include libraries here ****
// Standard libraries

// Microchip libraries
#include <xc.h>
#include <plib.h>
#include <stdbool.h>

// User libraries
#include "HardwareDefs.h"
#include "Leds.h"
#include "Buttons.h"


// **** Set macros and preprocessor directives ****

// **** Declare any datatypes here ****


// **** Define global, module-level, or external variables here ****
static uint8_t bEvent;
static uint8_t switchesState;
// **** Declare function prototypes ****

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

int main(void)
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

    // Configure Timer 1 using PBCLK as input. This default period will make the LEDs blink at a
    // pretty reasonable rate to start.
    OpenTimer1(T1_ON | T1_SOURCE_INT | T1_PS_1_8, 0xFFFF);

    // Set up the timer interrupt with a priority of 4.
    INTClearFlag(INT_T1);
    INTSetVectorPriority(INT_TIMER_1_VECTOR, INT_PRIORITY_LEVEL_4);
    INTSetVectorSubPriority(INT_TIMER_1_VECTOR, INT_SUB_PRIORITY_LEVEL_0);
    INTEnable(INT_T1, INT_ENABLED);

/***************************************************************************************************
 * Your code goes in between this comment and the following one with asterisks.
 **************************************************************************************************/

    uint8_t bitfield = 0;


LEDS_INIT();
ButtonsInit();

    while (1) {

        // Checks if an event has happened
        if (bEvent) {

            // Check Buttons Down
            if ((bEvent & BUTTON_EVENT_1DOWN)&& !(switchesState & SWITCH_STATE_SW1)) {
                puts("BUTTON_EVENT_1DOWN");
                bitfield ^= 0x03;
            }
            if ((bEvent & BUTTON_EVENT_2DOWN)&& !(switchesState & SWITCH_STATE_SW2)) {
                puts("BUTTON_EVENT_2DOWN");
                 bitfield ^= 0x0C;
            }
             if ((bEvent & BUTTON_EVENT_3DOWN)&& !(switchesState & SWITCH_STATE_SW3)) {
                puts("BUTTON_EVENT_3DOWN");
                 bitfield ^= 0x30;
            }
             if ((bEvent & BUTTON_EVENT_4DOWN)&& !(switchesState & SWITCH_STATE_SW1)) {
                puts("BUTTON_EVENT_4DOWN");
                 bitfield ^= 0xC0;
            }

            // Check Buttons Up
            if ((bEvent & BUTTON_EVENT_1UP)&& (switchesState & SWITCH_STATE_SW1)) {
                puts("BUTTON_EVENT_1UP");
                 bitfield ^= 0x03;
            }
            if ((bEvent & BUTTON_EVENT_2UP)&& (switchesState & SWITCH_STATE_SW2)) {
                puts("BUTTON_EVENT_2UP");
                 bitfield ^= 0x0C;
            }
             if ((bEvent & BUTTON_EVENT_3UP)&& (switchesState & SWITCH_STATE_SW3)) {
                puts("BUTTON_EVENT_3UP");
                 bitfield ^= 0x30;
            }
             if ((bEvent & BUTTON_EVENT_4UP) && (switchesState & SWITCH_STATE_SW4)) {
                puts("BUTTON_EVENT_4UP");
                 bitfield ^= 0xC0;
            }

            // Turns on LED
            LEDS_SET(bitfield);

            // Resets event flag
            bEvent = BUTTON_EVENT_NONE;
        }
    }

    
/***************************************************************************************************
 * Your code goes in between this comment and the preceding one with asterisks
 **************************************************************************************************/

    while (1);
}

/**
 * This is the interrupt for the Timer1 peripheral. It checks for button events and stores them in a
 * module-level variable.
 */
void __ISR(_TIMER_1_VECTOR, ipl4auto) Timer1Handler(void)
{
    // Clear the interrupt flag.
    IFS0CLR = 1 << 4;

    // Check for events
    bEvent = ButtonsCheckEvents();
    switchesState = SWITCH_STATES();

}