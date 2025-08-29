#ifndef __ADC_H__
#define __ADC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"

/**
 * @brief ADC driver handle structure.
 */
typedef struct {
    ADC_HandleTypeDef *hadc;   ///< Pointer to HAL ADC handle configured by the user.
} AdcHandle_t;

/**
 * @brief Initialize ADC driver handle.
 *
 * The user must create and configure an ADC_HandleTypeDef with CubeMX or HAL before calling this function.
 * This function simply stores the provided HAL handle in the driver context.
 *
 * @param handle Pointer to ADC driver handle to initialize.
 * @param hadc   Pointer to HAL ADC handle configured by user.
 */
void Adc_Init(AdcHandle_t *handle, ADC_HandleTypeDef *hadc);

/**
 * @brief Read a value from a specific ADC channel.
 *
 * This function configures the channel, starts a conversion, polls for conversion completion, and returns the result.
 *
 * @param handle Pointer to ADC driver handle.
 * @param channel ADC channel number (e.g., ADC_CHANNEL_0).
 * @return uint32_t Raw ADC conversion value.
 */
uint32_t Adc_Read(AdcHandle_t *handle, uint32_t channel);

#ifdef __cplusplus
}
#endif

#endif // __ADC_H__
