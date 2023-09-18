#include "../inc/adc.h"

float adc_res_filtered = 0;

void adcInit(void) {

    ADCSRA = (1 << ADEN) | (1 << ADSC) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS0);
    ADMUX = (1 << REFS0) | ADC_CHANNEL;
}

uint16_t adcGetPos(void) {

    return (uint16_t)adc_res_filtered;
}

ISR(ADC_vect) {

    adc_res_filtered = (LP_FILTER_A * (ADCL | (ADCH << 8))) + ((1.0F - LP_FILTER_A) * (ADCL | (ADCH << 8)));
    ADCSRA |= (1 << ADSC);
}