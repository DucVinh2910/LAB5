/*
 * software_timer.h
 *
 *  Created on: Dec 19, 2023
 *      Author: DucVinh
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

// timer for 3s waiting in uart communication
extern int timer_counter;
extern int timer_flag;

// timer for blinking led
extern int timer_blinking;
extern int timer_blinking_flag;

void setTimer(int duraion);
void setTimerBlinking();
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
