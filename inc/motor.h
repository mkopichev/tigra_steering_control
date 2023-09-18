#ifndef MOTOR_H_
#define MOTOR_H_

#include "utils.h"
#include <stdbool.h>

#define DDR_POWER_SUPPLY DDRD
#define PORT_POWER_SUPPLY PORTD

#define DDR_CONTROL DDRB
#define PORT_CONTROL PORTB

#define DDR_VCC   6
#define DDR_GND   7
#define DDR_R_EN  3
#define DDR_L_EN  0
#define DDR_R_PWM 1
#define DDR_L_PWM 2

#define PORT_VCC   6
#define PORT_GND   7
#define PORT_R_EN  3
#define PORT_L_EN  0
#define PORT_R_PWM 1
#define PORT_L_PWM 2

#define MOTOR_SPEED 64

void driverInit(void);
void driverOn(void);
void driverOff(void);
void motorStop(void);
void motorGo(bool direction);

#endif