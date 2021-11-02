#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# This make file builds the output file C1M2.out for two possible platforms:
#      1) MSP432
#      2) Host
#
# Use: make [TARGET] [OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      build - Builds and links all source files
#      all - Same as build
#      clean - removes all generated files
#
# Platform Overrides:
#      PLATFORM - HOST/MSP432
#      1) TI MSP432 - ARM 32-bit Cortex-M4F based microcontroller
#      2) Host platform (Native build)
#
#------------------------------------------------------------------------------
include sources.mk

VPATH = src INCLUDE

ifeq ($(PLATFORM),HOST)
    # Architecture Specific Flags
    ARCH:=$(shell arch)
    LDFLAGS = -Wl,-Map=$(TARGET).map

    # Compiler Flags and Defines
    CC = gcc
    LD = ld
    ARCH_CFLAGS = -DHOST

    CPPFLAGs = -DHOST $(INCLUDES) -DVERBOSE -DCOURSE1

    OBJDUMP = objdump

    SIZE = size         

else
    # Architecture Specific Flags
    LINKER_FILE = msp432p401r.lds
    ARCH = armv7e-m
    CPU = cortex-m4
    SPECS = nosys.specs
    FPU = fpv4-sp-d16
    MODE = thumb
    FLOAT = float-abi=hard
    ARCH_CFLAGS = -mcpu=$(CPU) \
                  -m$(MODE) \
                  --specs=$(SPECS) \
                  -m$(FLOAT) \
                  -march=$(ARCH) \
                  -mfpu=$(FPU) \
                  -DMSP432
    LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE) 

    # Compiler Flags and Defines
    CC = arm-none-eabi-gcc
    LD = arm-none-eabi-ld

    CPPFLAGs = -DMSP432 $(INCLUDES)
    
    OBJDUMP = arm-none-eabi-objdump

    SIZE = arm-none-eabi-size

endif

# Compiler Flags and Defines
TARGET = main
CFLAGS = $(ARCH_CFLAGS) \
     $(INCLUDES) \
     -Wall \
     -Werror \
     -g \
     -O0 \
     -std=c99
         

# Dependency files
DEPS := $(SOURCES:.c=.d)
OBJS := $(SOURCES:.c=.o)
I = $(SOURCES:.c=.i)

%.d : %.c
	$(CC) -c -E -MMD $< $(CFLAGS) $(CPPFLAGS) -o $@

%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@

%.i : %.c
	$(CC) -c -E $< $(CFLAGS) $(CPPFLAGS) -o $@

%.asm : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) $(PLATFORM) $(INCLUDES) $(LDFLAGS) -S -o $@

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS) $(DEPS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) -o $@
	$(SIZE) -Atd $(TARGET).out
	$(SIZE) $(TARGET).out

.PHONY: compile-all
compile-all: $(OBJS) $(DEPS)
	$(CC) -c $(OBJS) $(CFLAGS) $(CPPFLAGS) -o $(TARGET).o

.PHONY: clean
clean: 
	$(RM) count *.o *.map *.out *.asm *.i *.d
