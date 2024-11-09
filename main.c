/*
 * main.c
 *
 *  Created on: Dec 17, 2022
 *      Author: Doaa Rageh
 */

#include "STD_TYPES.h"
#include "DIO_int.h"
#include "UART_Int.h"
#include "util/delay.h"

int main(){
	DIO_VidSetPinDirection(Port_D,Pin0,Input);
	DIO_VidSetPinDirection(Port_D,Pin1,Output);
	DIO_VidSetPinDirection(Port_B,Pin0,Output);
	DIO_VidSetPinDirection(Port_C,Pin4,Output);
	DIO_VidSetPinDirection(Port_D,Pin7,Output);
	DIO_VidSetPortDirection(Port_A,Output);
	UART_VidInt();

	u8 *name, *pass, checkName, checkPass, nSize, pSize, mode;

	while(1){
		UART_VidSendData('n');
		UART_VidSendData('a');
		ReceiveName(name,&nSize);
		checkName = CheckName(name);
		UART_VidSendData(checkName);

		/*if the name exists*/
		if(checkName!='a'){
			RecievePassword(pass,&pSize);
			checkName=UART_Vid_ToInt(checkName);

			for(u8 i=0;i<3;i++){
				checkPass = CheckPassword(pass,checkName);

				/*if the password is correct*/
				if(checkPass==0){
					UART_VidSendData('0');
					/*Open the lock*/
					DIO_VidSetPinValue(Port_C,Pin4,PinHigh);
					_delay_ms(3000);
					/*Close the lock*/
					DIO_VidSetPinValue(Port_C,Pin4,PinLow);

					while(1){
						mode = UART_u8RecieveData();
						/*LED off*/
						if(mode=='0'){
							DIO_VidSetPortValue(Port_A,0b00000000);
						}
						/*LED on*/
						else if(mode=='1'){
							DIO_VidSetPortValue(Port_A,0b11111111);
						}
						/*FAN Off*/
						else if(mode=='2'){
							DIO_VidSetPinValue(Port_D,Pin7,PinLow);
						}
						/*FAN on*/
						else if(mode=='3'){
							DIO_VidSetPinValue(Port_D,Pin7,PinHigh);
						}
						else if(mode=='4'){
							break;
						}
					}
					break;
				}

				/*if the user enters the password incorrectly and it is less than 3 times*/
				if(i<2){
					UART_VidSendData('1');
					RecievePassword(pass,&pSize);
				}
				/*if the user enters the password 3 times wrong, the buzzer will on*/
				else if(i==2){
					UART_VidSendData('2');
					/*Buzzer on*/
					DIO_VidSetPinValue(Port_B,Pin0,PinHigh);
					_delay_ms(3000);
					/*Buzzer off*/
					DIO_VidSetPinValue(Port_B,Pin0,PinLow);
				}
			}
		}
	}
}
