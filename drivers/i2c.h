#ifndef I2C_HELPER_H
#define I2C_HELPER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include <stdint.h>

// I2C handle wrapper structure
typedef struct {
    I2C_HandleTypeDef *I2cHandle;
} I2cHandle_t;

// Initialize the I2C handle wrapper
void I2c_Init(I2cHandle_t *i2c, I2C_HandleTypeDef *hi2c);

// Read from an I2C device memory address (blocking)
HAL_StatusTypeDef I2c_Read(I2cHandle_t *i2c, uint16_t devAddr, uint16_t memAddr, uint16_t memAddrSize,
                           uint8_t *pData, uint16_t size, uint32_t timeout);

// Write to an I2C device memory address (blocking)
HAL_StatusTypeDef I2c_Write(I2cHandle_t *i2c, uint16_t devAddr, uint16_t memAddr, uint16_t memAddrSize,
                            uint8_t *pData, uint16_t size, uint32_t timeout);

#ifdef __cplusplus
}
#endif

#endif // I2C_HELPER_H
