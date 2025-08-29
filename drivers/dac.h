#ifndef __DAC_H__
#define __DAC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"

/**
 * @brief DAC driver handle structure.
 */
typedef struct {
    DAC_HandleTypeDef *hdac; ///< Pointer to HAL DAC handle configured by the user.
} DacHandle_t;

/**
 * @brief Initialize DAC driver handle.
 *
 * Stores the provided HAL DAC handle into the driver context. The HAL handle must be configured
 * using CubeMX or HAL functions before calling this initializer.
 *
 * @param handle Pointer to driver handle to initialize.
 * @param hdac   Pointer to HAL DAC handle configured by user.
 */
void Dac_Init(DacHandle_t *handle, DAC_HandleTypeDef *hdac);

/**
 * @brief Write a value to a DAC channel.
 *
 * Sets the DAC output value for the specified channel and triggers the conversion.
 *
 * @param handle  Pointer to DAC driver handle.
 * @param channel DAC channel (e.g., DAC_CHANNEL_1 or DAC_CHANNEL_2).
 * @param value   12-bit value to output.
 * @return HAL_StatusTypeDef HAL status code from underlying HAL functions.
 */
HAL_StatusTypeDef Dac_Write(DacHandle_t *handle, uint32_t channel, uint32_t value);

#ifdef __cplusplus
}
#endif

#endif // __DAC_H__
