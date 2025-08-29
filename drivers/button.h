#ifndef BUTTON_H
#define BUTTON_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include <stdbool.h>

typedef struct {
    GPIO_TypeDef *Port;
    uint16_t Pin;
    GPIO_PinState ActiveState;
} ButtonHandle_t;

void Button_Init(ButtonHandle_t *button);
bool Button_IsPressed(ButtonHandle_t *button);

#ifdef __cplusplus
}
#endif

#endif // BUTTON_H
