#include "button.h"

void Button_Init(ButtonHandle_t *button) {
    // Configure the GPIO pin for the button as input with proper pull-up/down.
    // This is typically done in CubeMX or user code outside this driver.
    (void)button;
}

bool Button_IsPressed(ButtonHandle_t *button) {
    GPIO_PinState state = HAL_GPIO_ReadPin(button->Port, button->Pin);
    return (state == button->ActiveState);
}
