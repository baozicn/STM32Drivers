#include "adc.h"

/**
 * @brief Initialize the ADC driver handle.
 *
 * Stores the provided HAL ADC handle inside the driver context. The HAL handle must already be configured using
 * CubeMX or HAL functions before calling this initializer.
 *
 * @param handle Pointer to ADC driver handle to initialize.
 * @param hadc   Pointer to HAL ADC handle configured by user.
 */
void Adc_Init(AdcHandle_t *handle, ADC_HandleTypeDef *hadc)
{
    if (handle)
    {
        handle->hadc = hadc;
    }
}

/**
 * @brief Read an ADC value from a given channel.
 *
 * This function configures the specified channel on the underlying HAL handle, starts a conversion, waits for
 * completion, reads the value and stops the conversion. Error conditions return zero.
 *
 * @param handle  Pointer to ADC driver handle.
 * @param channel ADC channel identifier (e.g., ADC_CHANNEL_0, ADC_CHANNEL_1).
 * @return uint32_t Raw ADC conversion value, or 0 if an error occurred.
 */
uint32_t Adc_Read(AdcHandle_t *handle, uint32_t channel)
{
    if (handle == NULL || handle->hadc == NULL)
    {
        return 0;
    }
    ADC_ChannelConfTypeDef sConfig = {0};
    sConfig.Channel = channel;
    sConfig.Rank = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;

    if (HAL_ADC_ConfigChannel(handle->hadc, &sConfig) != HAL_OK)
    {
        return 0;
    }
    if (HAL_ADC_Start(handle->hadc) != HAL_OK)
    {
        return 0;
    }
    if (HAL_ADC_PollForConversion(handle->hadc, 10) != HAL_OK)
    {
        HAL_ADC_Stop(handle->hadc);
        return 0;
    }
    uint32_t value = HAL_ADC_GetValue(handle->hadc);
    HAL_ADC_Stop(handle->hadc);
    return value;
}
