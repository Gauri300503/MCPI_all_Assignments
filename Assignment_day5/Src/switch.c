/*
 * switch.c
 *
 *  Created on: Sep 22, 2024
 *      Author: gauri
 */

#include "switch.h"
#include "led.h"

void SwitchInit()
{
	RCC->AHB1ENR |= BV(SWITCH_CLK);
	GPIO_SWITCH->MODER &= ~(BV((SWITCH_PIN<<1)+1) | BV(SWITCH_PIN<<1));
	GPIO_SWITCH->PUPDR &= ~(BV((SWITCH_PIN<<1)+1) | BV(SWITCH_PIN<<1));

	EXTI->FTSR |= BV(SWITCH_EXTI);
	EXTI->IMR |= BV(SWITCH_EXTI);

	SYSCFG->EXTICR[0] &= ~(BV(3)|BV(2)|BV(1)|BV(0));
	NVIC_EnableIRQ(EXTI0_IRQn);
}

volatile uint32_t flag = 0;
void EXTI0_IRQHandler()
{
	EXTI->PR |= BV(SWITCH_EXTI);
	flag=1;
	//ledtoggle(GPIO_RED_PIN,1000);
}


