#include "metric_convertor.h"

// Create a function pointer array for calling the respective function to print the options for each quantity
int (*quantity_options[5])() = {length_options, area_options, volume_options, mass_options, speed_options};

int main(){
    // Printing Introduction
    printf("\n");
    printf("********************************************************************************************\n");
    printf("\n");
    printf("\t\t Metric Conversion Calculator\n");
    printf("\t\t ============================\n");

    // while true loop to make the program run repeatedly until exited explicitly
    while(1){
        // Printing quantity options
        printf("\n");
        printf("\t Choose the type of quantity you would like to convert:\n");
        printf("\n");
        printf("%-35s %s", "  1. Length/Distance","4. Mass\n");
        printf("%-35s %s", "  2. Area","5. Speed\n");
        printf("%-35s %s", "  3. Volume","6. Exit\n");
        printf("\n");
        printf("Enter your choice: ");

        // variable to store index of choice of the quantity
        int choice_of_quantity;

        // ERROR HANDLING - To avoid infinite loop if accidentally char is entered instead of int for choice_of_quantity
        
        char user_choice[25]; // Define temporary variable to get choice as string

        fseek(stdin,0,SEEK_END); // flush the stdin so that it does not consider \n from previous input

        fgets (user_choice, 25, stdin); // get the choice value from user as string

        // check if the choice is within the range
        // else: ask to re-enter and go to start of loop
        if (*user_choice < '1' || *user_choice > '6' || *(user_choice+1)!='\n') {
            printf("Entered value is out of range, value must be between 1 and 6\n");
            printf("Kindly re-enter the values\n");
            continue;
        }

        // store the value as int in choice_of_quantity if the input is valid (within the range 1 to 6)
        choice_of_quantity = *user_choice - '0';

        // initialize required variables for conversion
        int index_of_input = 0, number_of_output_conversions = 0, *array_of_output_index = NULL;
        
        // if one of the conversion is chosen i.e., between 1 and 5(not 6 - exit)
        if (choice_of_quantity >= 1 && choice_of_quantity <= 5){
             
             // to display the options repeatedly until a valid values are entered
             while(1){
               
               // ERROR HANDLING - To avoid infinite loop if accidentally char is entered instead of int for quantity_options
               
               char user_input[25]; // Define temporary variable to get choice as string

                quantity_options[choice_of_quantity-1](); // print the respective quantity option based on choice using function pointer array

                printf("Enter the index of your input type: ");

                fseek(stdin,0,SEEK_END); // flush the stdin so that it does not consider \n from previous input

                fgets (user_input, 25, stdin); // get the input index value from user as string

                // check if the input index is within the range
                // else: ask to re-enter and go to start of loop
                if (*user_input < '1' || *user_input > '5' || *(user_input+1)!='\n') {
                    printf("Entered value is out of range, value must be between 1 and 5\n");
                    printf("Kindly re-enter the values\n");
                    continue;
                }

                // store the value as int in index_of_input if the input is valid (within the range 1 to 5)
                index_of_input = *user_input - '0';

                printf("Enter the number of options to which you would like to convert: ");

                fgets (user_input, 25, stdin); // get the number of options value from user as string

                // check if the number of conversions is <= number of options
                // else: ask to re-enter and go to start of loop
                if (*user_input < '1' || *user_input > '5' || *(user_input+1)!='\n') {
                    printf("Number of conversions cannot be more than 5, value must be between 1 and 5\n");
                    printf("Kindly re-enter the values\n");
                    continue;
                }

                // store the value as int in number_of_output_conversions if the input is valid (within the range 1 to 5)
                number_of_output_conversions = *user_input - '0';

                // initialize an array for storing the index of output
                array_of_output_index = (int *)malloc(number_of_output_conversions*sizeof(int));

                // initialize a flag that goes high if the index is out of range (1 to 5)
                int flag = 0;

                // loop to get each of the index of the output to be stored in the array
                for (int i=0; i<number_of_output_conversions; i++){
                    printf("Enter the index of output type: ");
                    fgets (user_input, 25, stdin); // get the output index value from user as string

                    // check if the output indices are within the range
                    // else: raise the flag and break the for loop
                    if (*user_input < '1' || *user_input > '5' || *(user_input+1)!='\n') {
                        printf("Entered value is out of range, value must be between 1 and 5\n");
                        printf("Kindly re-enter the values\n");
                        flag++;
                        break;
                    }

                // if the output index is valid, then store it in an array
                array_of_output_index[i] = *user_input - '0';
                }

                // if flag is high i.e., if one of the output index is out of range
                // go to the start of the loop -> print options and get all the values (input index, number of conversions, etc.) again
                if (flag != 0){
                    continue;
                }

                // if all the input options are valid then break the inner while loop and go ahead
                break;
            }
        }

        // if choice is 6 (exit), then print the message and exit the program by breaking the while loop
        else if (choice_of_quantity == 6){
            printf("\n");
            printf("Thank you for using our application.!! Hope you liked it. :)\n");
            break;
        }

        // initialize and get the value to be converted as double
        double input_value = 0;
        while (1){
            input_value = 0;
            printf("Enter Input Value to be Converted: ");

            // initialize a dummy string to get input value as string
            char input_val_str[100] = "";
            fgets(input_val_str, 100, stdin);

            // try to convert the string to double
            if (sscanf(input_val_str, "%lf", &input_value) == 1){
                // if possible, then check if input is positive
                if (input_value>=0){
                    break;
                }
                else{
                    // if input is negative ask to re-enter
                    printf("metric value cannot be negative, kindly re-enter a valid value\n");
                    printf("\n");
                }
            }
            else{
                // if input cannot be converted to string (say input is char), then ask to re-enter
                printf("input is not an floating point value, kindly re-enter a valid value\n");
                printf("\n");
            }
        }

        // initialize an array to store the result in conversion parameter array
        conversion_parameter* array_of_conversion_parameters = ((conversion_parameter *) malloc(number_of_output_conversions*sizeof(conversion_parameter)));

        // call the function to convert and store the result in array_of_conversion_parameters
        quantity_convertor(choice_of_quantity, array_of_conversion_parameters, index_of_input, input_value, number_of_output_conversions, array_of_output_index);
        
        // call the function to print the output in table form
        print_output_table(array_of_conversion_parameters, number_of_output_conversions);

        // free the memory allocated dynamically
        free(array_of_output_index);
        free(array_of_conversion_parameters);

        }

    return 0;
}
