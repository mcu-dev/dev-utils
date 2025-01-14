/**
 ******************************************************************************
 * @file    utils.c
 * @author  - Anthoy Raterta
 * @version V1.0.0
 * @date    14-January-2025
 * @brief   Top-level wrappers for different functions
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 mcu-dev
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "utils.h"

#ifdef PLATFORM_ZEPHYR
#include <zephyr/kernel.h>
#endif

/**
 * @brief 	Put the current thread to sleep.
 *
 * @param s Value in seconds to put the thread to sleep
 *
 * @return None.
 * 
 */
void delay(int32_t s) {
#ifdef PLATFORM_ZEPHYR
  k_sleep(s);
#endif
}

/**
 * @brief 	Put the current thread to sleep in milliseconds
 *
 * @param ms Value in seconds to put the thread to sleep
 * in milliseconds
 *
 * @return None.
 * 
 */
void delay_ms(int32_t ms) {
#ifdef PLATFORM_ZEPHYR
  k_msleep(ms);
#endif
}

/**
 * @brief 	Put the current thread to sleep in microseconds
 *
 * @param us Value in seconds to put the thread to sleep
 * in microseconds
 *
 * @return None.
 * 
 */
void delay_us(int32_t us) {
#ifdef PLATFORM_ZEPHYR
  k_usleep(us);
#endif
}