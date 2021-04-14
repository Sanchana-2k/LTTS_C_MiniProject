#include <stdio.h>
#include <stdlib.h>
#include "metric_convertor.h"

unit_info length_units[4] = {{"meter", "m"}, {"centimeter", "cm"}, {"foot", "'"}, {"inches", "\""}};

double convo_val[4][4] = {{1.0, 100.0, 3.28084, 39.3701}, 
                            {0.01, 1, 0.0328084, 0.393701},
                            {0.304800164592, 30.48, 1, 12},
                            {0.0254, 2.54, 0.0833333, 1}};

void convo_func (conversion_parameter* (length_convo_i), double ip_val, int op_index_1, double *convo_buffer);


    void convertor(conversion_parameter *length_convo, int ip_index, double ip_val, int op_num, int *op_index){
        double *convo_buffer = convo_val[ip_index-1];

        for (int i=0; i<op_num; i++){
            convo_func ((length_convo+i), ip_val, op_index[i]-1, convo_buffer);
        }

    }
    
    void convo_func (conversion_parameter* (length_convo_i), double ip_val, int op_index_1, double *convo_buffer){
        length_convo_i->unit = (length_units + op_index_1);
        length_convo_i->conversion_factor = convo_buffer[op_index_1];
        length_convo_i->calculated_output = ip_val * length_convo_i->conversion_factor;
    }

    