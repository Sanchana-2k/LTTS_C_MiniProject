#include "metric_convertor.h"

// function to convert the value to the specified type (index of output) from the input type (index of input) 
// based on the conversion factor value 
// and store the required values in the conversion parameter array
int conversion_function (conversion_parameter* ith_parameter_struct, double input_value, int output_index, double ith_conversion_factor, unit_info *units_struct){
    // store the unit info of the output type
    ith_parameter_struct->unit = (units_struct + output_index);
    // store the connvertion factor from input type to output type
    ith_parameter_struct->conversion_factor = ith_conversion_factor;
    // calculate the converted value and store the result
    ith_parameter_struct->calculated_output = input_value * (ith_parameter_struct->conversion_factor);

    return 0;
 }