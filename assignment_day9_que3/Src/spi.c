/*
 * spi.c
 *
 *  Created on: Sep 25, 2024
 *      Author: gauri
 */

#include "spi.h"

void SPI_Init(void)
{
 // GPIOE  initialization

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
    GPIOE->MODER |=BV(SPI_CS_PIN*2);
    GPIOE->MODER &=~BV(SPI_CS_PIN*2+1);

    //SET OSPEER=00
    GPIOE->OSPEEDR &=~BV(SPI_CS_PIN*2)|BV(SPI_CS_PIN*2+1);
    //SET OTYPER=0 (PUSH PULL)
    GPIOE->OTYPER &=~BV(SPI_CS_PIN);
    //NO PUSH AND PULL-UP
    GPIOE->PUPDR &=~BV(SPI_CS_PIN*2)|BV(SPI_CS_PIN*2+1);

    //GPIOA(SPI) INITIALIZATION
    	RCC->AHB1ENR |=RCC_AHB1ENR_GPIOAEN;
    	//SET MODER
    	GPIOA->MODER &=~BV(SPI_SCLK_PIN*2)|BV(SPI_MISO_PIN*2)|BV(SPI_MOSI_PIN*2);
    	GPIOA->MODER |=BV(SPI_SCLK_PIN*2+1)|BV(SPI_MISO_PIN*2+1)|BV(SPI_MOSI_PIN*2+1);
      //SELECT ALT FN AF5=0101
    	GPIOA->AFR[0] &=~ BV(31)|BV(29)|BV(27)|BV(25)|BV(23)|BV(21);
    	GPIOA->AFR[0] |=BV(30)|BV(28)|BV(26)|BV(24)|BV(22)|BV(20);

    //SPI initialization
    	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;

    	SPI1->CR1=SPI_CR1_MSTR | SPI_CR1_SSM |SPI_CR1_SSI |SPI_CR1_BR_1;
    	//CR2...DISABLE INTRRUPTS
    	SPI1->CR2 |= 0x0000;
    	SPI1->CR1 |=SPI_CR1_SPE;


}

void SPI_CS_Enable(void)
{
	//GPIOE.3=0
	GPIOE->ODR &=~BV(SPI_CS_PIN);

}

void SPI_CS_Disable(void)
{
	//GPIOE.3=1
   GPIOE->ODR |=BV(SPI_CS_PIN);
}


uint16_t SPI_Transmit(uint16_t val) {
	// wait until previous data is transmitted (txe)
	while(!(SPI1->SR & SPI_SR_TXE));
	// write data into DR
	SPI1->DR = val;
	// wait until new data is received (rxne)
	while(!(SPI1->SR & SPI_SR_RXNE));
	// read data from DR
	val = SPI1->DR;

	return val;
}


uint16_t SPI_Receive(void)
{
  uint16_t val= SPI_Transmit(0x00);
  return val;
}
