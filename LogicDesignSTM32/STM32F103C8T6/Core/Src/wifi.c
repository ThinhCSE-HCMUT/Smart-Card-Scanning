/*
 * wifi.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */

#include "wifi.h"

uint32_t uint8ArrayToInt(uint8_t* array, size_t length) {
    uint32_t result = 0;
    for (size_t i = 0; i < length; i++) {
        result = (result << 8) | array[i]; } return result;
}



//uint32_t checkForID(){
////	if(cardFlag)
////	{
////		uint8_t Rx_data[1];
////		memset(Rx_data, 0, 1); //clear array before receiving again
////		if (HAL_UART_Receive_IT(&huart1, Rx_data, 1) == HAL_OK) { // receiving the index
////			message = uint8ArrayToInt(Rx_data, sizeof(Rx_data)); //decode the index
////			//for debug purposes transmit back to esp32
////			//HAL_UART_Transmit(&huart1, Rx_data, strlen((char *)Rx_data), 1000);
////		}
////		if(message != 5) userID = (int) message;
////	}
////	return message;
//}

int isCardFromESP32()
{
	if(cardFlag)
	{
		cardFlag = 0;
		userID = uint8ArrayToInt(Rx_data, sizeof(Rx_data)) - 48;
//		memset(Rx_data, 0, 1);
		return 1;
	}
	return 0;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef * huart)
{
	if(huart -> Instance == USART1)
	{
		HAL_UART_Receive_IT(&huart1,Rx_data, 1);

		cardFlag = 1;
	}
}


