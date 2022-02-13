
#include "fileHandler.h"
#include "utilities.h"
#include "filterConvolution.h"


int main(void)
{

    const char in_file_name[]="/../data_samples.txt";
    const char out_file_name[]="/../filtered_output.txt";

    double p_in[SIZE] = {0};
    double p_out[SIZE] = {0};
    double p_coeffs[SIZE]= {0};

    GetFileValues(in_file_name, p_in);

    FilterConvolution(p_in, p_out, p_coeffs, SIZE);

    WriteFile(out_file_name, p_out, SIZE);


    return 0;
}


