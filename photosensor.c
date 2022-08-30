/*
 * Project File: Photosensor and Lasers
 * Names: Peter and Eleanor
 * Date: 6/2/2022
 * Description: This file contains the implementation of the photosensor library
 *
 */

#include "uart.h"
#include "gpio.h"
#include "timer.h"
#include "printf.h"
#include "malloc.h"
#include "photosensor.h"

/* Create an array containing the GPIO pin per sensor */
unsigned int sensors[10] = {GPIO_PIN23, GPIO_PIN24, GPIO_PIN25, GPIO_PIN8, GPIO_PIN7, GPIO_PIN12, GPIO_PIN16,GPIO_PIN20, GPIO_PIN21, GPIO_PIN26};

/* The initalization sets all of the GPIO pins to be input */
void init_photo(void) {
    printf("in the init\n");
    for(int i = 0; i < 10; i++){
        printf("initalizing sensor %d\n", i);
        gpio_set_input(sensors[i]);
    }
}

/* The get_photo_val function returns the value of a given 
 * photo sensor. The photo sensors are labeled 0 through 9
 */
unsigned int get_photo_val(unsigned int pin) {
    return gpio_read(sensors[pin]);
}

/* The get_all_photo_val function returns all the values of
 * the photosensors in an array.
 */
unsigned int *get_all_photo_val(void) {
    unsigned int *values = malloc(10);

    for(int i = 0; i < 10; i++){
        values[i] = gpio_read(sensors[i]);
    }

    return values;
}

/* The any_covered function returns 1 (true) if any of 
 * the photosensors are covered and returns 0 (false)
 * if none of the photosensors are covered
 */
unsigned int any_covered(void) {
    for(int i = 0; i < 10; i++){
        // Sensor is 0 if covered (aka unlight), 1 if being 
        // hit by the laser (aka light)
        if(gpio_read(sensors[i]) == 0){
            return 1;
        }
    }
    return 0;
}
