#include "gpio.h"

// -- Hardware-specific setup --

#ifdef RED_V_BOARD
    #define GPIO_BASE                0x10012000UL
    #define GPIO_INPUT_VAL_OFFSET    0x00
    #define GPIO_INPUT_EN_OFFSET     0x04
    #define GPIO_OUTPUT_EN_OFFSET    0x08
    #define GPIO_OUTPUT_VAL_OFFSET   0x0C
#elif defined(ESP32_C3_BOARD)
    #define GPIO_BASE                0x10012000UL
    #define GPIO_INPUT_VAL_OFFSET    0x00
    #define GPIO_INPUT_EN_OFFSET     0x04
    #define GPIO_OUTPUT_EN_OFFSET    0x08
    #define GPIO_OUTPUT_VAL_OFFSET   0x0C
#else
    #error "Please define board: RED_V_BOARD or ESP32_C3_BOARD"
#endif

// Helper macros
#define GPIO_REG(offset) (*(volatile uint32_t *)(GPIO_BASE + (offset)))


void gpio_enable_output(uint32_t pin) {
    GPIO_REG(GPIO_OUTPUT_EN_OFFSET) |= (1 << pin);
}

void gpio_disable_output(uint32_t pin) {
    GPIO_REG(GPIO_OUTPUT_EN_OFFSET) &= ~(1 << pin);
}

void gpio_enable_input(uint32_t pin) {
    GPIO_REG(GPIO_INPUT_EN_OFFSET) |= (1 << pin);
}

void gpio_disable_input(uint32_t pin) {
    GPIO_REG(GPIO_INPUT_EN_OFFSET) &= ~(1 << pin);
}

void gpio_write(uint32_t pin, uint8_t value) {
    if (value) {
        GPIO_REG(GPIO_OUTPUT_VAL_OFFSET) |= (1 << pin);
    } else {
        GPIO_REG(GPIO_OUTPUT_VAL_OFFSET) &= ~(1 << pin);
    }
}

uint8_t gpio_read(uint32_t pin) {
    return (GPIO_REG(GPIO_INPUT_VAL_OFFSET) >> pin) & 0x1;
}

void gpio_toggle(uint32_t pin) {
    GPIO_REG(GPIO_OUTPUT_VAL_OFFSET) ^= (1 << pin);
}
