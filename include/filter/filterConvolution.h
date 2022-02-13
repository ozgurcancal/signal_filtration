#ifndef __FILTER_CONVOLUTION_H_
#define __FILTER_CONVOLUTION_H_

#include "utilities.h"

/**
 * @brief Applies convolution to a specified input signal
 * 
 * @param p_in Input signal to convolve
 * @param p_out Output signal
 * @param p_coeffs Input convolution coefficients. It is assumed to 1 to prevent any unwanted change in the signal
 * @param size Input signal size
 */
void FilterConvolution(const double* p_in, double* p_out, double* p_coeffs, const size_t size);




#endif /* __FILTER_CONVOLUTION_H_ */