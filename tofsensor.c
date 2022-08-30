// Using this spec: file:///Users/Eleanor/Downloads/en.DM00279086.pdf

#include "tofsensor.h"
#include "printf.h"
#include "gpio.h"
#include "malloc.h"
#include "strings.h"
//#include "clock.h"
#include "timer.h"
#include "i2c.h"
#include "stdint.h"

#include "interrupts.h"

struct vl53l0x_t {
    unsigned int clock;
    unsigned int data;
    unsigned int gpio; // possibly unused
    unsigned int address;
    unsigned int code;
};

void vl53l0x_new() {
    i2c_init();
    /*struct vl53l0x_t *sensor = malloc(sizeof(*sensor));

    sensor->clock = clock_gpio;
    gpio_set_input(sensor->clock);
    gpio_set_pullup(sensor->clock);

    sensor->data = data_gpio;
    gpio_set_input(sensor->data);
    gpio_set_pullup(sensor->data); //pretty sure this should be pullup, confirmed in spec on page 8/40
    
    sensor->gpio = gpio_gpio;
    gpio_set_input(sensor->gpio);
    gpio_set_pullup(sensor->gpio); //pretty sure this should be pullup, confirmed in spec on page 8/40


    gpio_enable_event_detection(clock_gpio, 
    */
    uint8_t temp = 0x00;
    i2c_write(0x88, (char *)&temp, 1);

    temp = 0x01;
    i2c_write(0x80, 0x01, 1);
    i2c_write(0xFF, 0x01, 1);

    temp = 0x00;
    i2c_write(0x00, 0x00, 1);

    stop_variable = i2c_read(0x91);


    i2c_write(0x00, 0x01, 1);
    i2c_write(0xFF, 0x00, 1);
    i2c_write(0x80, 0x00, 1);

    i2c_write(MSRC_CONFIG_CONTROL, readReg(MSRC_CONFIG_CONTROL) | 0x12, 1);

    // set final range signal rate limit to 0.25 MCPS (million counts per second)
    setSignalRateLimit(0.25);

    i2c_write(SYSTEM_SEQUENCE_CONFIG, 0xFF, 1);
    
}


bool setSignalRateLimit(float limit_Mcps) {
  if (limit_Mcps < 0 || limit_Mcps > 511.99) { return false; }

  // Q9.7 fixed point format (9 integer bits, 7 fractional bits)
  i2c_write(FINAL_RANGE_CONFIG_MIN_COUNT_RATE_RTN_LIMIT, limit_Mcps * (1 << 7), 1); // this was origionally write 16 bit... do I need to be worried?
  return true;
}


uint16_t readRangeContinuousMillimeters() {
  while ((readReg(RESULT_INTERRUPT_STATUS) & 0x07) == 0) { /* spint */ }

  // assumptions: Linearity Corrective Gain is 1000 (default);
  // fractional ranging is not enabled
  uint16_t range = readReg16Bit(RESULT_RANGE_STATUS + 10);

  i2c_write(SYSTEM_INTERRUPT_CLEAR, 0x01, 1);

  return range;
}


uint16_t readRangeSingleMillimeters() {
  i2c_write(0x80, 0x01, 1);
  i2c_write(0xFF, 0x01, 1);
  i2c_write(0x00, 0x00, 1);
  i2c_write(0x91, stop_variable, 1);
  i2c_write(0x00, 0x01, 1);
  i2c_write(0xFF, 0x00, 1);
  i2c_write(0x80, 0x00, 1);

  i2c_write(SYSRANGE_START, 0x01, 1);

  // "Wait until start bit has been cleared"
  startTimeout();
  while (i2c_read(SYSRANGE_START) & 0x01) { /* spin */ }

  return readRangeContinuousMillimeters();
}


