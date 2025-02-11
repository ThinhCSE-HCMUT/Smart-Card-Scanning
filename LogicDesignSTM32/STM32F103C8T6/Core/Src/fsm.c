/*
 * fsm.c
 *
 *  Created on: Dec 7, 2024
 *      Author: Admin
 */

#include "fsm.h"

void fsm_run()
{
	switch(status)
	{
	case INIT:
		lcd_init();
		ledRgb_init();
		signal_reset();
		timerReset = 50;
		status = WAITING_CARD;
		cardFlag = 0;
		userID = UNKNOWN;
		break;
	case WAITING_CARD:
	    signal_waiting();
	    // Check if card received
	    if(isCardFromESP32()) {
	        status = PROCESSING_CARD;
	    }
	    break;

	case PROCESSING_CARD:
		if(userID == UNKNOWN)
		{
			status = SIGNAL_UNKNOWN;
			signal_reset();
		}
		else
		{
			status = SIGNAL_MEMBER;
			signal_reset();
		}
		break;
	case SIGNAL_MEMBER:
		signal_correct();
		//Timer
		if(timerReset > 0)
		{
			timerReset--;
			if(timerReset <= 0)
			{
				status = INIT;
			}
		}
		break;
	case SIGNAL_UNKNOWN:
		signal_wrong();
		//Timer
		if(timerReset > 0)
		{
			timerReset--;
			if(timerReset <= 0)
			{
				status = INIT;
			}
		}
		break;
	default:
		break;
	}
}
