// Colaborated with Victoria Lyn and Andrea David
// Standard Libraries
#include <xc.h>
#include <stdint.h>

//User libraries
#include "Buttons.h"
#include "HardwareDefs.h"

// Global Variables
static int bEventBitfield = BUTTON_EVENT_NONE;
static int debounceCounter = 0;

/**
 * This function initializes the proper pins such that the buttons 1-4 may be used by modifying
 * the necessary bits in TRISD/TRISF. Only the bits necessary to enable the 1-4 buttons are
 * modified so that this library does not interfere with other libraries.
 */
void ButtonsInit(void)
{
    BTN1 = 1;
    BTN2 = 1;
    BTN3 = 1;
    BTN4 = 1;
}

/**
 * This function checks the button states and returns any events that have occured since the last
 * call. In the case of the first call to ButtonsCheckEvents() after ButtonsInit(), the function
 * should assume that the buttons start in an off state with value 0. Therefore if no buttons are
 * pressed when ButtonsCheckEvents() is first called, BUTTONS_EVENT_NONE should be returned. The
 * events are listed in the ButtonEventFlags enum at the top of this file. This function should be
 * called repeatedly.
 *
 * This function also performs debouncing of the buttons. Every time ButtonsCheckEvents() is called,
 * all button values are saved, up to the 4th sample in the past, so 4 past samples and the present
 * values. A button event is triggered if the newest 4 samples are the same and different from the
 * oldest sample. For example, if button 1 was originally down, button 1 must appear to be up for 4
 * samples before a BUTTON_EVENT_1UP is triggered. This eliminates button bounce, where the button
 * may quickly oscillate between the ON and OFF state as it's being pressed or released.
 *
 * NOTE: This will not work properly without ButtonsInit() being called beforehand.
 * @return A bitwise-ORing of the constants in the ButtonEventFlags enum or BUTTON_EVENT_NONE if no
 *         event has occurred.
 */
uint8_t ButtonsCheckEvents(void)
{
    // Declare Variables
    uint8_t bEventCurent = BUTTON_STATES();
    bEventBitfield = BUTTON_EVENT_NONE;

    // Check for each button event and set a bitflag

    //Button 1
    if (bEventCurent & 0x01) {
        bEventBitfield |= BUTTON_EVENT_1DOWN;
    } else {
        bEventBitfield |= BUTTON_EVENT_1UP;
    }

    //Button 2
    if (bEventCurent & 0x02) {
        bEventBitfield |= BUTTON_EVENT_2DOWN;
    } else {
        bEventBitfield |= BUTTON_EVENT_2UP;
    }

    //Button 3
    if (bEventCurent & 0x04) {
        bEventBitfield |= BUTTON_EVENT_3DOWN;
    } else {
        bEventBitfield |= BUTTON_EVENT_3UP;
    }

    //Button 4
    if (bEventCurent & 0x08) {
        bEventBitfield |= BUTTON_EVENT_4DOWN;
    } else {
        bEventBitfield |= BUTTON_EVENT_4UP;
    }

    //Debouncing Period
    if (debounceCounter > 4) {
        debounceCounter = 0;
        return bEventBitfield;
    } else {
        ++debounceCounter;
        return BUTTON_EVENT_NONE;
    }
}

