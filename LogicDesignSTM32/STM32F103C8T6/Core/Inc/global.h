/*
 * global.h
 *
 *  Created on: Dec 7, 2024
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "signal.h"
#include "wifi.h"
#include "scheduler.h"
#include "fsm.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define DISABLE				0
#define INIT 				1
#define WAITING_CARD		2
#define PROCESSING_CARD		3
#define SIGNAL_MEMBER		4
#define SIGNAL_UNKNOWN		5

#define MAX_MEMBER_DATABASE	3
#define UNKNOWN 			4

extern char* memberName[MAX_MEMBER_DATABASE];
extern int status;
extern int userID;
extern int timerReset;
extern uint32_t message;
extern int cardFlag;
extern uint8_t Rx_data[1];
#endif /* INC_GLOBAL_H_ */
