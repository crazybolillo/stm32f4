#include "stm32f4xx_hal.h"
#include "usbd_cdc.h"
#include "usbd_cdc_if.h"
#include "usbd_desc.h"

USBD_HandleTypeDef USB_Device;

uint8_t WELCOME_MESSAGE[] = "Thermo v0.0.1 - Reflow Oven Control\r\n";

void ClockInit() {
    __HAL_RCC_PWR_CLK_ENABLE();

    RCC_OscInitTypeDef oscInitTypeDef;
    oscInitTypeDef.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    oscInitTypeDef.HSEState = RCC_HSE_ON;
    oscInitTypeDef.PLL.PLLState = RCC_PLL_ON;
    oscInitTypeDef.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    oscInitTypeDef.PLL.PLLM = 25;
    oscInitTypeDef.PLL.PLLN = 192;
    oscInitTypeDef.PLL.PLLQ = 4;
    oscInitTypeDef.PLL.PLLP = 4;
    HAL_RCC_OscConfig(&oscInitTypeDef);

    RCC_ClkInitTypeDef config;
    config.ClockType =
        RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    config.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
    config.AHBCLKDivider = 1;
    config.APB1CLKDivider = 1;
    config.APB2CLKDivider = 1;

    HAL_RCC_ClockConfig(&config, FLASH_LATENCY_1);  // No wait states required below 30 MHz
    HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_PLLCLK, RCC_MCO_DIV4);
}

void GpioInit(void) {
    GPIO_InitTypeDef gpioInitTypeDef;
    gpioInitTypeDef.Pin = GPIO_PIN_13;
    gpioInitTypeDef.Mode = GPIO_MODE_OUTPUT_PP;
    gpioInitTypeDef.Pull = GPIO_NOPULL;
    gpioInitTypeDef.Speed = GPIO_SPEED_LOW;

    __HAL_RCC_GPIOC_CLK_ENABLE();
    HAL_GPIO_Init(GPIOC, &gpioInitTypeDef);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
}

int main(void) {
    HAL_Init();
    ClockInit();
    GpioInit();

    USBD_Init(&USB_Device, &CDC_Desc, 0);
    USBD_RegisterClass(&USB_Device, USBD_CDC_CLASS);
    USBD_CDC_RegisterInterface(&USB_Device, &USBD_CDC_Template_fops);
    USBD_Start(&USB_Device);

    while (1) {
        CDC_Transmit(WELCOME_MESSAGE, sizeof(WELCOME_MESSAGE));
    }
}
