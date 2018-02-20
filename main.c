/*
* GccApplication1.c
*
* Created: 2/17/2018 11:11:01 AM
* Author : tlfal_000
*/

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "LCD_Controller.c"
#include "DHT.c"
#include "mpu9250.c"

#define LED PA0
#define BUZZER PA1

#define output_low(port, pin) port &= ~(1<<pin)
#define output_high(port, pin) port |= (1<<pin)
#define set_output(portdir, pin) portdir |= (1<<pin)
#define set_input(portdir, pin) portdir &= ~(1<<pin)



int main(void)
{
	float gyroBias[3]  = {0, 0, 0},
	accelBias[3] = {0, 0, 0},
	magBias[3]   = {0, 0, 0},
	magScale[3]  = {0, 0, 0};
	
	
	LCD_Init();
	LCD_Clear();
	LCD_String("Booting...");
	
	set_output(DDRA, BUZZER);
	set_output(DDRA, LED);
	DHT_setup();
	i2c_init();
	mpu_calibrate(gyroBias,accelBias);
	mpu_init();
	
	
	
	double temp[1], hum[1];
	char first_line[16];
	char second_line[16];
	uint8_t data;

	temp[0] = hum[0] = 0;
	uint8_t address = 0x00;
	
	_delay_ms(1000);
	while (1)
	{
		data = mpu_read_byte(AK8963_ADDRESS, WHO_AM_I_AK8963);
		
		sprintf(first_line, "0x%02X :: 0x%02X", AK8963_ADDRESS, WHO_AM_I_AK8963);
		sprintf(second_line, "0x%02X", data);
		
		output_high(PORTA, LED);
		output_low(PORTA, BUZZER);
		DHT_read(temp, hum);
		
		/*switch (DHT_STATUS)
		{
		case (DHT_OK):
		sprintf(first_line, "Hum: %f", hum[0]);
		sprintf(second_line, "Tmp: %f", temp[0]);
		break;
		case (DHT_ERROR_CHECKSUM):
		sprintf(first_line, "Error!");
		sprintf(second_line, "Checksum!");
		break;
		case (DHT_ERROR_TIMEOUT):
		sprintf(first_line, "Error!");
		sprintf(second_line, "Timeout!");
		break;
		case (DHT_ERROR_HUMIDITY):
		sprintf(first_line, "Error!");
		sprintf(second_line, "Humidity!");
		break;
		case (DHT_ERROR_TEMPERATURE):
		sprintf(first_line, "Error!");
		sprintf(second_line, "Temperature!");
		break;
		}*/
		
		LCD_Clear();
		LCD_String(first_line);
		LCD_Command(0xC0); //Second Line
		LCD_String(second_line);
		
		
		/*_delay_ms(1000);
		output_high(PORTA, BUZZER);
		output_low(PORTA, LED);*/
		if (data == 0xFF || data == 0x00){
			_delay_ms(100);
		}else{
			_delay_ms(1000);
		}
		address ++;

	}
}



