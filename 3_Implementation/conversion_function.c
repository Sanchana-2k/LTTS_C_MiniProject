#include "metric_convertor.h"

void convo_func (conversion_parameter* (length_convo_i), double ip_val, int op_index_1, double *convo_buffer, unit_info *length_units){
        length_convo_i->unit = (length_units + op_index_1);
        length_convo_i->conversion_factor = convo_buffer[op_index_1];
        length_convo_i->calculated_output = ip_val * length_convo_i->conversion_factor;
    }