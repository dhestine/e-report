int main(void){

	/* Equivalent to the void setup() */

	// Enable clock access to GPIOA
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	// Set GPIOA Pin 5 as output
	GPIOA->MODER &= ~GPIO_MODER_MODE5_Msk; // ensure the bits are set to zero

	GPIOA->MODER |= GPIO_MODER_MODER5_0; // Writes 1 to bit 10

//	CLEAR_BIT(GPIOA->MODER,0);
//	SET_BIT(GPIOA->MODER,1);
	/* Equivalent to the void loop() */
	while(1){

		GPIOA->BSRR |= GPIO_BSRR_BS5; // sets pin 5 high
		GPIOA->BSRR |= GPIO_BSRR_BR0; // sets pin 5 high
		for(int i=0; i<100000; i++); // does nothing for 300000 cycles

		GPIOA->BSRR |= GPIO_BSRR_BR5; // sets pin 5 low (resets it)
		GPIOA->BSRR |= GPIO_BSRR_BS0; // sets pin 5 low (resets it)
		for(int i=0; i<100000; i++); // does nothing for 300000 cycles

	}
}
