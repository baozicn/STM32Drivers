#include "spi.h"

void Spi_Init(SpiHandle_t *hspi, SPI_HandleTypeDef *spiHandle)
{
    hspi->SpiHandle = spiHandle;
}

HAL_StatusTypeDef Spi_Transmit(SpiHandle_t *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    return HAL_SPI_Transmit(hspi->SpiHandle, pData, Size, Timeout);
}

HAL_StatusTypeDef Spi_Receive(SpiHandle_t *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    return HAL_SPI_Receive(hspi->SpiHandle, pData, Size, Timeout);
}

HAL_StatusTypeDef Spi_TransmitReceive(SpiHandle_t *hspi, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size, uint32_t Timeout)
{
    return HAL_SPI_TransmitReceive(hspi->SpiHandle, pTxData, pRxData, Size, Timeout);
}
