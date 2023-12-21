/*
 * uart.c
 *
 *  Created on: Dec 19, 2023
 *      Author: DucVinh
 */

#include "main.h"
#include "controlData.h"
// variable for send data activity
char startData[] = "!ADC";
char endData[] = "#";
// variable for new line transmit uart activity
uint8_t nl = 0x0D;
// buffer to get ADC value
char str[20];
void getNewValue(){
	HAL_ADC_Start(&hadc1);
	ADC_Value = HAL_ADC_GetValue(&hadc1);
}
void transfer(uint32_t value){
	HAL_UART_Transmit(&huart2, startData, 4, 1000);
	HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "%d\n", value), 1000);
	HAL_UART_Transmit(&huart2, endData, 1, 1000);
	HAL_UART_Transmit(&huart2, &nl, 1, 100);
	HAL_UART_Transmit(&huart2, &nl, 1, 100);
}
void INIT(){
	HAL_ADC_Start(&hadc1);
	ADC_Value = HAL_ADC_GetValue(&hadc1);
	ADC_Value_buffer = ADC_Value;
}
