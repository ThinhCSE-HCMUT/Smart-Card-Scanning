/*
 * buzzer.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */
#include "buzzer.h"


void right_buzzer(){
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	__HAL_TIM_SET_PRESCALER(&htim3,3);
}
void wrong_buzzer(){
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	__HAL_TIM_SET_PRESCALER(&htim3,240);
}
