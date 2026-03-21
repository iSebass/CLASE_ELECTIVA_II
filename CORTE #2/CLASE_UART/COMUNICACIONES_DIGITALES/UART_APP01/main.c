#include "hal/config.h"
#include "hal/uart.h"
#include "hal/adc.h"


uint16_t mv, mv_temp;
float temp;

int main(void)
{
    hal_uart_config_t cfg_uart = {
		.baud_rate = 9600U,
		.data_bits = 8U,
		.stop_bits = 1U,
		.parity    = HAL_UART_PARITY_NONE,
		.use_irq   = HAL_UART_MODE_POLLING
	};
	HAL_UART_Init(HAL_UART0, &cfg_uart);
	HAL_UART_SetStdout(HAL_UART0);
	
	hal_adc_config_t cfg_adc = {
		.reference = HAL_ADC_REF_AVCC,
		.prescaler = HAL_ADC_PRESCALER_128,
		.vref_mv   = 5000U,
		.use_irq   = HAL_ADC_MODE_POLLING
	};
	HAL_ADC_Init(&cfg_adc);
	
    while (1) 
    {
		
		HAL_ADC_ReadMillivolts(0, &mv);   // Canal ADC0
		HAL_ADC_ReadMillivolts(1, &mv_temp);   // Canal ADC1
		
		temp = (150.0/1505.0)*mv_temp;
		
		printf("VOLT: %4u mV | Temp: %5.1f °C \n", mv, temp);
		
		_delay_ms(500);
    }
}

