#include "metric_convertor.h"

unit_info length_units[5] = {{"meter", "m"}, {"centimeter", "cm"}, 
                            {"foot", "ft. or '"}, {"inches", "\""}, {"millimeter","mm"}};


char length_file_name[50] = "length_conversion_factor_table.csv";

unit_info area_units[5] = {{"square meters", "sq. m"}, {"square centimeter", "sq. cm"}, 
                            {"square foot", "sq. ft."}, {"square inches", "sq. in."}, {"square yard","sq. yd"}};

char area_file_name[50] = "area_conversion_factor_table.csv";

unit_info volume_units[5] = {{"cubic meters", "cu. m"}, {"cubic centimeter", "cu. cm"}, 
                            {"litres", "l"}, {"milli litres", "ml"}, {"gallons (imperial)","gal"}};

char volume_file_name[50] = "volume_conversion_factor_table.csv";

unit_info mass_units[5] = {{"Kilo grams", "kg"}, {"grams", "g"}, 
                            {"ounce", "oz"}, {"tonne", "t"}, {"pound","lbs"}};

char mass_file_name[50] = "mass_conversion_factor_table.csv";

unit_info speed_units[5] = {{"meters per second", "m/s"}, {"kilometers per hour", "km/h"}, 
                            {"miles per hour", "mi/h"}, {"foot per second", "ft/s"}, {"knot","kn"}};

char speed_file_name[50] = "speed_conversion_factor_table.csv";



int length_options(){
    printf("\n");
    printf("\t Available choice for interconversion:\n");
    printf("\n");
    printf("%-35s %s","  1. meter","4. inches\n");
    printf("%-35s %s","  2. centimeter","5. millimeter\n");
    printf("%s","  3. foot\n");
    printf("\n");

    return 0;
}

int area_options(){
    printf("\n");
    printf("\t Available choice for interconversion:\n");
    printf("\n");
    printf("%-35s %s","  1. square meters","4. square inches\n");
    printf("%-35s %s","  2. square centimeter","5. square yard\n");
    printf("%s","  3. square foot\n");
    printf("\n");

    return 0;
}

int volume_options(){
    printf("\n");
    printf("\t Available choice for interconversion:\n");
    printf("\n");
    printf("%-35s %s","  1. cubic meters","4. milli litres\n");
    printf("%-35s %s","  2. cubic centimeter","5. gallons (imperial)\n");
    printf("%s","  3. litres\n");
    printf("\n");

    return 0;
}

int mass_options(){
    printf("\n");
    printf("\t Available choice for interconversion:\n");
    printf("\n");
    printf("%-35s %s","  1. Kilo grams","4. tonne\n");
    printf("%-35s %s","  2. grams","5. pound\n");
    printf("%s","  3. ounce\n");
    printf("\n");

    return 0;
}

int speed_options(){
    printf("\n");
    printf("\t Available choice for interconversion:\n");
    printf("\n");
    printf("%-35s %s","  1. meters per second","4. foot per second\n");
    printf("%-35s %s","  2. kilometers per hour","5. knot\n");
    printf("%s","  3. miles per hour\n");
    printf("\n");

    return 0;
}



int quantity_convertor(int choice, conversion_parameter *conversion_parameter_array, int index_of_input, double input_value, int number_of_conversions, int *array_of_output_index){
    
    char *conversion_factor_file;
    unit_info *quantity_units_data;
    
    if (choice == 1){
        conversion_factor_file= length_file_name;
        quantity_units_data = length_units;     
    }
    else if (choice == 2){
        conversion_factor_file = area_file_name;
        quantity_units_data = area_units;     
    }
    else if (choice == 3){
        conversion_factor_file = volume_file_name;
        quantity_units_data = volume_units;     
    }
    else if (choice == 4){
        conversion_factor_file = mass_file_name;
        quantity_units_data = mass_units;     
    }
    else if (choice == 5){
        conversion_factor_file = speed_file_name;
        quantity_units_data = speed_units;     
    }

    double *conversion_factors_array = (double *) malloc(5*sizeof(double));

    conversion_factors_from_file (conversion_factor_file, index_of_input, conversion_factors_array);

    for (int i=0; i<number_of_conversions; i++){
        conversion_function ((conversion_parameter_array+i), input_value, array_of_output_index[i]-1, conversion_factors_array[array_of_output_index[i]-1], quantity_units_data);
    }
    free(conversion_factors_array);

    return 0;

}


