#ifndef __UTILITIES_H_
#define __UTILITIES_H_

#include <float.h>
#include <math.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SCALE_FACTOR 1
#define SIZE 316

/**
 * @brief Replaces commas with dots to be able to make easier type conversions
 * 
 * @param input Input string
 */
void ConvertCommaToDot(char* input);
/**
 * @brief Finds the biggest element of the input double array as a magnitude
 * 
 * @param arr Input array
 * @param size Input array size
 * @return double Returns the absolute value of the magnitudely biggest element
 */
double FindAbsMax(const double* input_arr, const size_t size);
/**
 * @brief Finds maximum and minimum numbers of a specified double array
 * 
 * @param input_arr Input array
 * @param size Input array size
 * @param max Output maximum element of the array
 * @param min Output minimum element of the array
 */
void FindMaxMin(double* input_arr, const size_t size, double* max, double* min);
/**
 * @brief Adjusts offset of a specified input signal
 * 
 * @param p_out Adjusted signal
 * @param size Input signal size
 * @param offset Input offset
 */
void AdjustOffset(double *p_out, size_t size, int offset);
/**
 * @brief Scales a specified input signal
 * 
 * @param p_out Scaled signal
 * @param size Input signal size
 */
void Scale(double *p_out, size_t size);
/**
 * @brief Applies convolution to a specified input signal
 * 
 * @param p_coeffs Input convolution coefficients. It is assumed to 1 to prevent any unwanted change in the signal
 * @param p_coeffs_n Input coefficient array size
 * @param p_in Input signal to convolve
 * @param p_out Output signal
 * @param n Input signal size
 */
void Convolve(const double *p_coeffs, const int p_coeffs_n, const double *p_in, double *p_out, const int n);

#endif /* __UTILITIES_ */