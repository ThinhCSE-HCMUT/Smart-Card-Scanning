/*
 * scheduler.h
 *
 *  Created on: Dec 7, 2024
 *      Author: Admin
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "global.h"

typedef struct TaskNode
{
	void (*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	struct TaskNode* next;
} TaskNode;

typedef struct
{
	TaskNode* head;
} LinkedList;

void SCH_Init(void);

void SCH_Update(void);

void SCH_Dispatch_Tasks(void);

void SCH_Delete_Task(void);

void SCH_Add_Task(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD);

#endif /* INC_SCHEDULER_H_ */
