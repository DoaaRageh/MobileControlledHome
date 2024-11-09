#ifndef UART_INT_H
#define UART_INT_H

void UART_VidInt(void);

void UART_VidSendData(u8 Copy_u8Data);

u8 UART_u8RecieveData(void);

void ReceiveName(u8 *name, u8 *size);

void RecievePassword(u8 *pass, u8 *size);

u8 CheckName(u8 *name);

u8 CheckPassword(u8 *pass,u8 userId);

u8 UART_Vid_ToInt(u8 number);

#endif
