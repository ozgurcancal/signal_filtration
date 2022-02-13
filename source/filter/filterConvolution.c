#include <filterConvolution.h>

#define DEBUG_FILTER_CONVOLUTION 0

void FilterConvolution(const double* p_in, double* p_out, double* p_coeffs, const size_t size){

#if DEBUG_FILTER_CONVOLUTION
      printf("Original file values\n");
    for (int i = 0; i < size; i++)
    {
        printf("%0.5f\n", p_in[i]);
    }
     printf("\n\n");
#endif

    //fill p_coeffs with 1
    for (int i = 0; i < size; i++)
    {
        p_coeffs[i] = 1;
    }

#if DEBUG_FILTER_CONVOLUTION
    printf("Before Convolve p_coeffs:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%0.5f\n", p_coeffs[i]);
    }

    printf("\n");
#endif

    Convolve(p_coeffs, size, p_in, p_out, size);
    
#if DEBUG_FILTER_CONVOLUTION
    printf("Before Scale\n");

    for (int i = 0; i < size; i++)
    {
        printf("%0.5f\n", p_out[i]);
    }

    printf("\n");
#endif
    AdjustOffset(p_out,size,0);
    Scale(p_out, size);

#if DEBUG_FILTER_CONVOLUTION
    printf("After Scale\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d: %0.5f\n", i, p_out[i]);
    }

#endif
}