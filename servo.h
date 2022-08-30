/*
 * Project file: Servo
 * Names: Peter and Eleanor
 * Date: 6/2/2022
 * 
 * Description: This file contains the headers and constants for opening and closing the servo
 * 
 */

// Used values
#define FREQ (19200000/16)
#define MIN 500
#define MAX 3100
#define RANGE 4000

// Testing values
#define TEST 4095
#define LEFT_HZ 440
#define RIGHT_HZ 220

/* Initalize the servo */
void init_servo(void);

/* This function turns the servo to its maximum
 * bound (aka opens the valve)
 */
void open(void);

/* This function turns the servo to its minimum
 * bound (aka closes the valve)
 */
void close(void);

/* This function was for testing values and ranges
 * to determine what values will turn the servo all 
 * the way open, and all the way closed. This will
 * open and close the water valve.
 * */
void test(void);


