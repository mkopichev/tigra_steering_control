#include "../inc/control.h"

uint16_t setpoint = MIN_SETPOINT + ((MAX_SETPOINT - MIN_SETPOINT) / 2);

void controlLoopTimerInit(void) {
    TCCR0B = (1 << CS00) | (1 << CS02);
    TIMSK0 = (1 << TOIE0);
    TCNT0 = 255 - 7;
}

ISR(TIMER0_OVF_vect) { // 1kHz
    TCNT0 = 255 - 7;
    PORTB ^= (1 << 5);
    uint16_t angle = adcGetPos();
    if((angle > MAX_SETPOINT) || (angle < MIN_SETPOINT) || (abs(setpoint - angle) < 25)) {
        motorStop();
        return;
    }
    if(angle < setpoint)
        motorGo(0);
    else
        motorGo(1);
}