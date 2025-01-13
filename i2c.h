/**
 ******************************************************************************
 * @file    i2c.h
 * @author  - Timothy Gorbunov
 *          - Anthoy Raterta
 * @version V1.0.0
 * @date    13-September-2024
 * @brief   I2C wrappers prototypes
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 Timothy Gorbunov
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
#ifndef I2C_H_INCLUDED
#define I2C_H_INCLUDED

#include <stdbool.h>
#include <stdint.h>

bool i2c_init(void);
int8_t i2c_write_bytes(uint8_t dev_addr, uint8_t *data_buffer);
int8_t i2c_read_byte(uint8_t dev_addr, uint8_t data_read_virtual_address,
                     uint8_t *read_data);
#endif