/**
 ******************************************************************************
 * @file    utils.h
 * @author  - Anthoy Raterta
 * @version V1.0.0
 * @date    14-January-2025
 * @brief   Contains the prototypes of the functions in utils.c
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
#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

void delay(int32_t s);

void delay_ms(int32_t ms);

void delay_us(int32_t us);

#endif /*UTILS_H*/