#ifndef __PWM_H__
#define __PWM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"

/**
 * @brief PWM driver handle structure.
 */
typedef struct {
    TIM_HandleTypeDef *htim; ///< Pointer to HAL timer configured for PWM.
    uint32_t channel;        ///< Timer channel used for PWM (e.g., TIM_CHANNEL_1).
} PwmHandle_t;

/**
 * @brief Initialize PWM driver handle.
 *
 * Stores the provided timer handle and channel in the driver context. The timer should be configured
 * in PWM mode using CubeMX or HAL functions before calling this initializer.
 *
 * @param handle  Pointer to PWM driver handle to initialize.
 * @param htim    Pointer to HAL timer handle configured for PWM output.
 * @param channel Timer channel used for PWM generation (TIM_CHANNEL_1, TIM_CHANNEL_2, etc.).
 */
void Pwm_Init(PwmHandle_t *handle, TIM_HandleTypeDef *htim, uint32_t channel);

/**
 * @brief Set PWM duty cycle.
 *
 * Adjusts the compare register value to achieve the desired duty cycle percentage. The duty cycle
 * should be between 0.0f (0%) and 100.0f (100%). Values outside this range will be clamped.
 *
 * @param handle Pointer to PWM driver handle.
 * @param duty   Desired duty cycle percentage from 0.0f to 100.0f.
 */
void Pwm_SetDuty(PwmHandle_t *handle, float duty);

/**
 * @brief Start PWM signal generation.
 *
 * Calls HAL_TIM_PWM_Start() on the underlying timer and channel.
 *
 * @param handle Pointer to PWM driver handle.
 */
void Pwm_Start(PwmHandle_t *handle);

/**
 * @brief Stop PWM signal generation.
 *
 * Calls HAL_TIM_PWM_Stop() on the underlying timer and channel.
 *
 * @param handle Pointer to PWM driver handle.
 */
void Pwm_Stop(PwmHandle_t *handle);

#ifdef __cplusplus
}
#endif

#endif // __PWM_H__
