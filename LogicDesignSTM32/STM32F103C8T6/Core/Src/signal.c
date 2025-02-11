/*
 * signal.c
 *
 *  Created on: Dec 6, 2024
 *      Author: Fung
 */

#include "signal.h"


void signal_correct(){

	/*Unknown User or Validate UserID*/
	if(userID >= MAX_MEMBER_DATABASE || userID < 0)
	{
		signal_wrong();
		return;
	}

	lcd_goto_XY(0, 0);
	lcd_send_string("Welcome");
	if(strlen(memberName[userID]) <= 8)
	{
		lcd_goto_XY(0, 8);
	}
	//Auto line break if username is too long
	else
	{
		lcd_goto_XY(1, 0);
	}
	lcd_send_string(memberName[userID]);
	right_buzzer();
	//TODO for LED RGB
	SetLedState(LED_STATE_ACCEPT);
}
void signal_wrong(){
//	lcd_clear_display();
	lcd_goto_XY(0, 0);
	lcd_send_string("Unknown User");
	wrong_buzzer();
	//TODO
	SetLedState(LED_STATE_DENY);
}
void signal_reset(){
	lcd_clear_display();
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
	SetLedState(LED_STATE_OFF);
}

void signal_waiting()
{
	lcd_goto_XY(0, 0);
	lcd_send_string("Please put");
	lcd_goto_XY(1, 0);
	lcd_send_string("your card here->");
	//red rgb: Turn on yellow
	//TODO
	SetLedState(LED_STATE_WAITING);
}
