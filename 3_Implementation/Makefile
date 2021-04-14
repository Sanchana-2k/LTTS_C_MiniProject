all: test.exe
	test.exe

test.exe: metric_convertor_main.c length_convo_with_file.c file_array_extraction.c conversion_function.c table_output.c
	gcc metric_convertor_main.c length_convo_with_file.c file_array_extraction.c conversion_function.c table_output.c -o test.exe

##test.exe: metric_convertor_main.c length_conversion.c table_output.c
##	gcc metric_convertor_main.c length_conversion.c table_output.c -o test.exe