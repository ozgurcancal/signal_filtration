#include "utilities.h"


void ConvertCommaToDot(char *input)
{
    char *ptr = NULL;
    while (ptr = strpbrk(input, ","))
    {
        *ptr = '.';
    }
}

double FindAbsMax(const double *arr, const size_t size)
{
    double abs_max = DBL_MIN;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > fabs(abs_max)){
            abs_max = fabs(arr[i]);
        }

    }

    return abs_max;

}

void FindMaxMin(const double *arr, size_t size, double* max, double* min)
{
    *max = DBL_MIN;
    *min = DBL_MAX;
    double max_min[2] = {0,0}; 


    for (int i = 0; i < size; i++)
    {
        if (arr[i] > *max){
            *max = arr[i];
        }

        if(arr[i] < *min){
            *min = arr[i];
        }

    }

}

void AdjustOffset(double *arr, size_t size, int offset)
{
    double max=0;
    double min=0;

    FindMaxMin(arr, size, &max, &min);
 
    double final_offset=-(max+min)/2+ offset;

    for(int i=0;i<size;i++){
        arr[i]+=final_offset;
    }

}

void Scale(double *p_out, size_t size)
{
    double abs_max = FindAbsMax(p_out, size);
  //  printf("abs_max= %0.5f\n", abs_max);
    double scale_constant = SCALE_FACTOR / fabs(abs_max);
 //   printf("scale_constant= %0.5f\n", scale_constant);
    for (int i = 0; i < size; i++)
    {
        p_out[i] *= scale_constant;
    }
}

void Convolve(const double *p_coeffs, const int p_coeffs_n, const double *p_in, double *p_out, int n)
{

    int i, j, k;
    double tmp;

    for (k = 0; k < n; k++) //  position in output
    {
        tmp = 0;

        for (i = 0; i < p_coeffs_n; i++)  //  position in coefficients array
        {
            j = k - i;  //  position in input

            if (j >= 0) //  bounds check for input buffer
            {
                tmp += p_coeffs[i] * p_in[j];
            }
        }

        p_out[k] = tmp;
    }
}

