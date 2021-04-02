#include "stm32f407xx.h"
void ADC_Config(void);
void interrupt_config(void);
int value;
void ADC_Config(void)
{
	RCC->AHB1ENR |= (1UL<<0);// Enable clock for Port A
	RCC->APB2ENR |= (1<<8);  // Enable ADC1 clock
	ADC->CCR |= (1UL<<16);  //Prescale clock to ADC by 4
	ADC1->CR1 |= (2UL<<24); //8 bit adc
	ADC1->CR2 |= (1UL<<1);  //Enable continuous conversion
	ADC1->CR2 |= (1UL<<10); //Enable EOC after every conversion
	ADC1->SMPR2 |= (7UL<<0);//Select sampling time as 480 cycles for channel 0
	GPIOA->MODER |= (3UL<<0); //Configure PA0 in analog mode
}
void interrupt_config(void)
{
	NVIC_EnableIRQ(ADC_IRQn);
	ADC1->CR1 |= (1UL<<5);  //Enable interrupt
}
void ADC_IRQHandler(void)
{
	value=ADC1->DR;
	ADC1->SR = 0;
}
int main()
{
	ADC_Config();
	interrupt_config();
	ADC1->CR2 |= (1UL<<0); // Start the ADC
	ADC1->CR2 |= (1UL<<30);// Start the conversion
	ADC1->SR = 0;
	while(1)
	{

	}
}
