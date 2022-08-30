#include "gpio.h"
#include "gpio_interrupts.h"
#include "interrupts.h"
#include "printf.h"
#include "ringbuffer.h"
#include "servo.h"
#include "button.h"
#include "gpio_extra.h"
#include "timer.h"

void handle_click(unsigned int pc, void *aux_data) {
    char *aux_data_print = (char *)aux_data;
    printf("%s\n", aux_data_print);
    if(gpio_check_and_clear_event(BUTTON)){
        open();
        while(gpio_read(BUTTON) == 0) {
            timer_delay_ms(50);
            printf("open!\n");
        }
        close();
        printf("close!\n");
    }
}

void init_button(void) {
    // set pullups
    gpio_set_input(BUTTON); // configure button
    gpio_set_pullup(BUTTON);
}
