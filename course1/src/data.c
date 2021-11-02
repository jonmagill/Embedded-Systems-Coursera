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
#include "data.h"
#include "memory.h"

// assuming negative numbers provided in 2's complement
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
  int modulo, digits;
  int neg = 0;
  
  // check sign of 
  if (data/0x80000000 == 1) {
    // value is negative
    neg = 1;
    data = (data -1) ^ 0xFFFFFFFF;
  }

  while(data != 0) {
    modulo = data % base;
    data /= base;

    // for bases higher than 10
    if(modulo > 9) {
      *ptr = (uint8_t) modulo + 55;
    }
    else {
      *ptr = modulo + 48;
    }
    ptr++;
    digits++;
  }
  if(neg == 1) {
    *ptr = 45;
    ptr++;
    digits++;
  }

  // reverse order of digits
  my_reverse(ptr, digits);

  return digits;
  
    
}

// assuming 2's complement for negative numbers
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){ 
  uint32_t sum = 0;
  int neg = 0;
  
  // check for negative number
  if(*ptr == 45) {
    neg = 1;
    ptr++;
  }
  
  ptr = ptr + digits -1;

  int power = 1;
  if(neg == 1){
    digits--;
  }

  while(digits != 0) {
    if (*ptr > 65) {
        *ptr -= 55;
    }
    else {
        *ptr -= 48;
    }
    ptr++;
    sum += *ptr * power;
    digits--;
    power *= base;
  }
  
  // apply 2's complement if neg = 1
  if (neg == 1) {
    sum = (sum ^ (0xFFFFFFFE)) + 1;
  }
  
  return sum;
}
