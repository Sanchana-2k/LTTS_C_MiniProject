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
 * @brief 
 * 
 * @param length_convo 
 * @param ip_index 
 * @param ip_val 
 * @param op_num 
 * @param op_index 
 */
void convertor(conversion_parameter *length_convo, int ip_index, double ip_val, int op_num, int *op_index);

/**
 * @brief 
 * 
 * @param ip_val 
 * @param op_index_1 
 * @param convo_buffer 
 * @param length_units 
 */
void convo_func (conversion_parameter* (length_convo_i), double ip_val, int op_index_1, double *convo_buffer, unit_info *length_units);

/**
 * @brief 
 * 
 * @param length_convo 
 * @param op_num 
 */
void print_output_table(conversion_parameter* length_convo, int op_num);

/**
 * @brief 
 * 
 * @param file_name 
 * @param ip_index 
 * @param convo_buffer 
 */
void file_to_double_array (char *file_name, int ip_index, double *convo_buffer);


#endif