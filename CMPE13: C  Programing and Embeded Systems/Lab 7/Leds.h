#ifndef LEDS_H
#define	LEDS_H

//Standard Libraries
#include <xc.h>

// Initializes TRISE and LATE
#define LEDS_INIT() do{\
    TRISE = 0;\
    LATE = 0;\
}while(0)

// Turn on the Leds  with a 1 bit on them
#define LEDS_SET(x) LATE = x

//Returns the value of LATE
#define LEDS_GET() PORTE


#endif	/* LEDS_H */

