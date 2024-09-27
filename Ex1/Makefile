
# Compiler
CC = gcc

# Directories
INCLUDE_DIRS = -I./include -I./tests
SRC_DIR = src
TEST_DIR = tests
BIN_DIR = bin

# Source Files
SRC_FILES = $(SRC_DIR)/main_ex1.c $(SRC_DIR)/mergeSort.c $(SRC_DIR)/quickSort.c $(SRC_DIR)/comparator.c $(SRC_DIR)/sort_records.c
TEST_FILES = $(TEST_DIR)/tests.c $(SRC_DIR)/quickSort.c $(SRC_DIR)/comparator.c $(SRC_DIR)/sort_records.c $(SRC_DIR)/mergeSort.c $(TEST_DIR)/unity.c

# Compiler Flags
CFLAGS = -g $(INCLUDE_DIRS)

# Targets
all: main_ex1 test_ex1

main_ex1: $(SRC_FILES)
	 $(CC) $(CFLAGS) -o $(BIN_DIR)/main_ex1 $(SRC_FILES)

test_ex1: $(TEST_FILES)
	 $(CC) $(CFLAGS) -o $(BIN_DIR)/test_ex1 $(TEST_FILES)

# clean removes all compiled binaries to clean the directory
clean:
	 del /Q bin\*
