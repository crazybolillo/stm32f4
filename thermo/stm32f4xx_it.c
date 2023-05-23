#include "stm32f4xx_it.h"

#include "stm32f4xx_hal.h"

extern PCD_HandleTypeDef hpcd;

void SysTick_Handler(void) { HAL_IncTick(); }

void OTG_FS_IRQHandler(void) { HAL_PCD_IRQHandler(&hpcd); }
