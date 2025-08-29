#ifndef UART_H
#define UART_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include <stdint.h>

// UART handle structure
typedef struct {
    UART_HandleTypeDef *UartHandle;
} UartHandle_t;

// Initialize the UART handle wrapper
void Uart_Init(UartHandle_t *uart, UART_HandleTypeDef *huart);

// Send data over UART (blocking)
HAL_StatusTypeDef Uart_Send(UartHandle_t *uart, uint8_t *pData, uint16_t size);

// Receive data over UART (blocking)
HAL_StatusTypeDef Uart_Receive(UartHandle_t *uart, uint8_t *pData, uint16_t size, uint32_t timeout);

// Send a null-terminated string over UART (blocking)
HAL_StatusTypeDef Uart_SendString(UartHandle_t *uart, const char *str);

#ifdef __cplusplus
}
#endif

#endif // UART_H
