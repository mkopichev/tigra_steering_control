#include "../inc/motor.h"

void driverInit(void) {

    DDR_POWER_SUPPLY |= (1 << DDR_VCC) | (1 << DDR_GND);
    DDR_CONTROL |= (1 << DDR_L_EN) | (1 << DDR_R_EN) | (1 << DDR_L_PWM) | (1 << DDR_R_PWM);
    TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM10);
    TCCR1B = (1 << CS11); // fast PWM ~8kHz
}

void driverOn(void) {

    PORT_POWER_SUPPLY |= (1 << PORT_VCC);
    PORT_POWER_SUPPLY &= ~(1 << PORT_GND);
}

void driverOff(void) {

    DDR_POWER_SUPPLY &= ~((1 << DDR_VCC) | (1 << DDR_GND));
}

void motorStop(void) {
    PORT_CONTROL &= ~(1 << DDR_L_EN);
    OCR1A = 0;
    PORT_CONTROL &= ~(1 << DDR_R_EN);
    OCR1A = 0;
}

void motorGo(bool direction) {

    if(direction) {
        PORT_CONTROL |= (1 << PORT_L_EN);
        OCR1A = MOTOR_SPEED;
        PORT_CONTROL |= (1 << PORT_R_EN);
        OCR1B = 0;
    } else {
        PORT_CONTROL |= (1 << PORT_L_EN);
        OCR1A = 0;
        PORT_CONTROL |= (1 << PORT_R_EN);
        OCR1B = MOTOR_SPEED;
    }
}