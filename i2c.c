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
 * Copyright (c) 2024 Timothy Gorbunov, mcu-dev
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
#include "i2c.h"

#ifdef PLATFORM_ZEPHYR
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/kernel.h>

#define i2c0_master DT_NODELABEL(i2c0)
const struct device *i2c0_dev;
#endif

/**
 * @brief Initializes the I2C interface.
 *
 * This function sets up the I2C peripheral for communication.
 *
 * @param None.
 *
 * @return `true` if the initialization is successful,
 *         `false` otherwise (future implementation).
 */
bool i2c_init(void) {
#ifdef PLATFORM_ZEPHYR
  i2c0_dev = DEVICE_DT_GET(i2c0_master);
  if (!device_is_ready(i2c0_dev)) {
    printk("I2C bus is not ready!\n\r");
    return false;
  }
#endif
  return true;
}

/**
 * @brief Writes data to a register of the device over I2C.
 *
 * This function writes data to a specified register of the device using
 * the provided data buffer.
 *
 * @param dev_addr     I2C address of the device.
 * @param data_buffer Pointer to the buffer containing the data to be written.
 *
 * @return
 *   - 0 on success.
 *   - Non-zero error code on failure.
 */
int8_t i2c_write_bytes(uint8_t dev_addr, uint8_t *data_buffer) {
#ifdef PLATFORM_ZEPHYR
  uint32_t bytecount = 2;
  return i2c_write(i2c0_dev, data_buffer, bytecount, dev_addr);
#endif
}

/**
 * @brief Reads a register value from the device via I2C.
 *
 * Reads a single register from the device and stores the retrieved value
 * in the specified buffer.
 *
 * @param dev_addr     I2C address of the device
 * @param data_read_virtual_address         Register address to read from.
 * @param read_data   Pointer to the buffer where the read value will be stored.
 *
 * @return
 *   - 0 on success.
 *   - Non-zero error code on failure.
 */
int8_t i2c_read_byte(uint8_t dev_addr, uint8_t data_read_virtual_address,
                     uint8_t *read_data) {
#ifdef PLATFORM_ZEPHYR         
  uint32_t bytecount = 1;

  if (i2c_write(i2c0_dev, &data_read_virtual_address, bytecount, dev_addr) !=
      I2C_STATUS_SUCCESS) {
    return I2C_STATUS_ERR;
  }

  if (i2c_read(i2c0_dev, read_data, sizeof(*read_data), dev_addr) !=
      I2C_STATUS_SUCCESS) {
    return I2C_STATUS_ERR;
  }

  return I2C_STATUS_SUCCESS;
#endif
}