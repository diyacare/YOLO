#ifndef MAIN_H
#define MAIN_H

#define CORE_ZERO		0 //motor setting
#define CORE_ONE		1 //leds settings

static unsigned char yoloState;

void setNewState(unsigned char newState);
unsigned char getState();

typedef enum
{
	HOMING_SETUP,
	RFID_CHECK,
	MIXING,
	HOMING,
	AMOUNT_SETUP
}STATES ;

#endif
