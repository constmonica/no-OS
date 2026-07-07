ifeq (y,$(strip $(APARD32690_ADIN1110_STANDALONE_EXAMPLE)))
CFLAGS += -DAPARD32690_ADIN1110_STANDALONE_EXAMPLE
SRCS += $(DRIVERS)/net/adin1110/adin1110.c
SRCS += $(NO-OS)/util/no_os_crc8.c
INCS += $(INCLUDE)/no_os_crc8.h
INCS += $(DRIVERS)/net/adin1110/adin1110.h

INCS += $(DRIVERS)/net/oa_tc6/oa_tc6.h
SRCS += $(DRIVERS)/net/oa_tc6/oa_tc6.c

SRC_DIRS += $(PROJECT)/src/examples/adin1110_standalone_example
endif

ifeq (y,$(strip $(APARD32690_ECHO_SERVER_EXAMPLE)))
CFLAGS += -DAPARD32690_ECHO_SERVER_EXAMPLE
LIBRARIES += lwip
CFLAGS += -DNO_OS_STATIC_IP
CFLAGS += -DNO_OS_LWIP_NETWORKING
INCS += $(INCLUDE)/no_os_crc8.h
INCS += $(DRIVERS)/net/adin1110/adin1110.h
INCS += $(NO-OS)/network/lwip_raw_socket/netdevs/adin1110/lwip_adin1110.h
SRCS += $(NO-OS)/network/lwip_raw_socket/netdevs/adin1110/lwip_adin1110.c
SRCS += $(DRIVERS)/net/adin1110/adin1110.c
SRCS += $(NO-OS)/util/no_os_crc8.c

INCS += $(DRIVERS)/net/oa_tc6/oa_tc6.h
SRCS += $(DRIVERS)/net/oa_tc6/oa_tc6.c

SRC_DIRS += $(PROJECT)/src/examples/tcp_echo_server_example
endif

ifeq (y,$(strip $(APARD32690_BASIC_EXAMPLE)))
CFLAGS += -DAPARD32690_BASIC_EXAMPLE
SRC_DIRS += $(PROJECT)/src/examples/basic_example
endif

ifeq (y,$(strip $(APARD32690_ESH_EXAMPLE)))
LIBRARIES += freertos
LIBRARIES += esh
FREERTOS_CONFIG_PATH = $(PROJECT)/src/FreeRTOSConfig.h
CFLAGS += -DAPARD32690_ESH_EXAMPLE
SRC_DIRS += $(PROJECT)/src/examples/esh_example
endif

ifeq (y,$(strip $(APARD32690_COLOR_SENSOR_EXAMPLE)))
CFLAGS += -DAPARD32690_COLOR_SENSOR_EXAMPLE
# P5 on the AD-APARD32690-SL routes I2C1 to its "alternate" pin set
# (P2.17 SDA / P2.18 SCL). MSDK's MXC_I2C_Init() always muxes the default
# I2C1 pins (P0.11/P0.12) instead, which leaves the peripheral driving
# floating pads and causes the bus-recover step to fail. Define
# MSDK_NO_GPIO_CLK_INIT so MXC_I2C_Init() skips pin/clock setup; the
# example then muxes P2.17/P2.18 and enables the I2C1 clock explicitly.
SRCS += $(DRIVERS)/api/no_os_i2c.c
SRCS += $(PLATFORM_DRIVERS)/maxim_i2c.c
SRCS += $(DRIVERS)/color-sensor/tcs34725/tcs34725.c
INCS += $(INCLUDE)/no_os_i2c.h
INCS += $(PLATFORM_DRIVERS)/maxim_i2c.h
INCS += $(DRIVERS)/color-sensor/tcs34725/tcs34725.h
SRC_DIRS += $(PROJECT)/src/examples/color_sensor_example
endif

SRCS += $(PLATFORM_DRIVERS)/maxim_irq.c		\
	$(PLATFORM_DRIVERS)/maxim_gpio.c	\
	$(PLATFORM_DRIVERS)/maxim_spi.c		\
	$(PLATFORM_DRIVERS)/../common/maxim_dma.c		\
	$(PLATFORM_DRIVERS)/maxim_timer.c	\
	$(PLATFORM_DRIVERS)/maxim_init.c	\
	$(PLATFORM_DRIVERS)/maxim_uart.c	\
	$(PLATFORM_DRIVERS)/maxim_uart_stdio.c
	
INCS += $(PLATFORM_DRIVERS)/maxim_irq.h		\
	$(PLATFORM_DRIVERS)/maxim_uart.h	\
	$(PLATFORM_DRIVERS)/maxim_timer.h	\
	$(PLATFORM_DRIVERS)/../common/maxim_dma.h	\
	$(PLATFORM_DRIVERS)/maxim_gpio.h	\
	$(PLATFORM_DRIVERS)/maxim_spi.h		\
	$(PLATFORM_DRIVERS)/maxim_uart_stdio.h

ifeq ($(if $(findstring freertos, $(LIBRARIES)), 1),)
SRCS += $(PLATFORM_DRIVERS)/maxim_delay.c
endif