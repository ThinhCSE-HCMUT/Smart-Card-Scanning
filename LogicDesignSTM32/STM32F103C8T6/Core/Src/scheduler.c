/*
 * scheduler.c
 *
 *  Created on: Nov 14, 2024
 *      Author: Admin
 */

#include "scheduler.h"

LinkedList SCH_LL = {
		.head = NULL
};

void SCH_Init(void)
{
	while(SCH_LL.head != NULL)
	{
		SCH_Delete_Task();
	}
}


void SCH_Update()
{
	if(SCH_LL.head == NULL) return;
	if(SCH_LL.head->Delay > 0)
	{
		SCH_LL.head->Delay--;
	}
}
void SCH_Delete_Task(void) //Delete head node
{
	if(SCH_LL.head == NULL) return;
	TaskNode* deleteNode = SCH_LL.head;
	SCH_LL.head = SCH_LL.head->next;

	free(deleteNode);
}

void SCH_Add_Task(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD)
{
	TaskNode* newTask = (TaskNode*) malloc (sizeof(TaskNode));

	newTask->pTask = pFunction;
	newTask->Delay = DELAY;
	newTask->Period = PERIOD;
	newTask->next = NULL;

	if(SCH_LL.head == NULL || SCH_LL.head->Delay > DELAY)
	{
		if(SCH_LL.head != NULL)
		{
			SCH_LL.head->Delay -= DELAY;
		}
		newTask->next = SCH_LL.head;
		SCH_LL.head = newTask;
	}
	else
	{
		TaskNode* current = SCH_LL.head;
		DELAY -= current->Delay;
		while(current->next != NULL && current->next->Delay <= DELAY)
		{
			DELAY -= current->next->Delay;
			current = current->next;
		}
		newTask->next = current->next;
		if(current->next != NULL)
		{
			current->next->Delay -= DELAY;
		}
		current->next = newTask;
		newTask->Delay = DELAY;
	}
}

void SCH_Dispatch_Tasks(void)
{
	if(SCH_LL.head == NULL) return;
	TaskNode* current = SCH_LL.head;
	while(current != NULL)
	{
		if(current->Delay == 0)
		{
			(*current->pTask)();
			if(current->Period > 0)
			{
				current->Delay = current->Period;
				SCH_Delete_Task();
				SCH_Add_Task(current->pTask, current->Delay, current->Period);
			}
			else //One-shot task
			{
				SCH_Delete_Task();
			}
		}
		current = current->next;
	}
}

