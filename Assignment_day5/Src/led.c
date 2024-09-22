/*
 * led.c
 *
 *  Created on: Sep 22, 2024
 *      Author: gauri
 */


#include "led.h"

void ledinit(uint32_t GPIO_LED_PIN)
{
	RCC->AHB1ENR |= BV(GPIO_LED_CLK);
	GPIO_LED->MODER &= ~BV((GPIO_LED_PIN<<1)+1);
	GPIO_LED->MODER |= BV(GPIO_LED_PIN<<1);
	GPIO_LED->OTYPER &= ~BV(GPIO_LED_PIN);
	GPIO_LED->OSPEEDR &= ~(BV((GPIO_LED_PIN<<1)+1) | BV(GPIO_LED_PIN<<1));
	GPIO_LED->PUPDR &= ~(BV((GPIO_LED_PIN<<1)+1) | BV(GPIO_LED_PIN<<1));
}

void ledon(uint32_t GPIO_LED_PIN)
{
    GPIO_LED->ODR |= BV(GPIO_LED_PIN);
}

void ledoff(uint32_t GPIO_LED_PIN)
{
    GPIO_LED->ODR &= ~BV(GPIO_LED_PIN);
}

void ledblink(uint32_t GPIO_LED_PIN, uint32_t delay)
{
	ledon(GPIO_LED_PIN);
	DelayMs(delay);
	ledoff(GPIO_LED_PIN);
	DelayMs(delay);
}
