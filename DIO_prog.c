/*****************************************************************/
/************** SWC : DIO Driver *********************************/
/**************  By : DoaaRageh   ********************************/
/**************  Date : 27Aug20   ********************************/
/**************  Version : v1.0   ********************************/
/*****************************************************************/

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "DIO_private.h"

/*setting pin direction*/

void DIO_VidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction){
	if(Copy_u8Direction == Input){
		switch(Copy_u8Port){
			case Port_A: CLEAR_BIT(DDRA, Copy_u8Pin);  break;
			case Port_B: CLEAR_BIT(DDRB, Copy_u8Pin);  break;
			case Port_C: CLEAR_BIT(DDRC, Copy_u8Pin);  break;
			case Port_D: CLEAR_BIT(DDRD, Copy_u8Pin);  break;
		}
	}
	else if(Copy_u8Direction == Output){
		switch(Copy_u8Port){
			case Port_A: SET_BIT(DDRA, Copy_u8Pin);  break;
			case Port_B: SET_BIT(DDRB, Copy_u8Pin);  break;
			case Port_C: SET_BIT(DDRC, Copy_u8Pin);  break;
			case Port_D: SET_BIT(DDRD, Copy_u8Pin);  break;
		}
	}
}

/*setting pin value*/

void DIO_VidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value){
	if(Copy_u8Value == PinLow){
		switch(Copy_u8Port){
			case Port_A: CLEAR_BIT(PORTA, Copy_u8Pin);  break;
			case Port_B: CLEAR_BIT(PORTB, Copy_u8Pin);  break;
			case Port_C: CLEAR_BIT(PORTC, Copy_u8Pin);  break;
			case Port_D: CLEAR_BIT(PORTD, Copy_u8Pin);  break;
		}
	}
	else if(Copy_u8Value == PinHigh){
		switch(Copy_u8Port){
			case Port_A: SET_BIT(PORTA, Copy_u8Pin);  break;
			case Port_B: SET_BIT(PORTB, Copy_u8Pin);  break;
			case Port_C: SET_BIT(PORTC, Copy_u8Pin);  break;
			case Port_D: SET_BIT(PORTD, Copy_u8Pin);  break;
		}
	}
}

/*getting pin value*/

void DIO_VidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *pu8Data){
	switch (Copy_u8Port){
		case Port_A: *pu8Data=GET_BIT(PINA, Copy_u8Pin);  break;
		case Port_B: *pu8Data=GET_BIT(PINB, Copy_u8Pin);  break;
		case Port_C: *pu8Data=GET_BIT(PINC, Copy_u8Pin);  break;
		case Port_D: *pu8Data=GET_BIT(PIND, Copy_u8Pin);  break;
	}
}


/*setting port direction*/

void DIO_VidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction){
	u8 i;
	if(Copy_u8Direction == Input){
			switch(Copy_u8Port){
				case Port_A: for(i=0; i<8;i++) CLEAR_BIT(DDRA, i);  break;
				case Port_B: for(i=0; i<8;i++) CLEAR_BIT(DDRB, i);  break;
				case Port_C: for(i=0; i<8;i++) CLEAR_BIT(DDRC, i);  break;
				case Port_D: for(i=0; i<8;i++) CLEAR_BIT(DDRD, i);	break;
			}
		}
		else if(Copy_u8Direction == Output){
			switch(Copy_u8Port){
				case Port_A: for(i=0; i<8;i++) SET_BIT(DDRA, i);  break;
				case Port_B: for(i=0; i<8;i++) SET_BIT(DDRB, i);  break;
				case Port_C: for(i=0; i<8;i++) SET_BIT(DDRC, i);  break;
				case Port_D: for(i=0; i<8;i++) SET_BIT(DDRD, i);  break;
			}
		}
}

/*setting port(Port register) value*/

void DIO_VidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value){
	switch(Copy_u8Port){
		case Port_A: PORTA = Copy_u8Value;  break;
		case Port_B: PORTB = Copy_u8Value;  break;
		case Port_C: PORTC = Copy_u8Value;  break;
		case Port_D: PORTD = Copy_u8Value;  break;
	}
}

/*getting port(PIN register) value*/

void DIO_VidGetPortValue(u8 Copy_u8Port, u8 *pu8Data){
	u8 i;
	switch (Copy_u8Port){
		case Port_A: for(i=0; i<8;i++) pu8Data[i]=GET_BIT(PINA, i);  break;
		case Port_B: for(i=0; i<8;i++) pu8Data[i]=GET_BIT(PINB, i);  break;
		case Port_C: for(i=0; i<8;i++) pu8Data[i]=GET_BIT(PINC, i);  break;
		case Port_D: for(i=0; i<8;i++) pu8Data[i]=GET_BIT(PIND, i);  break;
	}
}




