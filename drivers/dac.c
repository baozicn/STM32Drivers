#include "dac.h"

/**
 * @brief Initialize the DAC driver handle.
 *
 * Stores the provided HAL DAC handle into the driver context.
 * The HAL handle must be configured using CubeMX or HAL before calling this initializer.
 *
 * @param handle Pointer to driver handle to initialize.
 * @param hdac   Pointer to HAL DAC handle configured by user.
 */
void Dac_Init(DacHandle_t *handle, DAC_HandleTypeDef *hdac)
{
    if (handle)
    {
        handle->hdac = hdac;
    }
}

/**
 * @brief Write a value to a DAC channel.
 *
 * Starts the DAC channel if necessary, writes a 12-bit value, and returns HAL status.
 *
 * @param handle  Pointer to DAC driver handle.
 * @param channel DAC channel (DAC_CHANNEL_1 or DAC_CHANNEL_2).
 * @param value   12-bit value to output.
 * @return HAL_StatusTypeDef Status code returned by HAL functions.
 */
HAL_StatusTypeDef Dac_Write(DacHandle_t *handle, uint32_t channel, uint32_t value)
{
    if (handle == NULL || handle->hdac == NULL)
    {
        return HAL_ERROR;
    }
    if (HAL_DAC_Start(handle->hdac, channel) != HAL_OK)
    {
        return HAL_ERROR;
    }
    if (HAL_DAC_SetValue(handle->hdac, channel, DAC_ALIGN_12B_R, value) != HAL_OK)
    {
        return HAL_ERROR;
    }
    return HAL_OK;
}
