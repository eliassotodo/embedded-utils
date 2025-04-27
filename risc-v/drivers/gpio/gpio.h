#pragma once

#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

// Functions
void gpio_enable_output(uint32_t pin);
void gpio_disable_output(uint32_t pin);
void gpio_enable_input(uint32_t pin);
void gpio_disable_input(uint32_t pin);
void gpio_write(uint32_t pin, uint8_t value);
void gpio_toggle(uint32_t pin);
uint8_t gpio_read(uint32_t pin);

#endif // GPIO_H
