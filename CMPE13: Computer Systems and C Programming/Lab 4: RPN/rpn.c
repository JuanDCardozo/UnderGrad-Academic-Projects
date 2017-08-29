// **** Include libraries here ****
// Standard libraries
#include <stdio.h>

// Microchip libraries
#include <xc.h>
#include <plib.h>

// User libraries
#include "HardwareDefs.h"
#include "Stack.h"

// **** Set macros and preprocessor directives ****
#define TEST_ON 1
#define TEST_OFF 0
#define MAX_CHAR 60

// **** Define global, module-level, or external variables here ****

// **** Declare function prototypes ****
/*
 * Function prototype for ProcessBackspaces() - This function should be defined
 * below main after the related comment.
 */
int ProcessBackspaces(char *rpn_sentence);

// If this code is used for testing, rename main to something we can call from our testing code. We
// also skip all processor configuration and initialization code.
#ifndef LAB4_TESTING
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
    UARTEnable(UART_USED, UART_ENABLE | UART_TX | UART_RX);

    // And configure printf/scanf to use UART_USED if it's different from the default of UART2.
    if (UART_USED == UART1) {
        __XC_UART = 1;
    }
#else

int their_main(void)
{
#endif // LAB4_TESTING

    /******************************** Your custom code goes below here *******************************/

#if TEST_OFF
    // Declare Variabes for the Unit tests;
    int counterPassed = 0, counterTests = 0, i = 0, value = 0;
    struct Stack test;

#if TEST_ON

    StackInit(&test);
    ++counterTests;
    if ((test.currentItemIndex == -1) && (test.initialized == true)) {
        ++counterPassed;
        printf("----------------------------\n"
                "*StackInit() Test: PASSED\n"
                " -Index (-1): %d\n"
                " -Init Value (true/1): %d\n"
                "----------------------------\n"
                , test.currentItemIndex, test.initialized);
    } else {
        printf("----------------------------\n"
                "*StackInit() Test: FAILED\n"
                " -Index (-1): %d\n"
                " -Init Value (true/1): %d\n"
                "----------------------------\n"
                , test.currentItemIndex, test.initialized);
    }
#endif // Test StackInit()

#if TEST_ON
    ++counterTests;
    if (StackPush(&test, 1.0) == SUCCESS) {
        ++counterPassed;
        printf("----------------------------\n"
                "*StackIsEmpty() Test: PASSED\n"
                " -Index  (0):%d\n"
                " -Item   (1):%f\n"
                "----------------------------\n"
                , test.currentItemIndex, test.stackItems[test.currentItemIndex]);
    } else {
        printf("----------------------------\n"
                "*StackIsEmpty() Test: FAILED\n"
                " -Index  (0): %d\n"
                " -Item   (1): %f\n"
                "----------------------------\n"
                , test.currentItemIndex, test.stackItems[test.currentItemIndex]);
    }
#endif // Test StackIsEmpty()

#if TEST_ON
    ++counterTests;


    if (StackPush(&test, 4) == SUCCESS) {
        ++counterPassed;
        printf("----------------------------\n"
                "*StackPush() Test: PASSED\n"
                " -Index  (0):%f\n"
                " -Item   (4):%f\n"
                "----------------------------\n"
                , test.currentItemIndex, test.stackItems[test.currentItemIndex]);
    } else {
        printf("----------------------------\n"
                "*StackPush() Test: FAILED\n"
                " -Index  (0): %f\n"
                " -Item   (1): %f\n"
                "----------------------------\n"
                , test.currentItemIndex, test.stackItems[test.currentItemIndex]);
    }
#endif // Test StackPush()

#if TEST_ON
    struct Stack test2;
    StackInit(&test2);

    ++counterTests;

    while (STACK_SIZE - 1 > test2.currentItemIndex) {
        StackPush(&test2, i++);
    }

    if ((StackIsFull(&test2) == true)) {
        ++counterPassed;
        printf("----------------------------\n"
                "*StackIsFull() Test: PASSED\n"
                " -Item  (19): %f\n"
                " -Index (19): %d\n"
                "----------------------------\n"
                , test2.stackItems[test2.currentItemIndex], test2.currentItemIndex);
    } else {
        printf("----------------------------\n"
                "*StackIsFull() Test: FAILED\n"
                " -Item  (19): %f\n"
                " -Index (19): %d\n"
                "----------------------------\n"
                , test2.stackItems[test2.currentItemIndex], test2.currentItemIndex);
    }
#endif // Test StackIsFull()

#if TEST_ON
    ++counterTests;


    if (StackPop(&test2, &value) == SUCCESS) {
        ++counterPassed;
        printf("----------------------------\n"
                "*StackPop() Test: PASSED\n"
                " -Index  (18): %d\n"
                " -Item   (19): %f\n"
                "----------------------------\n"
                , test2.currentItemIndex, value);
    } else {
        printf("----------------------------\n"
                "*StackPop() Test: FAILED\n"
                " -Index  (18): %d\n"
                " -Item   (19): %f\n"
                "----------------------------\n"
                , test2.currentItemIndex, value);
    }
#endif // Test StackPop()

#if TEST_ON
    ++counterTests;


    if ((StackGetSize(&test) == 2) && (StackGetSize(&test2) == 19)) {
        ++counterPassed;
        printf("----------------------------\n"
                "*StackGetSize() Test: PASSED\n"
                " -Test    (2):%d\n"
                " -Test2   (19) :%d\n"
                "----------------------------\n"
                , StackGetSize(&test), StackGetSize(&test2));
    } else {
        printf("----------------------------\n"
                "*StackGetSize() Test: FAILED\n"
                " -Test    (2): %d\n"
                " -Test2   (19): %d\n"
                "----------------------------\n"
                , StackGetSize(&test), StackGetSize(&test2));
    }
#endif // Test StackGetSize()

    printf("\n%d out of %d Tests Passed!!\n", counterTests, counterPassed);
#endif// Test of Functions

    // Declare Variables
    char *tokens = NULL;
    float *operand_1c = NULL, *operand_2c = NULL;
    double tokenToEval = 0, result = 0;
    char stringInput[MAX_CHAR + 1];


    // Declare and Initialize myStack
    struct Stack myStack;
    StackInit(&myStack);

    while (1) {
        // Print Greeting and Get string
        printf("Welcome to Juan's RPN Calculator!!\n");
        printf("Enter Doubles and + - / * in RPN Format:\n");

        //Obtain the String
        fgets(stringInput, sizeof (stringInput), stdin);

        // Split The String Into Tokens
        tokens = strtok(stringInput, " \n");

        // Transform to double
        tokenToEval = atof(tokens);

        if (tokenToEval != 0) {

            // Check if an Error Ocurred
            if (StackPush(&myStack, tokenToEval) == STANDARD_ERROR) {
                printf("ERROR: No more room on stack.\n");
            }

        } else if (*tokens == '+' || *tokens == '*' || *tokens == '/' || *tokens == '-') {
            printf("ERROR: Invalid RPN calculation: more or less than one item in the stack.?.\n");

        } else {
            printf("ERROR: Invalid character in RPN string.\n");
        }
        while (tokens != NULL) {

            tokens = strtok(NULL, " ");
            tokenToEval = atof(tokens);

            if (tokenToEval != 0) {
                //Check for Errors
                if (StackPush(&myStack, tokenToEval) == STANDARD_ERROR) {
                    printf("ERROR: No more room on stack.\n");
                }

            } else if (*tokens == '+') { // Addition
                // Pop First Operand
                if (StackPop(&myStack, operand_1c) == STANDARD_ERROR) {
                    printf("ERROR: Not enough operands before operator.\n");
                }

                // Pop Second Operand
                if (StackPop(&myStack, operand_2c) == STANDARD_ERROR) {
                    printf("ERROR: Not enough operands before operator.\n");
                }

                // Perform Operation
                result = (*operand_1c) + (*operand_2c);

                // Print Out the Result
                printf("result: %f\n", result);

                // Push Result onto the Stack
                if (StackPush(&myStack, result) == STANDARD_ERROR) {
                    printf("ERROR: No more room on stack.\n");
                }

            } else if (*tokens == '*') { // Multiplication

                //Pop First Operand
                if (StackPop(&myStack, operand_1c) == STANDARD_ERROR) {
                    printf("ERROR: Not enough operands before operator.\n");
                }

                // Pop Second Operand
                if (StackPop(&myStack, operand_2c) == STANDARD_ERROR) {
                    printf("ERROR: Not enough operands before operator.\n");
                }

                // Perform Multiplication
                result = (*operand_1c) * (*operand_2c);

                // Print Result
                printf("result: %f\n", result);

                // Push the result onto the stack
                if (StackPush(&myStack, result) == STANDARD_ERROR) {
                    printf("ERROR: No more room on stack.\n");
                }

            } else if (*tokens == '-') {// Substraction

                // Pop first Operand
                if (StackPop(&myStack, operand_1c) == STANDARD_ERROR) {
                    printf("ERROR: Not enough operands before operator.\n");
                }

                // Pop second Operand
                if (StackPop(&myStack, operand_2c) == STANDARD_ERROR) {
                    printf("ERROR: Not enough operands before operator.\n");
                }

                //Perfrom the substraction
                result = (*operand_1c) - (*operand_2c);

                // Print out result
                printf("result: %f\n", result);

                // Push result into the stack
                if (StackPush(&myStack, result) == STANDARD_ERROR) {
                    printf("ERROR: No more room on stack.\n");
                }
            } else if (*tokens == '/') {// Division

                // Pop first operand
                if (StackPop(&myStack, operand_1c) == STANDARD_ERROR) {
                    printf("ERROR: Not enough operands before operator.\n");
                }

                // Pop second operand
                if (StackPop(&myStack, operand_2c) == STANDARD_ERROR) {
                    printf("ERROR: Not enough operands before operator.\n");
                }

                // Perfrom division
                result = (*operand_1c) / (*operand_2c);

                // Print result
                printf("result: %f\n", result);

                // Push result to the stack
                if (StackPush(&myStack, result) == STANDARD_ERROR) {
                    printf("ERROR: No more room on stack.\n");
                }
            } else {
                printf("ERROR: Invalid character in RPN string.\n");
            }
        }// End of while loop.    
    }//End of infinite loop

    /*************************************************************************************************/

    // You can never return from main() in an embedded system (one that lacks an operating system).
    // This will result in the processor restarting, which is almost certainly not what you want!
    while (1);
}

/**
 * Extra Credit: Define ProcessBackspaces() here - This function should read through an array of
 * characters and when a backspace character is read it should replace the preceding character with
 * the following character. It should be able to handle multiple repeated backspaces and also
 * strings with more backspaces than characters. It should be able to handle strings that are at
 * least 256 characters in length.
 * @param rpn_sentence The string that will be processed for backspaces. This string is modified in
 *                     place.
 * @return Returns the size of the resultant string in `rpn_sentence`.
 */
int ProcessBackspaces(char *rpn_sentence)
{
    return 0;
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
            ++i;
        }
        return i;
    }
    return 0;
}

