#include "inc/utils.h"

extern uint16_t setpoint;

void initAll(void);

int main(void) {
    initAll();
    while(1) {
        int16_t angle_received = uartReceiveData(); // 200...800
        uartSendDec((int16_t)setpoint);
        uartTransmitByte('\t');
        if(angle_received < MIN_SETPOINT)
            angle_received = MIN_SETPOINT;
        else if(angle_received > MAX_SETPOINT)
            angle_received = MAX_SETPOINT;
        else
            setpoint = angle_received;
        uartSendDec((int16_t)adcGetPos());
        uartSendStr("\r\n");
        _delay_ms(100);
    }
}

void initAll(void) {
    adcInit();
    uartInit();
    driverInit();
    driverOn();
    controlLoopTimerInit();
    DDRB |= (1 << 5);
    sei();
}