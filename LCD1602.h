#ifndef __LCD1602_H__
#define __LCD1602_H__

#include "main.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"

#define		D0				D0_Pin
#define		D1				D1_Pin
#define		D2				D2_Pin
#define		D3				D3_Pin
#define		D4				D4_Pin
#define		D5				D5_Pin
#define		D6				D6_Pin
#define		D7				D7_Pin
#define		RS				RS_Pin
#define		RW				RW_Pin
#define		E					E_Pin

#define		RS_HIGH		HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_SET)
#define		RS_LOW		HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_RESET)
#define		RW_HIGH		HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, GPIO_PIN_SET)
#define		RW_LOW		HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, GPIO_PIN_RESET)
#define		E_HIGH		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET)
#define		E_LOW			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET)

void Delay_us(uint32_t us);
void WriteD0_7(uint8_t data);
void LCD1602_WriteCmd(uint8_t cmd);
void LCD1602_ShowChar(int line, int column, char ch);
void LCD1602_ShowString(int line, int column, char* str);
void LCD1602_Init(void);
void LCD1602_CursorOn(bool sel);


#endif
