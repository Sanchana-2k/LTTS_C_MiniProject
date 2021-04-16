/**
 * @file metric_convertor.h
 * @author S Sanchana
 * @brief Contains all the declarations required for metric conversion
 * @version 0.1
 * @date 2021-04-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/* Header Guard */
#ifndef __METRIC_CONVERTOR_H__
#define __METRIC_CONVERTOR_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Structure definition for unit name and its symbol
 * 
 */
typedef struct{
    char name[20];
    char symbol[10];
} unit_info;

/**
 * @brief Structure Definition for values required for conversion
 * 
 */
typedef struct{
    unit_info *unit;
    double conversion_factor;
    double calculated_output; 
} conversion_parameter;

/**
 * @brief prints length options
 * 
 * @return int 
 */
int length_options();

/**
 * @brief prints area options
 * 
 * @return int 
 */
int area_options();

/**
 * @brief prints volume options
 * 
 * @return int 
 */
int volume_options();

/**
 * @brief prints mass options
 * 
 * @return int 
 */
int mass_options();

/**
 * @brief prints speed options
 * 
 * @return int 
 */
int speed_options();

/**
 * @brief Functions calls the file extaction function to extact the array of conversion factors and 
 * calls the conversion function to convert the input value to appropriate output 
 * 
 * @param choice 
 * @param conversion_parameter_array 
 * @param index_of_input 
 * @param input_value 
 * @param number_of_conversions 
 * @param array_of_output_index 
 * @return int 
 */
int quantity_convertor(int choice, conversion_parameter *conversion_parameter_array, int index_of_input, double input_value, int number_of_conversions, int *array_of_output_index);

/**
 * @brief Extracts the array of conversion factors form the file corresponding to the input index
 * 
 * @param file_name 
 * @param index_of_input 
 * @param conversion_factor_array 
 * @return int 
 */
int conversion_factors_from_file (char *file_name, int index_of_input, double *conversion_factor_array);

/**
 * @brief Functions takes the input value and converts to the output based on the appropriate conversion factor 
 * 
 * @param ith_parameter_struct 
 * @param input_value 
 * @param output_index 
 * @param ith_conversion_factor 
 * @param units_struct 
 * @return int 
 */
int conversion_function (conversion_parameter* ith_parameter_struct, double input_value, int output_index, double ith_conversion_factor, unit_info *units_struct);

/**
 * @brief prints output in the form of a table
 * 
 * @param array_of_parameters 
 * @param number_of_output 
 * @return int 
 */
int print_output_table(conversion_parameter* array_of_parameters, int number_of_output);

#endif