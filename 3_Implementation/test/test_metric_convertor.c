#include "unity.h"
#include "unity_internals.h"
#include "metric_convertor.h"


#define PROJECT_NAME    "metric_conversion_calc"

/* Prototypes for all the test functions */
void test_length_options(void);
void test_area_options(void);
void test_volume_options(void);
void test_mass_options(void);
void test_speed_options(void);
void test_quantity_convertor(void);
void test_conversion_factors_from_file(void);
void test_conversion_function(void);
void test_print_output_table(void);

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_length_options);
  RUN_TEST(test_area_options);
  RUN_TEST(test_volume_options);
  RUN_TEST(test_mass_options);
  RUN_TEST(test_speed_options);
  RUN_TEST(test_quantity_convertor);
  RUN_TEST(test_conversion_factors_from_file);
  RUN_TEST(test_conversion_function);
  RUN_TEST(test_print_output_table);
  //RUN_TEST(test_divide);

  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */ 
void test_length_options(void) {
  TEST_ASSERT_EQUAL(0,length_options());
}

void test_area_options(void) {
  TEST_ASSERT_EQUAL(0,area_options());
}

void test_volume_options(void) {
  TEST_ASSERT_EQUAL(0,volume_options());
}

void test_mass_options(void) {
  TEST_ASSERT_EQUAL(0,mass_options());
}

void test_speed_options(void) {
  TEST_ASSERT_EQUAL(0,speed_options());
}

void test_quantity_convertor(void){
  /* NOTE:
   * The range guard in the while loop does not allow any of the parameter
   * to be beyond the range of 1 to 5
   */ 

  //choice 1: length
  int choice_of_quantity = 1;
  int index_of_input = 1;
  int number_of_output_conversions = 1, array_of_output_index[1] = {2};

  double input_value = 5;


  conversion_parameter* array_of_conversion_parameters = ((conversion_parameter *) malloc(number_of_output_conversions*sizeof(conversion_parameter)));

  TEST_ASSERT_EQUAL(0, quantity_convertor(choice_of_quantity, array_of_conversion_parameters, index_of_input, input_value, number_of_output_conversions, array_of_output_index));
  TEST_ASSERT_EQUAL(100.0, array_of_conversion_parameters[0].conversion_factor);
  TEST_ASSERT_EQUAL(500.0, array_of_conversion_parameters[0].calculated_output);


  //choice 2 : Area
  choice_of_quantity = 2;

  TEST_ASSERT_EQUAL(0, quantity_convertor(choice_of_quantity, array_of_conversion_parameters, index_of_input, input_value, number_of_output_conversions, array_of_output_index));
  TEST_ASSERT_EQUAL(10000, array_of_conversion_parameters[0].conversion_factor);
  TEST_ASSERT_EQUAL(50000, array_of_conversion_parameters[0].calculated_output);

  //choice 3 : Volume
  choice_of_quantity = 3;

  TEST_ASSERT_EQUAL(0, quantity_convertor(choice_of_quantity, array_of_conversion_parameters, index_of_input, input_value, number_of_output_conversions, array_of_output_index));
  TEST_ASSERT_EQUAL(1000000, array_of_conversion_parameters[0].conversion_factor);
  TEST_ASSERT_EQUAL(5000000, array_of_conversion_parameters[0].calculated_output);

  //choice 4 : Mass
  choice_of_quantity = 4;

  TEST_ASSERT_EQUAL(0, quantity_convertor(choice_of_quantity, array_of_conversion_parameters, index_of_input, input_value, number_of_output_conversions, array_of_output_index));
  TEST_ASSERT_EQUAL(1000, array_of_conversion_parameters[0].conversion_factor);
  TEST_ASSERT_EQUAL(5000, array_of_conversion_parameters[0].calculated_output);

  //choice 5 : Speed
  choice_of_quantity = 5;

  TEST_ASSERT_EQUAL(0, quantity_convertor(choice_of_quantity, array_of_conversion_parameters, index_of_input, input_value, number_of_output_conversions, array_of_output_index));
  TEST_ASSERT_EQUAL(3.6, array_of_conversion_parameters[0].conversion_factor);
  TEST_ASSERT_EQUAL(18, array_of_conversion_parameters[0].calculated_output);

  free(array_of_conversion_parameters);

}

void test_conversion_factors_from_file(void){
  char test_file_name[50];
  strcpy(test_file_name, "length_conversion_factor_table.csv");
  int index_of_input = 1;
  double *conversion_factors_array = (double *) malloc(5*sizeof(double));
  TEST_ASSERT_EQUAL(0,conversion_factors_from_file (test_file_name, index_of_input, conversion_factors_array));
  TEST_ASSERT_EQUAL(100.0, conversion_factors_array[1]);
  
  strcpy(test_file_name,".\\src\\xyz.csv");
  TEST_ASSERT_EQUAL(1,conversion_factors_from_file (test_file_name, index_of_input, conversion_factors_array));

  free(conversion_factors_array);
}

void test_conversion_function(void){
  conversion_parameter test_parameter;
  int input_value = 5, output_index = 0, test_conversion_factor = 100.0;
  unit_info test_units[1] = {{"meter", "m"}};
  TEST_ASSERT_EQUAL(0, conversion_function (&test_parameter, input_value, output_index, test_conversion_factor, test_units));
  TEST_ASSERT_EQUAL(test_units+0, test_parameter.unit);
  TEST_ASSERT_EQUAL(100.0, test_parameter.conversion_factor);
  TEST_ASSERT_EQUAL(500.0, test_parameter.calculated_output);
}

void test_print_output_table(void) {
  unit_info test_units[1] = {{"meter", "m"}};
  conversion_parameter test_parameter_array[1];
  test_parameter_array[0].unit =  (test_units+0);
  test_parameter_array[0].conversion_factor = 0.01;
  test_parameter_array[0].calculated_output = 1;

  int number_of_output = 1;

  TEST_ASSERT_EQUAL(0, print_output_table(test_parameter_array, number_of_output));
}

