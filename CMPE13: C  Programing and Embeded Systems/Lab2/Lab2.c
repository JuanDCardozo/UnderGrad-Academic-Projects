// **** Include libraries here ****
// Standard libraries
#include <stdio.h>
#include <math.h>

// Microchip libraries
#include <xc.h>
#include <plib.h>

// User libraries
#include "HardwareDefs.h"

// **** Set macros and preprocessor directives ****

// **** Define global, module-level, or external variables here ****

// **** Declare function prototypes ****

/*
 * This function must round a number towards zero if the decimal value is below 0.5
 * and away otherwise. It takes in a double and returns an int.
 */
double Round(double operand);

//It gives the absolute value of a number. It takes a double and returns a double.
double AbsoluteValue(double operand);

/*
 * It converts from Fahrenheit to Celsius. It takes a double in degrees Fahreinheit
 * and returns a double coverted to degrees Celsius.
 */
double FahrenheitToCelsius(double fahr);

/*
 *  It converts from Celsius to Fahrenheit. It takes a double in degrees Celsius
 * and returns a double coverted to degrees Fahrenheit.
 */
double CelsiusToFahrenheit(double celsius);

// It takes in degrees and returns the tangent.
double Tangent(double degrees);

// It takes in two operands and then returns the average of those two numbers as a double.
double Average(double operand_1, double operand_2);

// If this code is used for testing, rename main to something we can call from our testing code.
#ifndef LAB1_TESTING
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

    // osc source, PLL multiplier value, PLL postscaler , RC divisor
    OSCConfig(OSC_POSC_PLL, OSC_PLL_MULT_20, OSC_PLL_POST_1, OSC_FRC_POST_1);

    // Configure the PB bus to run at 1/4th the CPU frequency, so 20MHz.
    OSCSetPBDIV(OSC_PB_DIV_4);

    // Enable multi-vector interrupts
    INTEnableSystemMultiVectoredInt();
    INTEnableInterrupts();

    // Configure UART1.
    UARTConfigure(UART_USED, UART_ENABLE_PINS_TX_RX_ONLY);
    UARTSetFifoMode(UART_USED, UART_INTERRUPT_ON_TX_NOT_FULL | UART_INTERRUPT_ON_RX_NOT_EMPTY);
    UARTSetLineControl(UART_USED, UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1);
    UARTSetDataRate(UART_USED, F_PB, UART_BAUD_RATE);
    UARTEnable(UART_USED, UART_ENABLE | UART_TX | UART_RX);

    // And configure printf/scanf to use UART_USED if it's different from the default of UART2.
    if (UART_USED == UART1) {
        __XC_UART = 1;
    }
#else

int their_main(void)
{
#endif // LAB1_TESTING

    /******************************************************************************
     * Your code goes in between this comment and the following one with asterisks.
     *****************************************************************************/
    // Declare Variables and all initialized to zero.
    char operation = 0, newline = 0;
    double operand_1 = 0, operand_2 = 0, result = 0;

    // Start of Infinite Loop
    while (1) {

        // Greting to Calculator's Program.
        printf("Welcome to Juan's Calculator Progam!\n");

        // Ask to Enter a Mathematical Operation.
        printf("Enter a Mathematical Operation to Perform (*,/,+,-,v,a,c,f,t,r): ");

        // Get the character typed.
        scanf("%c%c", &operation, &newline);

        // Check If the Operant is valid and ask for First Operand
        if (operation == '*' || operation == '/' || operation == 'v' || operation == '+' ||
                operation == '-' || operation == 'a' || operation == 'r' || operation == 'c'
                || operation == 'f' || operation == 't') {

            // Ask to Enter a the first operand
            printf("Enter First Operand: ");

            // Get the character typed.
            scanf("%f%c", &operand_1, &newline);
        }

        // Checks if a second operand is required
        if (operation == '*' || operation == '/' || operation == 'v' ||
                operation == '+' || operation == '-') {

            // Ask to Enter a the Second operand
            printf("Enter Second Operand: ");

            // Get the character typed.
            scanf("%f%c", &operand_2, &newline);
        }

        // Check what operation to perform or say that operator is invalid
        if (operation == '*') { //Multiply

            result = operand_1 * operand_2;

            // Returns the result
            printf("Result of %f * %f: %f\n", operand_1, operand_2, result);

        } else if (operation == '/') { // Division

            result = operand_1 / operand_2;

            // Returns the result
            printf("Result of %f / %f: %f\n", operand_1, operand_2, result);

        } else if (operation == '+') { //Sumation

            result = operand_1 + operand_2;

            // Returns the result
            printf("Result of %f + %f: %f\n", operand_1, operand_2, result);

        } else if (operation == '-') { //Difference

            result = operand_1 - operand_2;

            // Returns the result
            printf("Result of %f - %f: %f\n", operand_1, operand_2, result);

        } else if (operation == 'v') { //Average

            result = Average(operand_1, operand_2);

            // Returns the result
            printf("The average of %f and %f = %f\n", operand_1, operand_2, result);

        } else if (operation == 'a') { //Absoulute Value

            result = AbsoluteValue(operand_1);

            // Returns the result
            printf("Absolute Value of %f: %f\n", operand_1, result);

        } else if (operation == 'c') { //Celsius to Fahrenheit

            result = CelsiusToFahrenheit(operand_1);

            // Returns the result
            printf("Result of (%f deg->F): %f\n", operand_1, result);

        } else if (operation == 'f') { // Fahrenheit to Celsius

            result = FahrenheitToCelsius(operand_1);

            // Returns the result
            printf("Result of (%f deg->C): %f\n", operand_1, result);

        } else if (operation == 't') { // Tangent

            result = Tangent(operand_1);

            // Returns the result
            printf("Result of Tangent (%f): %f\n", operand_1, result);

        } else if (operation == 'r') {

            result = Round(operand_1);

            // Returns the result
            printf("Result of round(%f): %f\n", operand_1, result);
        } else {
            // Say if the operation is invalid
            printf("Invalid Operator! Try Again.\n");
        }
    } // End of while-loop
    /******************************************************************************
     * Your code goes in between this comment and the preceding one with asterisks
     *****************************************************************************/
    while (1);
}

/********************************************************************************
 * Define the Absolute Value function here.
 ********************************************************************************/

double AbsoluteValue(double operand)
{
    if (operand < 0) { // If it is negative then multiply operand by -1
        return (operand*-1);
    } else {
        return operand; // If zero or positive then just return operand
    }
}

/*********************************************************************************
 * Define the Fahrenheit to Celsius function here.
 ********************************************************************************/

double FahrenheitToCelsius(double fahr)
{
    return ((5 * (fahr - 32)) / 9);
}

/*********************************************************************************
 * Define the Celsius to Fahrenheit function here.
 ********************************************************************************/

double CelsiusToFahrenheit(double celsius)
{
    return ((((9 * celsius) / 5)) + 32);
}

/********************************************************************************
 * Define the Average function here.
 *******************************************************************************/

double Average(double operand_1, double operand_2)
{
    return ((operand_1 + operand_2) / 2);
}

/*********************************************************************************
 * Define the Tangent function that takes input in degrees (Note: Your tangent 
 * function relies on a call from the tangent function of math.h which uses 
 * radians).
 ********************************************************************************/

double Tangent(double degrees)
{
    //Declare Temporal Variable
    double resultInRadians;

    // Calculate the Tangent and convert the degrees to radians
    resultInRadians = tan((degrees * (M_PI / 180)));

    return (resultInRadians);

}

/*********************************************************************************
 * Define the Round function here.
 * In order to receive the extra credit your calculator MUST ALSO CORRECTLY utilize
 * this function.
 ********************************************************************************/
double Round(double operand)
{
    if (operand >= 0) {
        operand += 0.5;

        return ((int) operand);
    } else {
        operand -= 0.5;
        return ((int) operand);
    }
}

/**
 * This function overrides the built-in read() function used for stream
 * processing to read a set of characters from UART2.
 * NOTE: It's a blocking call and will wait for data.
 */
int read(int handle, void *buffer, unsigned int len)
{
    int i;
    if (handle == 0) {
        while (!U1STAbits.URXDA) {
            if (U1STAbits.OERR) {
                U1STAbits.OERR = 0;
            }
            continue;
        }
        i = 0;
        while (U1STAbits.URXDA) {
            char tmp = U1RXREG;
            if (tmp == '\r') {
                tmp = '\n';
            }
            *(char*) buffer++ = tmp;
            WriteUART1(tmp);
            i++;
        }
        return i;
    }
    return 0;
}