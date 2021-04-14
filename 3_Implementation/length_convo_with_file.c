#include <stdio.h>
#include <stdlib.h>

#include "metric_convertor.h"

unit_info length_units[4] = {{"meter", "m"}, {"centimeter", "cm"}, {"foot", "'"}, {"inches", "\""}};

char length_file_name[40] = "length_convo_factor_table.txt";

void convertor(conversion_parameter *length_convo, int ip_index, double ip_val, int op_num, int *op_index){
    double *convo_buffer = (double *) malloc(4*sizeof(double));

    file_to_double_array (length_file_name, ip_index, convo_buffer);

    for (int i=0; i<op_num; i++){
        convo_func ((length_convo+i), ip_val, op_index[i]-1, convo_buffer, length_units);
    }

}

