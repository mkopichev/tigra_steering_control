#ifndef UTILS_H_
#define UTILS_H_

#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>
#include <stdlib.h>
#include <util/delay.h>
#include "adc.h"
#include "control.h"
#include "motor.h"
#include "uart.h"

uint8_t digit(uint16_t d, uint8_t m);
uint16_t findMiddleValue(uint16_t a, uint16_t b, uint16_t c);
uint16_t findMaxValue(uint16_t a, uint16_t b, uint16_t c);
uint16_t findMinValue(uint16_t a, uint16_t b, uint16_t c);

#endif