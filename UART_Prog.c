#include "STD_Types.h"
#include "BIT_MATH.h"
#include "UART_Private.h"

u8 Names[10][10] = {"asmaa","ahmed","aya","heba","farid","amany","mohamed","doaa","seif","zeina"};
u8 Passwords[10][10] = {"123456","973846","108375","609752","199756","579613","234567","345678","456789","512346"};

void UART_VidInt(void){
	UCSRC = (1<<7) | (3<<1);
	UBRRL = 51;
	SET_BIT(UCSRB, TXEN);
	SET_BIT(UCSRB, RXEN);
}

void UART_VidSendData(u8 Copy_u8Data){
	while(GET_BIT(UCSRA, UDRE)!=1);
	UDR = Copy_u8Data;
}

u8 UART_u8RecieveData(void){
	while(GET_BIT(UCSRA, RXC)!=1);
	return UDR;
}

void ReceiveName(u8 *name, u8 *size){
	u8 i=0,x;
	*size=0;
	x = UART_u8RecieveData();
	while(x!=' '){
		name[i]=x;
		i++;
		*size=*size+1;
		x = UART_u8RecieveData();
	}
	name[i] = '\0';
}
void RecievePassword(u8 *pass, u8 *size){
	u8 i=0,x;
	*size=0;
	x = UART_u8RecieveData();
	while(x!=' '){
		pass[i] = x;
		i++;
		*size=*size+1;
		x = UART_u8RecieveData();
	}
	pass[i] = '\0';
}
u8 CheckName(u8 *name){
	u8 flag;
	for(u8 i=0; i<10; i++){
		flag = 0;
		for(u8 j=0; (name[j]!='\0') || (Names[i][j]!='\0'); j++){
			if(Names[i][j] != name[j]){
				flag=1;
				break;
			}
		}
		if(flag==0){
			switch(i){
				case 0:
					return '0';
				case 1:
					return '1';
				case 2:
					return '2';
				case 3:
					return '3';
				case 4:
					return '4';
				case 5:
					return '5';
				case 6:
					return '6';
				case 7:
					return '7';
				case 8:
					return '8';
				case 9:
					return '9';
			}
		}
	}
	return 'a';
}
u8 CheckPassword(u8 *pass,u8 userId){
	u8 flag = 0;
	for(u8 i=0; (pass[i]!='\0') || (Passwords[userId][i]!='\0'); i++){
		if(Passwords[userId][i]!=pass[i]){
			flag=1;
			break;
		}
	}
	if(flag==1){
		return 1;
	}

	return 0;
}

u8 UART_Vid_ToInt(u8 number){
	u32 val=0,num;
	num=number-48;
	val=val*10+num;
	return val;
}

