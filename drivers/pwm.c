#include "pwm.h"

/**
 * @brief Initialize PWM driver handle.
 *
 * Stores the provided timer handle and channel into the driver context.
 *
 * @param handle Pointer to PWM driver handle to initialize.
 * @param htim Pointer to HAL timer handle configured for PWM.
 * @param channel Timer channel used for PWM (e.g., TIM_CHANNEL_1).
 */
void Pwm_Init(PwmHandle_t *handle, TIM_HandleTypeDef *htim, uint32_t channel)
{
    if (handle)
    {
        handle->htim = htim;
        handle->channel = channel;
    }
}

/**
 * @brief Set PWM duty cycle.
 *
 * Updates the pulse width register to achieve the desired duty cycle percentage.
 * The duty cycle value should be between 0.0f (0%) and 1.0f (100%).
 * If outside this range, it will be clamped.
 *
 * @param handle Pointer to PWM driver handle.
 * @param duty   Desired duty cycle as a float from 0.0f to 1.0f.
 */
void Pwm_SetDutyCycle(PwmHandle_t *handle, float duty)
{
    if (handle == NULL || handle->htim == NULL)
    {
        return;
    }

    if (duty < 0.0f)
    {
        duty = 0.0f;
    }
    else if (duty > 1.0f)
    {
        duty = 1.0f;
    }

    /* Get the timer period. Use the Auto-Reload Register (ARR) + 1 to get the period. */
    uint32_t period = __HAL_TIM_GET_AUTORELOAD(handle->htim) + 1;

    /* Compute the pulse length corresponding to the duty cycle. */
    uint32_t pulse = (uint32_t)((float)period * duty);

    /* Set the Capture Compare Register value to adjust the duty cycle. */
    __HAL_TIM_SET_COMPARE(handle->htim, handle->channel, pulse);
}
