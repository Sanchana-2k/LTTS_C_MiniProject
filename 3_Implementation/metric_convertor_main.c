#include "metric_convertor.h"

int (*quantity_options[5])() = {length_options, area_options, volume_options, mass_options, speed_options};

int main(){
    printf("\n");
    printf("********************************************************************************************\n");
    printf("\n");
    printf("\t\t Metric Conversion Calculator\n");
    printf("\t\t ============================\n");
    while(1){
        printf("\n");
        printf("\t Choose the type of quantity you would like to convert:\n");
        printf("\n");
        printf("%-35s %s", "  1. Length/Distance","4. Mass\n");
        printf("%-35s %s", "  2. Area","5. Speed\n");
        printf("%-35s %s", "  3. Volume","6. Exit\n");
        printf("\n");
        printf("Enter your choice: ");

        int choice_of_quantity;

        char user_choice[5];

        fseek(stdin,0,SEEK_END);

        fgets (user_choice, 5, stdin);

        if (*user_choice < '1' || *user_choice > '6') {
            printf("Entered value is out of range, value must be between 1 and 6\n");
            printf("Kindly re-enter the values\n");
            continue;
        }

        choice_of_quantity = *user_choice - '0';

        int index_of_input = 0, number_of_output_conversions = 0, *array_of_output_index = NULL;
        

        if (choice_of_quantity >= 1 && choice_of_quantity <= 5){
             
             while(1){
               
               char user_input[5];

                quantity_options[choice_of_quantity-1]();

                printf("Enter the index of your input type: ");

                fseek(stdin,0,SEEK_END);

                fgets (user_input, 5, stdin);

                if (*user_input < '1' || *user_input > '5') {
                    printf("Entered value is out of range, value must be between 1 and 5\n");
                    printf("Kindly re-enter the values\n");
                    continue;
                }

                index_of_input = *user_input - '0';

                printf("Enter the number of options to which you would like to convert: ");

                fgets (user_input, 5, stdin);

                if (*user_input < '1' || *user_input > '5') {
                    printf("Number of conversions cannot be more than 5, value must be between 1 and 5\n");
                    printf("Kindly re-enter the values\n");
                    continue;
                }

                number_of_output_conversions = *user_input - '0';


                array_of_output_index = (int *)malloc(number_of_output_conversions*sizeof(int));

                int flag = 0;

                for (int i=0; i<number_of_output_conversions; i++){
                    printf("Enter the index of output type: ");
                    fgets (user_input, 5, stdin);

                    if (*user_input < '1' || *user_input > '5') {
                        printf("Entered value is out of range, value must be between 1 and 5\n");
                        printf("Kindly re-enter the values\n");
                        flag++;
                        break;
                    }

                array_of_output_index[i] = *user_input - '0';
                }

                if (flag != 0){
                    continue;
                }

                break;
            }
        }

        else if (choice_of_quantity == 6){
            printf("\n");
            printf("Thank you for using our application.!! Hope you liked it. :)\n");
            break;
        }

        double input_value = 0;
        printf("Enter Input Value to be Converted: ");
        scanf("%lf",&input_value);
        if (input_value<0){
        	printf("\n");
        	printf("NOTE: Since input value is negative, considering the absolute value of the input\n");
        	input_value = -1*input_value;	
        }

        conversion_parameter* array_of_conversion_parameters = ((conversion_parameter *) malloc(number_of_output_conversions*sizeof(conversion_parameter)));

        quantity_convertor(choice_of_quantity, array_of_conversion_parameters, index_of_input, input_value, number_of_output_conversions, array_of_output_index);
        
        print_output_table(array_of_conversion_parameters, number_of_output_conversions);

        free(array_of_output_index);
        free(array_of_conversion_parameters);

        }

    return 0;
}
