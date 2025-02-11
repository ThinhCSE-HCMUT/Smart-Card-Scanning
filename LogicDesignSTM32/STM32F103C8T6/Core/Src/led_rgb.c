/*
 * led_rgb.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */

#include "led_rgb.h"

void ledRgb_init(){
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
}

void rgb_color(uint8_t red, uint8_t green, uint8_t blue){
    // Scale the intensity values (0 to 255) to the PWM period
    uint16_t pwm_period = __HAL_TIM_GET_AUTORELOAD(&htim1);
    // Set the duty cycle for each color channel
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, (red * pwm_period) / 255);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, (green * pwm_period) / 255);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, (blue * pwm_period) / 255);
}


void SetLedState(LedState state) {
    uint8_t red = 0, green = 0, blue = 0;
    switch (state) {
    case LED_STATE_ACCEPT:
        red = 255;
        green = 0;
        blue = 0;
        break;
    case LED_STATE_DENY:
        red = 0;
        green = 255;
        blue = 0;
        break;
    case LED_STATE_WAITING:
        red = 255;
        green = 255;
        blue = 0;
        break;
    case LED_STATE_OFF:
            red = 0;
            green = 0;
            blue = 0;
            break;
    default:
        red = 0;
        green = 0;
        blue = 0;
        break;
    }
    // Scale the intensity values (0 to 255) to the PWM period
    uint16_t pwm_period = __HAL_TIM_GET_AUTORELOAD(&htim1);
    // Set the duty cycle for each color channel
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, (red * pwm_period) / 255);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, (green * pwm_period) / 255);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, (blue * pwm_period) / 255);
}
void blinkClolor(LedState state){
	SetLedState(state);
	HAL_Delay(BLINK_DUR);
	SetLedState(LED_STATE_OFF);
}
