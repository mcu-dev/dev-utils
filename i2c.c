/**
 ******************************************************************************
 * @file    i2c.c
 * @author  - Anthony E.Raterta
 * @version V1.0.0
 * @date    13-September-2024
 * @brief   I2C wrappers for Zephyr I2C
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
#include <stdint.h>
#include <stdio.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/kernel.h>

#include "i2c.h"

#define i2c0_master DT_NODELABEL(i2c0)

bool init_i2c0(struct device **bus) {
  *bus = DEVICE_DT_GET(i2c0_master);
  if (!device_is_ready(*bus)) {
    printk("I2C bus is not ready!\n\r");
    return false;
  }
  return true;
}

int i2c0_write_bytes(struct device **bus, uint8_t address,
                     uint8_t *data_buffer) {
  uint32_t bytecount = 2;
  return i2c_write(*bus, data_buffer, bytecount, address);
}

int i2c0_read_byte(struct device **bus, uint8_t address,
                   uint8_t data_read_virtual_address, uint8_t *read_data) {
  int ret;
  uint32_t bytecount = 1;

  ret = i2c_write(*bus, &data_read_virtual_address, bytecount, address);
  if (ret != 0) {
    return ret;
  }

  ret = i2c_read(*bus, read_data, sizeof(*read_data), address);
  if (ret != 0) {
    return ret;
  }
  return 0;
}