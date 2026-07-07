/***************************************************************************//**
 *   @file   color_sensor_example.c
 *   @brief  TCS34725 Example
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
 *
 * THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES, INC. “AS IS” AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL ANALOG DEVICES, INC. BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#include <stdio.h>

#include "no_os_delay.h"
#include "no_os_print_log.h"
#include "no_os_uart.h"
#include "no_os_i2c.h"
#include "common_data.h"
#include "color_sensor_example.h"
#include "tcs34725.h"

int color_sensor_example_main()
{
	struct no_os_uart_desc *uart_desc;
	struct tcs34725_desc *tcs34725_desc;
	uint8_t device_id;
	int ret;

	ret = no_os_uart_init(&uart_desc, &uart_ip);
	if (ret)
		return ret;

	no_os_uart_stdio(uart_desc);

	ret = tcs34725_init(&tcs34725_desc, &tcs34725_ip);
	if (ret) {
		printf("Error during TCS34725 initialization (%d)\n", ret);
		return ret;
	}

	printf("---- I2C debug ----\n");
	printf("bus (device_id) = %u\n", tcs34725_desc->comm_desc->device_id);
	printf("slave_address   = 0x%02x (7-bit)\n", tcs34725_desc->comm_desc->slave_address);
	printf("max_speed_hz    = %lu\n", (unsigned long)tcs34725_desc->comm_desc->max_speed_hz);


	
	ret = tcs34725_reg_read(tcs34725_desc, TCS34725_ID, &device_id);
	if (ret) {
		printf("Error reading the TCS34725's device id (%d)\n", ret);
		goto error;
	}
	printf("Got device id 0x%X\n", device_id);

error:
	printf("Error: %d\n", ret);
	tcs34725_remove(tcs34725_desc);
	return ret;
}