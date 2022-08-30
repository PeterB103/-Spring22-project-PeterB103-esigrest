/*
 * Project: Pi Water
 * Names: Peter and Eleanor
 * Date: 6/2/2022
 * 
 * Description: Full implementation of automatic water bottle filler
 * 
 */


#include "uart.h"
//#include "mymodule.h"
#include "tof.h"
#include "i2c.h"
#include "strings.h"
#include "printf.h"
#include "photosensor.h"
#include "servo.h"
#include "gpio.h"
#include "timer.h"
#include "button.h"
#include "gpio_interrupts.h"
#include "interrupts.h"
#include "gpio_extra.h"

void main(void) {
    // Initilization
    
    //uart_init();
    gpio_init();
    
    // Turn on interrupts for manual override of filler
    interrupts_init();
    gpio_interrupts_init();
    
    init_button();

    gpio_interrupts_enable();
    gpio_enable_event_detection(BUTTON, GPIO_DETECT_FALLING_EDGE);
    const char *aux_data = "Clicked!";
    interrupts_register_handler(INTERRUPTS_GPIO3, handle_click, (void *)aux_data);

    // Finish init
    tofInit(0, 0x29, 0);
    init_photo();
    init_servo();

    // Turn on final interrupts
    interrupts_global_enable();

    int waterBottleHeight = 0;

    while(1) { 

        // Wait until a water bottle is put into the stand
        int baseBeforeBottle = tofReadDistance();
        printf("baseBeforeBottle = %d\n", baseBeforeBottle);
        while(!any_covered()) { 
            //printf("Waiting for water bottle!\n");
            timer_delay_ms(50);
        }
        timer_delay(4); // used to be 2

        // Calculate height by looping from top-most sensor till the first covered sensor
        for(int i = 9; i >= 0; i--) {
            // Where 0 is covered, and 1 is uncovered
            if(get_photo_val(i) == 0) {
                printf("Photoresistor covered = %d\n", i);
                waterBottleHeight = 30*(i+1); // Where height is is mm
                break;
            }
        }
        printf("Water bottle height = %d\n", waterBottleHeight);

        // Calculate the fill height and get current height
        int fillHeight = waterBottleHeight - 60; // Where height is in mmhttps://www.youtube.com/watch?v=C_mxfW7Ybb0
        printf("Fill height = %d\n", fillHeight);

        timer_delay(2); // used to be 5
        int curFill = tofReadDistance();
        int base = curFill+5;
        //int prevFill = curFill;
        printf("Baseline current fill = %d\n", base);
        
        // Open valve
        printf("Open valve!!");
        open();
        
        // Fill water bottle
        //while((prevFill-curFill) < fillHeight) {
        while((base - curFill) < fillHeight) {
            //prevFill = curFill;
            curFill = tofReadDistance();
            printf("Base before bottle = %d\nCurrent fill = %d\nbase = %d\ndifference = %d\ngoal height = %d\n\n",baseBeforeBottle, curFill, base, base-curFill, fillHeight);
            timer_delay_ms(50);
        }

        // Close valve
        printf("Close valve!!! \n");
        close();

        while(any_covered()) { 
            printf("Remove the bottle pls\n");
            timer_delay_ms(50);
        }
    }
    
    //uart_putchar(EOT);
}


