/* 
 * File:   Serial.h
 * Author: Juan D. Cardozo
 * Student I.D: 1362585
 */

#ifndef SERIAL_H
#define	SERIAL_H

// User Created Libraries
#include "HardwareDefs.h"

/**
 * Initialize the UART peripheral for use by the PIC. Also sets stdin/stdout to point to the proper
 * UART and disables buffering for both.
 */
void SerialInit(void);

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* SERIAL_H */

