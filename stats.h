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
 * @file stats.h
 * @brief statistical operations on a set of unsigned char data
 *
 * Contains function headers for carrying out statistical operations on an 
 * array of unsigned char data. Functions calculate:
 *   - maximum
 *   - minimum
 *   - mean
 *   - median
 *   - sorting of array data
 *
 * @author Jonathan Magill
 * @date 18/07/21
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

unsigned char find_minimum(unsigned char *dataset, unsigned int length);
/**
 * @brief Finds minimum value in an array
 *
 * Accepts an data set of unsigned chars in the form of an array and find the
 * minimum value in the set. This is returned as an unsigned char
 *
 * @param dataset         array of unsigned chars from which to find minimum
 * @param length          size of dataset as unsigned int
 *
 * @return minimum in form of unsigned char
 */

unsigned char find_maximum(unsigned char *dataset, unsigned int length);
/**
 * @brief Finds maximum value in an array
 *
 * Accepts an data set of unsigned chars in the form of an array and find the
 * maximum value in the set. This is returned as an unsigned char
 *
 * @param dataset         pointer to array of unsigned chars from which to 
 *                        find maximum
 * @param length          size of dataset as unsigned int
 *
 * @return maximum in form of unsigned char
 */

unsigned char find_median(unsigned char *dataset, unsigned int length);
/**
 * @brief Finds median value in an array
 *
 * Accepts an data set of unsigned chars in the form of an array and find the
 * median value of the set. This is returned as an unsigned char
 *
 * @param dataset         pointer to array of unsigned chars from which to 
 *                        find median
 * @param length          size of dataset as unsigned int
 *
 * @return median in form of unsigned char
 */

unsigned char find_mean(unsigned char *dataset, unsigned int length);
/**
 * @brief Finds mean value in an array
 *
 * Accepts an data set of unsigned chars in the form of an array and find the
 * mean value of the set. This is returned as an unsigned char
 *
 * @param dataset         pointer to array of unsigned chars from which to 
 *                        find mean
 * @param length          size of dataset as unsigned int
 *
 * @return mean in form of unsigned char
 */

unsigned char sort_array(unsigned char *dataset, unsigned int length);
/**
 * @brief Sorts values in an array from largest to smallest
 *
 * Accepts an data set of unsigned chars in the form of an array and sorts the
 * set in order from largest to smallest. The sorted results are returned as
 * an array of unsigned chars
 *
 * @param dataset         pointer to array of unsigned chars to be sorted
 * @param length          size of dataset as unsigned int
 *
 * @return sorted data as array of unsigned char
 */

void print_statistics(unsigned char minimum, unsigned char maximum, unsigned char median, unsigned char mean);
/**
 * @brief Prints statistical values to screen
 *
 * Accepts calculated statistics as unsigned chars and prints these to the 
 * screen (rounded down to nearest int)
 *
 * @param minimum         minimum calculated by find_minimum as unsigned char
 * @param maximum         maximum calculated by find_maximum as unsigned char
 * @param median          median calculated by find_median as unsigned char
 * @param mean            mean calculated by find_mean as unsigned char
 *
 * @return prints statistics to screen
 */

void print_array(unsigned char *dataset, unsigned int length);
/**
 * @brief Prints contents of array to screen
 *
 * Accepts an data set of unsigned chars in the form of an array and prints
 * contents of the array to the screen in order
 *
 * @param dataset         pointer to array of unsigned chars to print
 * @param length          size of dataset as unsigned int
 *
 * @return prints array contents to screen
 */

#endif /* __STATS_H__ */
