/*
 * fsm.c
 *
 *  Created on: Dec 19, 2023
 *      Author: DucVinh
 */


#include "main.h"
#include "software_timer.h"
#include "fsm.h"
#include "command.h"
#include "controlData.h"
#include "uart.h"

int communiation_mode = 0;

void uart_communication_fsm(){
	switch (communiation_mode) {
		case 0:
			// waiting for flag
			// flag can catch in waiting mode
			if (timer_flag == 1){
				setTimer(0);
				command_mode = 2;
				// Transfer Data
				transfer(ADC_Value_buffer);
				command_mode = 0;
				setTimer(0);
			}
			break;
		case 1:
			// get data from ADC
			getNewValue();
			// Transfer Data
			transfer(ADC_Value);
			// set status environment
			ADC_Value_buffer = ADC_Value;
			communiation_mode = 0;
			command_mode = 0;
			setTimer(0);
			break;
		default:
			break;
	}
}
