/*****************************************************************/
/************** SWC : DIO Driver *********************************/
/**************  By : DoaaRageh   ********************************/
/**************  Date : 27Aug20   ********************************/
/**************  Version : v1.0   ********************************/
/*****************************************************************/

#ifndef DIO_INT_H
#define DIO_INT_H

typedef enum{
	Port_A,
	Port_B,
	Port_C,
	Port_D
}et_Port;

typedef enum{
	Pin0,
	Pin1,
	Pin2,
	Pin3,
	Pin4,
	Pin5,
	Pin6,
	Pin7
}et_Pin;

typedef enum{
	Input,
	Output
}et_Direction;

typedef enum{
	PinLow,
	PinHigh
}et_Status;

/*setting pin direction*/

void DIO_VidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);

/*setting pin value*/

void DIO_VidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

/*getting pin value*/

void DIO_VidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *pu8Data);



/*setting port direction*/

void DIO_VidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);

/*setting port(Port register) value*/

void DIO_VidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

/*getting port(PIN register) value*/

void DIO_VidGetPortValue(u8 Copy_u8Port, u8 *pu8Data);


#endif
