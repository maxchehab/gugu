#ifndef DHT_CONFIG_H_
#define DHT_CONFIG_H_
/*
||
||  Filename:	 		DHT_CONFIG.h
||  Title: 			    DHTxx Driver Settings
||  Author: 			Efthymios Koktsidis
||	Email:				efthymios.ks@gmail.com
||  Compiler:		 	AVR-GCC
||	Description:
||	Settings for the DHTxx driver. Pick a model 
||	and the desirable pin.
||
*/

//----- Configuration --------------------------//
#define DHT_TYPE	DHT11         //DHT11 or DHT22
#define DHT_PIN		D, 7
//----------------------------------------------//
#endif