#ifndef __FILE_HANDLER_H_
#define __FILE_HANDLER_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_LINE 1024

/**
 * @brief Gets values from a specified text file
 * 
 * @param fileName Input file name
 * @param p_out Output double array
 */
void GetFileValues(const char* fileName, double* p_out);
/**
 * @brief Write values into a specified file
 * 
 * @param out_fileName Output file name
 * @param data_to_write Input data to write 
 * @param size Input data size
 */
void WriteFile(const char* out_fileName, double* data_to_write, size_t size);

#endif /* __FILE_HANDLER_H_ */