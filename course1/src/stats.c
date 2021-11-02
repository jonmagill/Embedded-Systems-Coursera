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
 * @file stats.c
 * @brief Carries out a set of statistical operations on a set of input data
 * and prints the results
 *
 * Takes an array of unsigned char data items and calculates:
 *   - maximum
 *   - minimum
 *   - mean
 *   - median
 * (rounded down to the nearest int)
 *
 * The data is sorted from largest to smallest and all the data is printed to
 * the screen.
 *
 * @author Jonathan Magill
 * @date 18/07/21
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

/*void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};


  // calculate statistics
  unsigned char minimum = find_minimum(test,SIZE);
  unsigned char maximum = find_maximum(test,SIZE);
  unsigned char median = find_median(test,SIZE);
  unsigned char mean = find_mean(test,SIZE);

  // print statistics to display
  print_statistics(minimum, maximum, median, mean);

  // sort array
  sort_array(test,SIZE);

  // print sorted array results
  print_array(test, SIZE);
}*/

/* Add other Implementation File Code Here */


unsigned char find_minimum(unsigned char *dataset, unsigned int length) {
  // initialise minimum to first value of data
  unsigned char minimum = *dataset;
  /* compare minimum with each other value in data in turn, update if lower
  *  value is found
  */
  for (int n = 1; n < length; n++) {
    if (minimum > *(dataset + n)) {
      minimum = *(dataset + n);
    }
  }
  
  return minimum;
}


unsigned char find_maximum(unsigned char *dataset, unsigned int length) {
  // initialise maximum to first value of data
  unsigned char maximum = *dataset;
  /* compare maximum with each other value in data in turn, update if higher
  *  value is found
  */
  for (int n = 1; n < length; n++) {
    if (maximum < *(dataset + n)) {
      maximum = *(dataset + n);
    }
  }
  
  return maximum;
}


unsigned char find_median(unsigned char *dataset, unsigned int length) {
  // copying array of data so original is undisturbed
  unsigned char medianArray[length], median;
  for (int n = 0; n < length; n++) {
    *(medianArray + n) = *(dataset + n);
  }
  // call sort_array on copied array
  sort_array(medianArray,length);
  // for odd number of elements (n) median is element (n-1)/2
  if (length % 2 == 1) {
    median = medianArray[(length - 1)/2];
  }
  else {
    // otherwise, take mean of elements (n/2) and (n/2 - 1)
    median = (medianArray[length/2] + medianArray[length/2 - 1])/2; 
  }
  return median;
}


unsigned char find_mean(unsigned char *dataset, unsigned int length) {
  unsigned int sum = 0;
  unsigned char mean;
  // sum all values and divide by length
  for (int n = 0; n < length; n++) {
    sum += *(dataset + n);
  }
  mean = sum/length;

  return mean;
}


void sort_array(unsigned char *dataset, unsigned int length) {
  unsigned char n, m, swap;
  // bubble sorting used for simplicity
  for (n = 0; n < length -1; n++) {
    for (m = n; m < length; m++) {
      if (*(dataset + n) < *(dataset + m)) {
        swap = *(dataset + n);
        *(dataset + n) = *(dataset + m);
        *(dataset + m) = swap;
      }
    }
  }
}


void print_statistics(unsigned char minimum, unsigned char maximum, unsigned char median, unsigned char mean) {
  PRINTF("The statistics for the data set provided are as follows:\n\n");
  PRINTF("\tMinimum value:\t\t%d\n", minimum);
  PRINTF("\tMaximum value:\t\t%d\n", maximum);
  PRINTF("\tMedian value:\t\t%d\n", median);
  PRINTF("\tMean value:\t\t%d\n", mean);
  PRINTF("\n");
}


void print_array(unsigned char *dataset, unsigned int length) {
  #ifdef VERBOSE
  PRINTF("The contents of the array are: \n\n");
  for (unsigned int n = 0; n < length; n++) {
    int ans = *(dataset + n);
    PRINTF("%d \t", ans);
    if ((n + 1) % 8 == 0) {
      PRINTF("\n");
    }
  }
  PRINTF("\n");
  #endif
}
