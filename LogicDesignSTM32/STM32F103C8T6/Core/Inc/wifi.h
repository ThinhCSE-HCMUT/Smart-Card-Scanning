/*
 * wifi.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */

#ifndef INC_WIFI_H_
#define INC_WIFI_H_

#include "global.h"

extern UART_HandleTypeDef huart1;

uint32_t uint8ArrayToInt(uint8_t* array, size_t length);
//uint32_t checkForID();

int isCardFromESP32();
#endif /* INC_WIFI_H_ */
