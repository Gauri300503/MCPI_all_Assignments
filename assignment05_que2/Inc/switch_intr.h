/*
 * switch_intr.h
 *
 *  Created on: Sep 24, 2024
 *      Author: gauri
 */

#ifndef SWITCH_INTR_H_
#define SWITCH_INTR_H_

#include "stm32f4xx.h"

#define GPIO_SWITCH				GPIOA
#define SWITCH_PIN				0
#define SWITCH_GPIO_CLKEN		0

#define SWITCH_EXTI				0

void SwitchInit(void);
void EXTI0_IRQHandler(void);

volatile extern uint32_t SwitchExtiFlag;
volatile uint32_t switch_press_count=0;

#endif /* SWITCH_INTR_H_ */
