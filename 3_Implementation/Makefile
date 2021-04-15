##all: test.exe
##	test.exe

##test.exe: new_main.c length_convo_with_file.c file_array_extraction.c conversion_function.c table_output.c
##	gcc new_main.c length_convo_with_file.c file_array_extraction.c conversion_function.c table_output.c -o test.exe

# Name of the project
PROJECT_NAME = metric_conversion_calc

# Output directory
BUILD = build

# All source code files
SRC = metric_convertor_main.c\
src\quantity_data.c\
src\file_array_extraction.c\
src\conversion_function.c\
src\table_output.c

# All include folders with header files
INC	= -Iinc

# Project Output name
PROJECT_OUTPUT = $(BUILD)\$(PROJECT_NAME).exe

# Default target built
$(PROJECT_NAME):all

# Run the target even if the matching name exists
.PHONY: run clean test doc all

all: $(SRC) $(BUILD)
	gcc $(SRC) $(INC) -o $(PROJECT_OUTPUT)

# Call `make run` to run the application
run:$(PROJECT_NAME)
	.\$(PROJECT_OUTPUT)
