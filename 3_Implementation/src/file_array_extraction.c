#include "metric_convertor.h"

// function to extract the specific array from the csv file based on input type
int conversion_factors_from_file (char *file_name, int index_of_input, double *conversion_factor_array){

    // open the file
    FILE *file_pointer = fopen(file_name,"r");

    // if file does not open properly, return 1
    if (file_pointer == NULL){
        printf("Cant open file\n");
        return 1;
    }

    // create a temporary character buffer
    char temporary_buffer[1024], *token, *eptr;

    // till index_of_input, keep updating the temporary buffer with each row of conversion factors
    // so that at the end of iteration, the temporary buffer will have the row of conversion factors of the input type (index_of_input)
    for (int i=0; i<index_of_input; i++){
        fgets(temporary_buffer, 1024, file_pointer);
    }

    // having comma as delimiter, seperate each value and store in the conversion_factor_array
    token = strtok(temporary_buffer,",");
    conversion_factor_array[0] = strtod(token, &eptr);
    for (int i=1; i<5; i++){
        token = strtok(NULL,",");
        conversion_factor_array[i] = strtod(token, &eptr);
    }
    // close the file
    fclose(file_pointer);
    return 0;

}