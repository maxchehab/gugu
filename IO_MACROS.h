#ifndef IO_MACROS_H_INCLUDED
#define IO_MACROS_H_INCLUDED
/*
||
||  Filename:	 		IO_MACROS.h
||  Title: 			    IO manipulation macros
||  Author: 			Efthymios Koktsidis
||	Email:				efthymios.ks@gmail.com
||  Compiler:		 	AVR-GCC
||	Description:		This library contains macros for 
||						easy port manipulation (similar 
||						to Arduino).
||
||	Demo:
|| 1.	#define LED		A, 0		|| 6. 	pinModeToggle(BUTTON);
|| 2.	#define BUTTON	A, 1		|| 7. 	digitalWrite(LED, LOW);
|| 3.								|| 8. 	digitalWrite(LED, HIGH);
|| 4. 	pinMode(BUTTON, OUTPUT);	|| 9. 	digitalLevelToggle(LED);
|| 5. 	pinMode(LED, OUTPUT);		||10.	int a = digitalRead(BUTTON);
||
*/

//----- I/O Macros -----
//Macros to edit PORT, DDR and PIN
#define pinMode(			x, y)	( 		y 			?	_SET(DDR, x)	:	_CLEAR(DDR, x)		)
#define digitalWrite(		x, y)	( 		y 			?	_SET(PORT, x)	:	_CLEAR(PORT, x)		)
#define digitalRead(		x)		(						_GET(PIN, x)							)
#define pinModeToggle(		x)		(						_TOGGLE(DDR, x)							)
#define digitalLevelToggle(	x)		(						_TOGGLE(PORT, x)						)

//General use bit manipulating commands
#define bitSet(		x, y)			(	x |=	 (1UL<<y)			)
#define bitClear(	x, y)			(	x &=	(~(1UL<<y))			)
#define bitToggle(	x, y)			(	x ^=	 (1UL<<y)			)
#define bitCheck(	x, y)			(	x &		 (1UL<<y)	? 1 : 0	)

//Access PORT, DDR and PIN
#define PORT(	port)				(_PORT(	port))
#define DDR(	port)				(_DDR(	port))
#define PIN(	port)				(_PIN(	port))

#define _PORT(	port)				(PORT##	port)
#define _DDR(	port)				(DDR##	port)
#define _PIN(	port)				(PIN##	port)

#define _SET(	type, port, bit)	(	bitSet(		(type##port),	bit)	)
#define _CLEAR(	type, port, bit)	(	bitClear(	(type##port),	bit)	)
#define _TOGGLE(type, port, bit)	(	bitToggle(	(type##port),	bit)	)
#define _GET(	type, port, bit)	(	bitCheck(	(type##port),	bit)	)

//Definitions
#define INPUT		0
#define OUTPUT		!INPUT
#define LOW			0
#define HIGH		!LOW
#define FALSE		0
#define TRUE		!FALSE
//------------------
#endif
