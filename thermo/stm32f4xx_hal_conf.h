#ifndef __STM32F4xx_HAL_CONF_H
#define __STM32F4xx_HAL_CONF_H

#define HAL_DMA_MODULE_ENABLED
#define HAL_FLASH_MODULE_ENABLED
#define HAL_GPIO_MODULE_ENABLED
#define HAL_EXTI_MODULE_ENABLED
#define HAL_I2C_MODULE_ENABLED
#define HAL_PWR_MODULE_ENABLED
#define HAL_RCC_MODULE_ENABLED
#define HAL_SPI_MODULE_ENABLED
#define HAL_TIM_MODULE_ENABLED
#define HAL_CORTEX_MODULE_ENABLED
#define HAL_PCD_MODULE_ENABLED
#define HAL_TIM_MODULE_ENABLED

#include "stm32f4xx_hal_cortex.h"
#include "stm32f4xx_hal_dma.h"
#include "stm32f4xx_hal_exti.h"
#include "stm32f4xx_hal_flash.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_i2c.h"
#include "stm32f4xx_hal_pcd.h"
#include "stm32f4xx_hal_pwr.h"
#include "stm32f4xx_hal_rcc.h"
#include "stm32f4xx_hal_spi.h"
#include "stm32f4xx_hal_tim.h"

/* ########################## HSE/HSI Values adaptation ##################### */
/**
 * @brief Adjust the value of External High Speed oscillator (HSE) used in your application.
 *        This value is used by the RCC HAL module to compute the system frequency
 *        (when HSE is used as system clock source, directly or through the PLL).
 */
#if !defined(HSE_VALUE)
#define HSE_VALUE 25000000U /*!< Value of the External oscillator in Hz */
#endif                      /* HSE_VALUE */

#if !defined(HSE_STARTUP_TIMEOUT)
#define HSE_STARTUP_TIMEOUT 100U /*!< Time out for HSE start up, in ms */
#endif                           /* HSE_STARTUP_TIMEOUT */

/**
 * @brief Internal High Speed oscillator (HSI) value.
 *        This value is used by the RCC HAL module to compute the system frequency
 *        (when HSI is used as system clock source, directly or through the PLL).
 */
#if !defined(HSI_VALUE)
#define HSI_VALUE 16000000U /*!< Value of the Internal oscillator in Hz */
#endif                      /* HSI_VALUE */

/**
 * @brief Internal Low Speed oscillator (LSI) value.
 */
#if !defined(LSI_VALUE)
#define LSI_VALUE 32000U /*!< LSI Typical Value in Hz */
#endif /* LSI_VALUE */   /*!< Value of the Internal Low Speed oscillator in Hz    \
                              The real value may vary depending on the variations \
                              in voltage and temperature. */
/**
 * @brief External Low Speed oscillator (LSE) value.
 */
#if !defined(LSE_VALUE)
#define LSE_VALUE 32768U /*!< Value of the External Low Speed oscillator in Hz */
#endif                   /* LSE_VALUE */

#if !defined(LSE_STARTUP_TIMEOUT)
#define LSE_STARTUP_TIMEOUT 5000U /*!< Time out for LSE start up, in ms */
#endif                            /* LSE_STARTUP_TIMEOUT */

/**
 * @brief External clock source for I2S peripheral
 *        This value is used by the I2S HAL module to compute the I2S clock source
 *        frequency, this source is inserted directly through I2S_CKIN pad.
 */
#if !defined(EXTERNAL_CLOCK_VALUE)
#define EXTERNAL_CLOCK_VALUE 12288000U /*!< Value of the External oscillator in Hz*/
#endif                                 /* EXTERNAL_CLOCK_VALUE */

/* Tip: To avoid modifying this file each time you need to use different HSE,
   ===  you can define the HSE value in your toolchain compiler preprocessor. */

/* ########################### System Configuration ######################### */
/**
 * @brief This is the HAL system configuration section
 */
#define VDD_VALUE 3300U         /*!< Value of VDD in mv */
#define TICK_INT_PRIORITY 0x0FU /*!< tick interrupt priority */
#define PREFETCH_ENABLE 1U
#define INSTRUCTION_CACHE_ENABLE 1U
#define DATA_CACHE_ENABLE 1U

#define USE_SPI_CRC 1U

#ifdef USE_FULL_ASSERT
/**
 * @brief  The assert_param macro is used for function's parameters check.
 * @param  expr If expr is false, it calls assert_failed function
 *         which reports the name of the source file and the source
 *         line number of the call that failed.
 *         If expr is true, it returns no value.
 * @retval None
 */
#define assert_param(expr) ((expr) ? (void)0U : assert_failed((uint8_t*)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
void assert_failed(uint8_t* file, uint32_t line);
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

#endif /* __STM32F4xx_HAL_CONF_H */
