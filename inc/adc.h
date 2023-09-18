#ifndef ADC_H_
#define ADC_H_

#include "utils.h"

#define ADC_CHANNEL 0
#define LP_FILTER_A 0.95F

void adcInit(void);
uint16_t adcGetPos(void);

#endif