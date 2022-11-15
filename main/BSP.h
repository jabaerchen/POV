#pragma once

#include "driver/gpio.h"

#define GPIO_AND0 GPIO_NUM_12
#define GPIO_AND1 GPIO_NUM_13
#define GPIO_AND2 GPIO_NUM_14
#define GPIO_AND3 GPIO_NUM_15
#define GPIO_CLK GPIO_NUM_16

#define GPIO_MOTOR_SENS GPIO_NUM_5
#define GPIO_MOTOR_PWM GPIO_NUM_4

/**
 * D0 | D1 | OUT |     
 * ---|----|-----------
 *  0 | 0  |  Y0 |  G
 *  1 | 0  |  Y1 |  B
 *  0 | 1  |  Y2 |  R
 *  1 | 1  |  Y3 | RCLK
*/
#define GPIO_DECODER_0 GPIO_NUM_2
#define GPIO_DECODER_1 GPIO_NUM_0

