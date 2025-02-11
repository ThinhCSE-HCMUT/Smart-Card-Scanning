/*
 * signal.h
 *
 *  Created on: Dec 6, 2024
 *      Author: Fung
 */

#ifndef INC_SIGNAL_H_
#define INC_SIGNAL_H_

#include "buzzer.h"
#include "lcd.h"
#include "led_rgb.h"
#include "global.h"

void signal_correct();
void signal_wrong();
void signal_reset();
void signal_waiting();
#endif /* INC_SIGNAL_H_ */
