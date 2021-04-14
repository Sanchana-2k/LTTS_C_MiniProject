#include <stdio.h>
#include <stdlib.h>
#include "metric_convertor.h"

int main(){
    printf("\n");
    printf("********************************************************************************************\n");
    printf("\n");
    printf("\t\t Metric Conversion Calculator\n");
    printf("\t\t ============================\n");
    printf("\n");
    printf("\t Choose the type of quantity you would like to convert:\n");
    printf("\n");
    printf("%-35s %s","  1. Length/Distance","4. Mass\n");
    printf("%-35s %s","  2. Area","5. Speed\n");
    printf("%-35s %s","  3. Volume","6. Time\n");

    int ip_index = 3, op_num = 2, op_index[2] = {1,4};
    double ip_val = 5;

    conversion_parameter* length_convo = ((conversion_parameter *) malloc(op_num*sizeof(conversion_parameter)));

    convertor(length_convo, ip_index, ip_val, op_num, op_index);

    print_output_table(length_convo, op_num);


    /*
    printf("\n");
    printf("  +----------------------+----------------------+----------------------+----------------------+\n");
    printf("  | %-20s | %-20s | %-20s | %-20s |\n", "Unit Name", "Conversion Factor", "Output Value", "Unit Symbol");
    printf("  +----------------------+----------------------+----------------------+----------------------+\n");

    for (int i=0; i<op_num; i++){

        printf("  | %-20s | %-20f | %-20f | %-20s |\n", length_convo[i].unit->name, length_convo[i].conversion_factor, length_convo[i].calculated_output, length_convo[i].unit->symbol);
    }

    printf("  +----------------------+----------------------+----------------------+----------------------+\n");

    */

    return 0;
}