#include "hal/config.h"
#include "hal/gpio.h"
#include "hal/uart.h"
#include "hal/interrupt.h"
#include "hal/timer.h"
#include "hal/adc.h"

 int main(void) {
	 
	 //CONFIGURAMOS EL UART
	hal_uart_config_t cfg = {
		.baud_rate = 9600U,
		.data_bits = 8U,
		.stop_bits = 1U,
		.parity    = HAL_UART_PARITY_NONE,
		.use_irq   = HAL_UART_MODE_POLLING
	};
	HAL_UART_Init(HAL_UART0, &cfg);
	HAL_UART_SetStdout(HAL_UART0);
	
	 //CONFIGURAMOS EL ADC
	hal_adc_config_t cfg_adc = {
		.reference = HAL_ADC_REF_AVCC,
		.prescaler = HAL_ADC_PRESCALER_128,
		.vref_mv   = 5000U,
		.use_irq   = HAL_ADC_MODE_POLLING
	};
	HAL_ADC_Init(&cfg_adc);
	
	printf("Sistema iniciado\n");
	
	while (1) {
			uint16_t mv;
			
			HAL_ADC_ReadMillivolts(0, &mv);   // Canal ADC0
			printf("Tension: %u mV\n", mv);
	}
 }