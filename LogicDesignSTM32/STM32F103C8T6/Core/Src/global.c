/*
 * global.c
 *
 *  Created on: Dec 7, 2024
 *      Author: Admin
 */

#include "global.h"

char* memberName[MAX_MEMBER_DATABASE] = {"Thinh", "Thuan", "Trung"};
int userID = UNKNOWN;
int status = INIT;
int timerReset;

uint32_t message = 5;
int cardFlag = 0;
uint8_t Rx_data[1];
