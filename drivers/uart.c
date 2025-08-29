#include "uart.h"
#include <string.h>

void Uart_Init(UartHandle_t *uart, UART_HandleTypeDef *huart) {
    uart->UartHandle = huart;
}

HAL_StatusTypeDef Uart_Send(UartHandle_t *uart, uint8_t *pData, uint16_t size) {
    return HAL_UART_Transmit(uart->UartHandle, pData, size, HAL_MAX_DELAY);
}

HAL_StatusTypeDef Uart_Receive(UartHandle_t *uart, uint8_t *pData, uint16_t size, uint32_t timeout) {
    return HAL_UART_Receive(uart->UartHandle, pData, size, timeout);
}

HAL_StatusTypeDef Uart_SendString(UartHandle_t *uart, const char *str) {
    return HAL_UART_Transmit(uart->UartHandle, (uint8_t *)str, (uint16_t)strlen(str), HAL_MAX_DELAY);
}
