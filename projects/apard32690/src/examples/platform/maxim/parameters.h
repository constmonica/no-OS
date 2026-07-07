/***************************************************************************//**
 *   @file   parameters.h
 *   @brief  Definitions specific to Maxim platform used by apard32690 project.
 *   @author Monica Constandachi (monica.constandachi@analog.com)
********************************************************************************
 * Copyright 2026(c) Analog Devices, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of Analog Devices, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
*******************************************************************************/
#ifndef __PARAMETERS_H__
#define __PARAMETERS_H__

#include "maxim_uart.h"
#include "maxim_uart_stdio.h"
#include "maxim_i2c.h"

#if defined(APARD32690_COLOR_SENSOR_EXAMPLE)
#include "maxim_i2c.h"
#endif

#define UART_DEVICE_ID  0
#define UART_BAUDRATE   115200
#define UART_EXTRA      &apard32690_uart_extra_ip
#define UART_OPS        &max_uart_ops



#define I2C_DEVICE_ID   1
#define I2C_OPS         &max_i2c_ops
#define I2C_EXTRA       &apard32690_i2c_extra

extern struct max_uart_init_param apard32690_uart_extra_ip;
extern struct max_i2c_init_param apard32690_i2c_extra;

#endif /* __PARAMETERS_H__ */
