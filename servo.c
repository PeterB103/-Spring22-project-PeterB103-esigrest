/*
 * Project file: Servo
 * Names: Peter and Eleanor
 * Date: 6/2/2022
 * 
 * Description: This file contains the implementation of the servo header
 * 
 */

#include "pwm.h"
#include "gpio.h"
#include "servo.h"
#include "printf.h"

#define FREQ (19200000/16) //I'm not sure what value I should set this too... look in spec?

void init_servo(void) {
    // Turn on gpio pins and set functionality
    gpio_set_function(GPIO_PIN18, GPIO_FUNC_ALT5);

    // Turn on, initalize, and configure pwm
    pwm_init();
    pwm_set_clock(FREQ);
    pwm_set_mode(0, PWM_MARKSPACE); // Is this the correct mode? Or should it be PWM_SIGMADELTA?
    pwm_set_fifo(0, 0);
    pwm_set_range(0, RANGE);
    pwm_enable(0);
}

void open(void) {
    pwm_set_width(0, MIN);
}

void close(void) {
    pwm_set_width(0, MAX);
}

void test(void){
    // Testing ranges after conversation with Benson
    // I learned that the pwm values set in width determine
    // what angle the servo turns to.
    // Benson suggested a range 4000, with width between 500 and 3100 
    pwm_set_range(0, 4000);
    pwm_set_width(0, 500);

    
    // Testing from given audio/sound code with edited/testing values
    int left_width = FREQ/LEFT_HZ; // 1.2M / 440 = 2727
    //pwm_set_range( 0, left_width ); // 2727 
    pwm_set_range(0, FREQ);
    pwm_set_width( 0, left_width/4 );  // 681
    
    
    // Testing from given audio/sound code
    int right_width = FREQ/RIGHT_HZ; // 1.2M / 523 = 2294
    pwm_set_range( 0, right_width ); 
    pwm_set_width( 0, right_width/2 );
    
}





