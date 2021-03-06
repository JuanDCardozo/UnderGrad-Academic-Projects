#include "Common.h"

#include "Stack.h"

/**
 * This function checks for whether the stack is empty or not. In this simple
 * case this merely checks if the currentItemIndex == -1. Returns true if the
 * stack is empty, false if not. Also needs to check if the stack is
 * initialized and return false if it isn't.
 */
int StackIsEmpty(const struct Stack *stack)
{
    if (stack->initialized == true) {
        if (stack->currentItemIndex == -1) {
            return true;
        }
    }
    return false;
}

/**
 * This function checks for whether the stack is empty or not. For this simple
 * implementation that is merely if the currentItemIndex == STACK_SIZE - 1.
 * Returns true if the stack is full and false if not. Also returns false if
 * the stack isn't initialized.
 */
int StackIsFull(const struct Stack *stack)
{
    if (stack->initialized == true) {
        if (stack->currentItemIndex == STACK_SIZE - 1) {
            return true;
        }
    }
    return false;
}

/**
 * This function initializes the stack. For a statically allocated stack such
 * as this, this just means initializing currentItemIndex to -1 and setting
 * initialized to true.
 */


void StackInit(struct Stack *stack)
{
    // Initialize current Item Index
    stack->currentItemIndex = -1;

    // Initiaized to true
    stack->initialized = true;
}

/**
 * This function pushes a value onto the stack. It returns SUCCESS for success
 * and STANDARD_ERROR for a failure. A failure occurs when trying to push onto full or
 * non-initialized stacks. (SUCCESS and STANDARD_ERROR are declared in the Common.h header file.
 */
int StackPush(struct Stack *stack, float value)
{
    if (stack->initialized == true) {
        if (StackIsFull(stack) == false) {
            stack->stackItems[++stack->currentItemIndex] = value;
            return SUCCESS;
        }
    }
    return STANDARD_ERROR;
}

/**
 * This function returns the top of the stack into the value point location.
 * It also returns a success code: SUCCESS for success and STANDARD_ERROR for failure.
 * Failure occurs when Pop() is called on empty stacks or non-initialized
 * stacks.
 *
 * NOTE: When trying to return the output into the value variable, you'll need
 * to write it with an extra asterisk like:
 *   *value = 7.0;
 * This is because of pointers and K&R 5.1-5.2 should explain it. This is the
 * only time in your lab where you'll need to do something like that for an
 * assignment operation.
 */
int StackPop(struct Stack *stack, float *value)
{
    if (stack->initialized == true) {
        if (StackIsEmpty(stack) == false) {
            *value = stack->stackItems[stack->currentItemIndex--];
            return SUCCESS;
        }
    }
    return STANDARD_ERROR;
}

/**
 * Returns the current size of the stack in terms of how many active elements
 * are in it. Returns an error of SIZE_ERROR for uninitialized stacks, 0 for
 * empty and initialized stacks, and the number of elements in the stack
 * otherwise. SIZE_ERROR is declared in the Common.h header file.
 */
int StackGetSize(const struct Stack *stack)
{
    // Declare tempora Variable
    int size = 0;

    //Check if it is
    if (stack->initialized == true) {
        if (StackIsEmpty(stack) == true) {
            return 0;
        } else {
            return (size += stack->currentItemIndex);
        }
    }//End of outer if
    return SIZE_ERROR;
}
