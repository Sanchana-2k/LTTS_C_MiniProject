# Name of the project
PROJ_NAME = metric_conversion_calc
TEST_PROJ_NAME = Test_$(PROJ_NAME)

# Output directory
BUILD_DIR = build

# Main file name
MAIN_NAME = metric_convertor_main.c

# All source code files
SRC = src/quantity_data.c\
src/file_array_extraction.c\
src/conversion_function.c\
src/table_output.c


# All test source files
TEST_SRC = test/test_metric_convertor.c\
unity/unity.c

# All include folders with header files
INC = -Iinc\
-Iunity

# All include folders for cppcheck
CPPCHECK_INC = -Iinc src

#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
ifdef OS
   MOVE = move
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
	  MOVE = mv
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

# Makefile will not run target command if the name with file already exists. To override, use .PHONY
.PHONY : all test coverage run clean doc

all:$(BUILD_DIR)
	gcc $(MAIN_NAME) $(SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

run: all
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

test: $(SRC) $(TEST_SRC) $(BUILD_DIR)
	gcc $(SRC) $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))

coverage:${PROJECT_NAME} $(BUILD_DIR)
	gcc -fprofile-arcs -ftest-coverage $(SRC) $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
#gcc -fprofile-arcs -ftest-coverage $(SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	$(MOVE) *.gcno src
	$(MOVE) *.gcda src
	gcov -a $(SRC)
	$(RM) $(call FixPath,src/*.gcda)
	$(RM) $(call FixPath,src/*.gcno)

doc:
	make -C doc

$(BUILD_DIR):
	mkdir $(BUILD_DIR)
	
cppcheck:
	cppcheck --enable=all $(CPPCHECK_INC) *.c
	
valgrind_main: all
	valgrind $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))
	
valgrind_test: $(SRC) $(TEST_SRC) $(BUILD_DIR)
	gcc $(SRC) $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	valgrind $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	

clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/*)
	make clean -C doc
	rmdir $(BUILD_DIR) doc/html
