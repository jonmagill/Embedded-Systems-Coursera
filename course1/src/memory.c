/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
  // create copy of src to allow overlaps
  uint8_t copySrc[length];
  uint8_t *copySrcPtr = copySrc;
  
  for (int i = 0; i < length; i++) {
    *copySrcPtr = *src;
    copySrcPtr ++;
    src++;
  }
  
  // reset pointer to start of copy
  copySrcPtr = copySrc;

  // copy into destination
  for (int i = 0; i < length; i++) {
    *dst = *copySrcPtr;
    copySrcPtr++;
    dst++;
  }

  // return pointer to start of dst
  return dst - length;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
  
  for (int i = 0; i < length; i++) {
    *dst = *src;
    dst++;
    src++;
  }
  
  // return pointer to start of dst
  return dst - length;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
  for (int i = 0; i < length; i++) {
    *src = value;
    src++;
  }

  // return pointer to src
  return src - length;
}

uint8_t * my_memzero(uint8_t * src, size_t length){
  for (int i = 0; i < length; i++) {
    *src = 0;
    src++;
  }

  // return pointer to src
  return src - length;
}

uint8_t * my_reverse(uint8_t * src, size_t length){
  // create pointers to start and end of src
  uint8_t *ptrStart = src;    
  uint8_t *ptrEnd = src + (length-1); 
  
  // create swap variable to hold value
  uint8_t swap = 0;
  
  while((ptrEnd - ptrStart) > 1) {
    swap = *ptrStart;
    *ptrStart = *ptrEnd;
    *ptrEnd = swap;
    ptrStart++;
    ptrEnd--; 
  
    if(ptrStart == (ptrEnd -1)) {
      swap = *ptrStart;
      *ptrStart = *ptrEnd;
      *ptrEnd = swap;
    }
  }
  return src;
}

int32_t * reserve_words(size_t length){
  int32_t * resWordsPtr;

  // allocate memory
  resWordsPtr = (int32_t *) malloc(sizeof(size_t) * length);

  // if malloc returns 0, return null pointer
  if (resWordsPtr == 0) {
    return NULL;
  }
  return resWordsPtr;
}

void free_words(uint32_t * src){
  // free memory
  free(src);
}
