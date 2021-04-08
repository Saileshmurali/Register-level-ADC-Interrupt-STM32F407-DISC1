# Register-level-ADC-Interrupt-STM32F407-DISC1
ADC clock is prescaled by 4, and a sampling time of 480 cycles is used. This gives the ADC sampling rate around 8KHz. ADC1 channel 0 has been configured. This corresponds to pin PA0 to which analog input is to be connected.
If you want to configure other channels for ADC1, set the corresponding pin as analog mode and use ADC1->SQR3 |= (channel<<0); to select a desired channel
