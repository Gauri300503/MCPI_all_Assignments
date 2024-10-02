/*
 * systic.h
 *
 *  Created on: Oct 2, 2024
 *      Author: gauri
 */

#ifndef SYSTIC_H_
#define SYSTIC_H_

#include "stm32f4xx.h"

void SysTick_Handler(void);
void SysTick_Delay(uint32_t ms);



#endif /* SYSTIC_H_ */
