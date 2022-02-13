#include "fileHandler.h"
#include "utilities.h"


void GetFileValues(const char* file_name, double *p_in)
{
    FILE *in_file;

    if ((in_file = fopen(file_name, "r")) == NULL)
    {
        fprintf(stderr, "cannot open input file!..\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE];
    char *str;

    char *ptr = NULL;
    double ret = 0;
    int i = 0;
    while (fgets(line, MAX_LINE, in_file) != NULL)
    {
        for (str = strtok(line, "\t\n"); str != NULL; str = strtok(NULL, "\t\n"))
        {
            ConvertCommaToDot(str);
            ret = strtod(str, &ptr);
    #if DEBUG
            printf("double value is: %0.5f\n", ret);
    #endif
            p_in[i++] = ret;
    #if DEBUG
            printf("new double value is: %0.5f\n", ret);
            printf("---------------\n");
    #endif
        }
    }

    fclose(in_file);
}

void WriteFile(const char* file_name, double* data_to_write, size_t size)
{
    FILE *out_file;
    out_file = fopen(file_name, "w");

    if (out_file == NULL)
    {
        printf("%s doesn't open.", file_name);
    }
    else
    {

    printf("The file is opened.\n");
    
    for(int i=0;i<size;i++){
        if (size > 0)
        {
            fprintf(out_file, "%lf\n", data_to_write[i]);

        }
        else{
            printf("Input buffer is empty!!\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(out_file);

    printf("Data successfully written in file %s\n", file_name);
    printf("The file is closed.");
  }
}
