#ifndef LED_H
#define LED_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"

// LED handle structure defines the GPIO port and pin
typedef struct {
    GPIO_TypeDef *Port;
    uint16_t Pin;
} LedHandle_t;

void Led_Init(LedHandle_t *handle);
void Led_On(LedHandle_t *handle);
void Led_Off(LedHandle_t *handle);
void Led_Toggle(LedHandle_t *handle);

#ifdef __cplusplus
}
#endif

#endif /* LED_H */
