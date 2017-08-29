/*
 * File:   Serial.h
 * Author: JuanD
 * Created on January 9, 2015, 10:21 PM
 */

#ifndef OLED_H
#define	OLED_H

// Include standard C libraries.
#include <stddef.h>
#include <stdbool.h>

// Include User Created Libraries
#include "OledDriver.h"
#include "Ascii.h"

/**
 * Initializes the OLED, turns it on, and clears the screen.
 */
void OledInit(void);

/**
 * Sets a specific pixel in the frame buffer, available colors are black or white.
 * @note OledUpdate() must be called before the OLED will actually display these changes.
 * @param x The X position (left is zero)
 * @param y The Y position (top is zero)
 * @param color OLED_COLOR_WHITE or OLED_COLOR_BLACK
 */
void OledSetPixel(int x, int y, int color);

/**
 * Reads a pixel from the frame buffer.
 * @param x The X position (left is zero)
 * @param y The Y position (top is zero)
 * @return OLED_COLOR_WHITE or OLED_COLOR_BLACK
 */
int OledGetPixel(int x, int y);

/**
 * Draws the specified character at the specified position, using Ascii.h as the font.
 * @param x The x-position to use as the left-most value for the character.
 * @param y The y-position to use as the top-most value for the character
 * @param c The character to write. Uses the character array defined in Ascii.h
 * @return True if the write succeeded. Fails on invalid inputs.
 */
bool OledDrawChar(int x, int y, char c);

/**
 * Draws a string to the screen buffer, starting on the top line. 21 characters fit on the 4 lines
 * on the screen.
 * @note OledUpdate() must be called before the OLED will actually display these changes.
 * @param string A null-terminated string to print.
 */
void OledDrawString(const char *string);

/**
 * Writes the specified color pixels to the entire frame buffer.
 * @note OledUpdate() must be called before the OLED will actually display these changes.
 * @param p The color to write all pixels in the OLED to.
 */
void OledClear(int p);

/**
 * Redraws the OLED display based on the contents of `rgb0ledBmp`. Use after `rgb0ledBmp` is
 * modified.
 */
void OledUpdate(void);

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* OLED_H */

