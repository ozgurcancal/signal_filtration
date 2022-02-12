#include "fileHandler.h"
#include "utilities.h"


void GetFileValues(const char* fileName, double *p_in)
{
    FILE *in_file;

    if ((in_file = fopen(fileName, "r")) == NULL)
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

void WriteFile(const char* fileName, double* dataToBeWritten, size_t size)
{
    FILE *out_file;
    out_file = fopen(fileName, "w");

    if (out_file == NULL)
    {
        printf("%s doesn't open.", fileName);
    }
    else
    {

    printf("The file is opened.\n");
    
    for(int i=0;i<size;i++){
        if (size > 0)
        {
            fprintf(out_file, "%lf\n", dataToBeWritten[i]);

        }
        else{
            printf("Input buffer is empty!!\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(out_file);

    printf("Data successfully written in file %s\n", fileName);
    printf("The file is closed.");
  }
}
