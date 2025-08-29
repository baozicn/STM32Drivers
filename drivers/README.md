#Drivers

This directory contains reusable peripheral drivers for STM32 microcontrollers. Each module provides an easy-to-use API for initializing and interacting with a hardware peripheral while abstracting away the underlying register and HAL call. 
Available drivers include:

- `led`: simple wrapper to control on-board LEDs (initialize, turn on/off, toggle).
- `button`: wrapper for push-buttons, with initialization and debounce-aware state reading functions.
- `uart`: wrapper for serial communication; supports initialization, transmit and receive functions built on top of HAL_UART.
- `i2c`: provides basic functions to read and write registers and buffers over I²C using HAL.
- `spi`: convenience functions for SPI transfers.

Each driver is implemented as a pair of `.h` and `.c` files. You can include only the drivers you need in your application. See the examples in the `examples/` directory for usage.
