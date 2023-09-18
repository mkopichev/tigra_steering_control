/*
 * uart.h
 *
 * Created: 14.03.2022 17:42:51
 *  Author: Michael
 */

#ifndef UART_H_
#define UART_H_

#include "utils.h"

// функция передачи байта
void uartTransmitByte(uint8_t byte);
// функция приёма байта
uint8_t uartReceiveByte(void);
// посылка десятичного 16-битного числа с МК в терминал
void uartSendDec(int16_t val);
// функция передачи строки, слова или фразы
void uartSendStr(char *string);
// посылка hex числа с МК в терминал
void uartSendHex(uint16_t val);
// приём десятичного 16-битного числа на МК с терминала
int16_t uartReceiveDec(void);
// приём значения с верхнего уровня по прерыванию
int16_t uartReceiveData(void);
/* функция инициализации: настройка МК на приём и передачу данных,
длина сообщения – 8 бит, один СТОП бит, без паритета, скорость обмена – 9600 бод */
void uartInit(void);

#endif