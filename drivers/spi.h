#ifndef SPI_HELPER_H
#define SPI_HELPER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include <stdint.h>

// SPI handle wrapper structure
typedef struct {
    SPI_HandleTypeDef *SpiHandle;
} SpiHandle_t;

// Initialize the SPI handle wrapper
void Spi_Init(SpiHandle_t *spi, SPI_HandleTypeDef *hspi);

// Transmit data over SPI (blocking)
HAL_StatusTypeDef Spi_Transmit(SpiHandle_t *spi, uint8_t *pData, uint16_t size, uint32_t timeout);

// Receive data over SPI (blocking)
HAL_StatusTypeDef Spi_Receive(SpiHandle_t *spi, uint8_t *pData, uint16_t size, uint32_t timeout);

// Transmit and receive data over SPI (blocking)
HAL_StatusTypeDef Spi_TransmitReceive(SpiHandle_t *spi, uint8_t *txData, uint8_t *rxData, uint16_t size, uint32_t timeout);

#ifdef __cplusplus
}
#endif

#endif // SPI_HELPER_H
