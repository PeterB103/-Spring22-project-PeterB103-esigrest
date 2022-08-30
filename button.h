#include "gpio.h"
#include "gpio_interrupts.h"
#include "interrupts.h"
#include "printf.h"
#include "ringbuffer.h"
#include "servo.h"

static const int BUTTON = GPIO_PIN6;

void handle_click(unsigned int pc, void *aux_data);

void init_button(void);


