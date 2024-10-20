/**
 ******************************************************************************
 * @file    i2c.h
 * @author  - Anthony E.Raterta
 * @version V1.0.0
 * @date    13-September-2024
 * @brief   I2C wrappers prototypes
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 mcu-dev
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

#include <stdint.h>
#include <zephyr/device.h>

bool init_i2c0(struct device **bus);
int i2c0_write_bytes(struct device **bus, uint8_t address,
                     uint8_t *data_buffer);
int i2c0_read_byte(struct device **bus, uint8_t address,
                   uint8_t data_read_virtual_address, uint8_t *read_data);
#endif