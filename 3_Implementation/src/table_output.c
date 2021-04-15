#include <stdio.h>
#include "metric_convertor.h"

int print_output_table(conversion_parameter* array_of_parameters, int number_of_output){

    printf("\n");
    printf("  +----------------------+----------------------+----------------------+----------------------+\n");
    printf("  | %-20s | %-20s | %-20s | %-20s |\n", "Unit Name", "Conversion Factor", "Output Value", "Unit Symbol");
    printf("  +----------------------+----------------------+----------------------+----------------------+\n");

    for (int i=0; i<number_of_output; i++){

        printf("  | %-20s | %-20lf | %-20lf | %-20s |\n", array_of_parameters[i].unit->name, array_of_parameters[i].conversion_factor, array_of_parameters[i].calculated_output, array_of_parameters[i].unit->symbol);

    }
    printf("  +----------------------+----------------------+----------------------+----------------------+\n");

    return 0;
}