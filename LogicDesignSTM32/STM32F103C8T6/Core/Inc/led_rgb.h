/*
 * led_rgb.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */

#ifndef INC_LED_RGB_H_
#define INC_LED_RGB_H_

#include "global.h"

extern TIM_HandleTypeDef htim1;

#define BLINK_DUR 500

typedef enum {
    LED_STATE_DENY,
    LED_STATE_ACCEPT,
    LED_STATE_WAITING,
    LED_STATE_OFF
} LedState;

void ledRgb_init();
void rgb_color(uint8_t red, uint8_t green, uint8_t blue);

void SetLedState(LedState state);
void blinkClolor(LedState state);

#endif /* INC_LED_RGB_H_ */
