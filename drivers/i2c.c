#include "i2c.h"

void I2c_Init(I2cHandle_t *i2c, I2C_HandleTypeDef *hi2c) {
    i2c->I2cHandle = hi2c;
}

HAL_StatusTypeDef I2c_Read(I2cHandle_t *i2c, uint16_t devAddr, uint16_t memAddr, uint16_t memAddrSize,
                           uint8_t *pData, uint16_t size, uint32_t timeout) {
    return HAL_I2C_Mem_Read(i2c->I2cHandle, devAddr, memAddr, memAddrSize, pData, size, timeout);
}

HAL_StatusTypeDef I2c_Write(I2cHandle_t *i2c, uint16_t devAddr, uint16_t memAddr, uint16_t memAddrSize,
                            uint8_t *pData, uint16_t size, uint32_t timeout) {
    return HAL_I2C_Mem_Write(i2c->I2cHandle, devAddr, memAddr, memAddrSize, pData, size, timeout);
}
