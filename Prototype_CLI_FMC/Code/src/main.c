#include "main.h"
/*
void pre_init(void) __attribute__((constructor));

void pre_init(void)
{
	SCB->SHCSR &= ~SCB_SHCSR_MEMFAULTENA_Msk;
	MPU->CTRL = 0;
	MPU->RNR = MPU_REGION_NUMBER0;				//region 2

#ifndef REMAP
	MPU->RBAR = 0x60000000;
#endif

#ifdef REMAP
	MPU->RBAR = 0xC0000000;

    MPU->RASR = ((uint32_t)((uint8_t)0x00U)        			<< MPU_RASR_XN_Pos)   |
                ((uint32_t)MPU_REGION_FULL_ACCESS        	<< MPU_RASR_AP_Pos)   |
                ((uint32_t)MPU_TEX_LEVEL0        			<< MPU_RASR_TEX_Pos)  |
                ((uint32_t)MPU_ACCESS_NOT_SHAREABLE        	<< MPU_RASR_S_Pos)    |
                ((uint32_t)MPU_ACCESS_CACHEABLE        		<< MPU_RASR_C_Pos)    |
                ((uint32_t)MPU_ACCESS_NOT_BUFFERABLE        << MPU_RASR_B_Pos)    |
                ((uint32_t)((uint8_t)0x00U)        			<< MPU_RASR_SRD_Pos)  |
                ((uint32_t)MPU_REGION_SIZE_256KB        	<< MPU_RASR_SIZE_Pos) |
                ((uint32_t)((uint8_t)0x01U)        			<< MPU_RASR_ENABLE_Pos);

    MPU->CTRL = MPU_PRIVILEGED_DEFAULT | MPU_CTRL_ENABLE_Msk;
    SCB->SHCSR |= SCB_SHCSR_MEMFAULTENA_Msk;
    __DSB();
    __ISB();

    SCB_EnableICache();
    SCB_EnableDCache();

	PWR->CR1 |= PWR_CR1_ODEN;
#endif
	}

volatile uint16_t e[300];
//volatile uint8_t Buffer1[8] /*__attribute__((aligned(32)));   __attribute__((at(0x60000000)));        //__attribute__((aligned(32)));
*/

int main(void){
	flash_init();
	rng_init();
	clock_update(216);
	//USART_Init(115200, 2);
	//CLI_usart_init();
	display_init(1);
    SCB_EnableICache();
    SCB_EnableDCache();

	config.CLI_bacgroundeColor = 0x00;
	config.CLI_textColor = 0xac;
	config_save(sector8);


	lcd_console_log();

	delay(2000);

	for(ever){

		if (USART_Flag.ressiveByte != 0)
		{
			//CLI_Process_Command(RessivBuffer, RessivBuffer, 10);
		}
			}
}
