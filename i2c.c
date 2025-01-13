/**
 ******************************************************************************
 * @file    i2c.c
 * @author  - Timothy Gorbunov
 *          - Anthoy Raterta
 * @version V1.0.0
 * @date    13-September-2024
 * @brief   I2C wrappers for Zephyr I2C
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
#include "i2c.h"

#define i2c0_master DT_NODELABEL(i2c0)

bool init_i2c0(void) { return true; }

int8_t i2c0_write_bytes(uint8_t dev_addr, uint8_t *data_buffer) { return 0; }

int8_t i2c0_read_byte(uint8_t dev_addr, uint8_t data_read_virtual_address,
                      uint8_t *read_data) {
  return 0;
}