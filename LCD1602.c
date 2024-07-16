#include "LCD1602.h"

void LCD1602_Init(){	
	HAL_Delay(15);
	LCD1602_WriteCmd(0x38);
	HAL_Delay(5);
	LCD1602_WriteCmd(0x38);
	HAL_Delay(5);
	LCD1602_WriteCmd(0x38);
	while(HAL_GPIO_ReadPin(D7_GPIO_Port, D7_Pin) != 0);
	LCD1602_WriteCmd(0x38);
	while(HAL_GPIO_ReadPin(D7_GPIO_Port, D7_Pin) != 0);
	LCD1602_WriteCmd(0x08);
	while(HAL_GPIO_ReadPin(D7_GPIO_Port, D7_Pin) != 0);
	LCD1602_WriteCmd(0x01);
	while(HAL_GPIO_ReadPin(D7_GPIO_Port, D7_Pin) != 0);
	LCD1602_WriteCmd(0x06);
	while(HAL_GPIO_ReadPin(D7_GPIO_Port, D7_Pin) != 0);
	LCD1602_WriteCmd(0x0C);
}


void LCD1602_ShowChar(int line, int column, char ch){
	LCD1602_WriteCmd(column + 0x40*line + 0x80);
	RS_HIGH;
	RW_LOW;
	E_LOW;
	WriteD0_7(ch);
	Delay_us(1);
	E_HIGH;
	Delay_us(1);
	E_LOW;
	Delay_us(1);
}


void LCD1602_ShowString(int line, int column, char* str){
	LCD1602_WriteCmd(column + 0x40*line + 0x80);
	int len = strlen(str);
	while(len>0){
		RS_HIGH;
		RW_LOW;
		E_LOW;
		WriteD0_7(*str);
		Delay_us(1);
		E_HIGH;
		Delay_us(1);
		E_LOW;
		Delay_us(1);
		str++;
		len--;
	}
}


void LCD1602_CursorOn(bool sel){
	if(sel == 1){
		LCD1602_WriteCmd(0x0E);
	}else{
		LCD1602_WriteCmd(0x0C);
	}
}


void LCD1602_WriteCmd(uint8_t cmd){
	RS_LOW;
	RW_LOW;
	E_LOW;
	WriteD0_7(cmd);
	Delay_us(1);
	E_HIGH;
	Delay_us(1);
	E_LOW;
	Delay_us(1);
}


void WriteD0_7(uint8_t data){
	HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, (GPIO_PinState)((data & 0x01)!=0));
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, (GPIO_PinState)((data & 0x02)!=0));
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, (GPIO_PinState)((data & 0x04)!=0));
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, (GPIO_PinState)((data & 0x08)!=0));
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, (GPIO_PinState)((data & 0x10)!=0));
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, (GPIO_PinState)((data & 0x20)!=0));
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, (GPIO_PinState)((data & 0x40)!=0));
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, (GPIO_PinState)((data & 0x80)!=0));
	
	//printf("%d",HAL_GPIO_ReadPin(D7_GPIO_Port, D7_Pin));
	//printf("%d",HAL_GPIO_ReadPin(D6_GPIO_Port, D6_Pin));
	//printf("%d",HAL_GPIO_ReadPin(D5_GPIO_Port, D5_Pin));
	//printf("%d",HAL_GPIO_ReadPin(D4_GPIO_Port, D4_Pin));
	//printf("%d",HAL_GPIO_ReadPin(D3_GPIO_Port, D3_Pin));
	//printf("%d",HAL_GPIO_ReadPin(D2_GPIO_Port, D2_Pin));
	//printf("%d",HAL_GPIO_ReadPin(D1_GPIO_Port, D1_Pin));
	//printf("%d",HAL_GPIO_ReadPin(D0_GPIO_Port, D0_Pin));
	//printf("\n");
}


void Delay_us(uint32_t us){
	uint32_t delay = HAL_RCC_GetHCLKFreq()/8000000*us;
	while(delay--);
}
