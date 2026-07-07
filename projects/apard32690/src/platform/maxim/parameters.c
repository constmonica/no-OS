/***************************************************************************//**
 *   @file   parameters.c
 *   @brief  Definition of Maxim platform data used by apard32690 project.
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

#include "parameters.h"

struct max_uart_init_param apard32690_uart_extra_ip = {
	.flow = MAX_UART_FLOW_DIS,
	.vssel = MXC_GPIO_VSSEL_VDDIOH,
};

struct max_i2c_init_param apard32690_i2c_extra = {
	.vssel = MXC_GPIO_VSSEL_VDDIOH
};
