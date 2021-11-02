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
 * @file data.h
 * @brief Data manipulation headers for the Course 1 final assessment
 *
 * This file contains headers for data manipulation funcions for the Course 1 
 * final assessment.
 *
 * @author Jonathan Magill
 * @date October 30th 2021
 *
 */

#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief Converts int to ASCII
 *
 * Given a 32 bit in of data, a ptr to a memory location and a base, converts data
 * from a signed int to a set of ASCII characters representing the number in the 
 * base given starting at the pointer location.
 *
 * @param data Signed 32 bit int of data to convert
 *
 * @param * ptr Pointer to memory location where string should be stored
 *
 * @param base Base of output value 
 *
 * @return uint8_t Length of converted string
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts from ASCII to int
 *
 * Given a 32 string of digits of a particular base at a memory location and 
 * a base, converts digits from ASCII to a 32 bit signed int.
 *
 * @param * ptr Pointer to memory location where string should be stored
 *
 * @param digits Number of digits to convert
 *
 * @param base Base of input value 
 *
 * @return int32_t Converted value as 32 bit int
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);




#endif /* __DATA_H__ */
