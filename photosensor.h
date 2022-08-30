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

unsigned int sensors[10];

void init_photo(void);

unsigned int get_photo_val(unsigned int pin);

unsigned int *get_all_photo_val(void);

unsigned int any_covered(void);
