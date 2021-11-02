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
 * @file main.c
 * @brief Main entry point to the Course 1 final assessment
 *
 * This file contains the main code for the Course 1 final assessment.
 *
 * @author Jonathan Magill
 * @date October 28th 2021
 *
 */

#include <stdio.h>
#include <stdlib.h>


/* Main function for this assigment - calls course1() */
int main(void) {

  #ifdef COURSE1
  course1();
  #endif
  
  return 0;
}

