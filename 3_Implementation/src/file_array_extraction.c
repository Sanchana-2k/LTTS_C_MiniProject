#include "metric_convertor.h"

int conversion_factors_from_file (char *file_name, int index_of_input, double *conversion_factor_array){

    FILE *file_pointer = fopen(file_name,"r");

    if (file_pointer == NULL){
        printf("Cant open file\n");
        return 1;
    }

    char temporary_buffer[1024], *token, *eptr;

    for (int i=0; i<index_of_input; i++){
        fgets(temporary_buffer, 1024, file_pointer);
    }

    token = strtok(temporary_buffer,",");
    conversion_factor_array[0] = strtod(token, &eptr);
    for (int i=1; i<5; i++){
        token = strtok(NULL,",");
        conversion_factor_array[i] = strtod(token, &eptr);
    }
    fclose(file_pointer);
    return 0;

}