#include "metric_convertor.h"

int conversion_function (conversion_parameter* (ith_parameter_struct), double input_value, int output_index, double conversion_factor_array, unit_info *units_struct){
    ith_parameter_struct->unit = (units_struct + output_index);
    ith_parameter_struct->conversion_factor = conversion_factor_array;
    ith_parameter_struct->calculated_output = input_value * (ith_parameter_struct->conversion_factor);

    return 0;
 }