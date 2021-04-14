#include <stdio.h>
#include "metric_convertor.h"

void print_output_table(conversion_parameter* length_convo, int op_num){

    printf("\n");
    printf("  +----------------------+----------------------+----------------------+----------------------+\n");
    printf("  | %-20s | %-20s | %-20s | %-20s |\n", "Unit Name", "Conversion Factor", "Output Value", "Unit Symbol");
    printf("  +----------------------+----------------------+----------------------+----------------------+\n");

    for (int i=0; i<op_num; i++){

        printf("  | %-20s | %-20f | %-20f | %-20s |\n", length_convo[i].unit->name, length_convo[i].conversion_factor, length_convo[i].calculated_output, length_convo[i].unit->symbol);

    }
    printf("  +----------------------+----------------------+----------------------+----------------------+\n");

}