/******************************************************************************
 * Copyright (C) 2021 by Jonathan Magill
 *
 * Use or modification of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to use this file as required. Jonathan Magill not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.c
 * @brief Data manipulation functions for the Course 1 final assessment
 *
 * This file contains the data manipulation funcions for the Course 1 final 
 * assessment.
 *
 * @author Jonathan Magill
 * @date October 30th 2021
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include "data.h"
#include "memory.h"



// assuming negative numbers provided in 2's complement
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
  int modulo;
  int digits = 0;
  int neg = 0;
  
  // check sign of 
  if (data < 0) {
    // value is negative
    neg = 1;
    data *= -1;
  }

  while(data != 0) {
    modulo = data % base;

    // for bases higher than 10
    if(modulo > 9) {
      *ptr = (uint8_t) modulo + 55;
    }
    else {
      *ptr = modulo + 48;
    }
    ptr++;
    digits++;
    data = data/base;
  }

  if(neg == 1) {
    *ptr = 45;
    ptr ++;
    digits++;
  }

  // reset pointer position
  ptr = ptr - digits;
  
  // reverse order of digits
  my_reverse(ptr, digits);

  return digits;
}

// assuming 2's complement for negative numbers
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){ 
  uint32_t sum = 0;
  int neg = 0;

  ptr = ptr+digits-1;
  int power = 1;

  while(digits != 0) {
    // check for negative number
    if(*ptr == 45) {
      neg = 1;
    }

    else if (*ptr > 65) {
      *ptr -= 55;
      sum += *ptr * power;
    }
    else {
      *ptr -= 48;
      sum += *ptr * power;
    }
    digits--;
    power *= base;
    ptr --;
  }
  ptr ++;
  // apply 2's complement if neg = 1
  if (neg == 1) {
    sum *= -1;
  }
  
  return sum;
}
