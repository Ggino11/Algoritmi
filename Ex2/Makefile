# Compiler
CC = gcc

# Directories
INCLUDE_DIRS = -I./include -I./tests
SRC_DIR = src
TEST_DIR = tests
BIN_DIR = bin
DATA_DIR = data

# Source Files
SRC_FILES = $(SRC_DIR)/main_ex2.c $(SRC_DIR)/edit_distance.c $(SRC_DIR)/file_utils.c 
# Tests Files
TEST_FILES = $(TEST_DIR)/tests.c  $(SRC_DIR)/edit_distance.c $(SRC_DIR)/file_utils.c $(TEST_DIR)/unity.c

# Compiler Flags
CFLAGS = -Wall -Wextra -g $(INCLUDE_DIRS)

# Targets
all: $(BIN_DIR)/main_ex2 $(BIN_DIR)/test_ex2

$(BIN_DIR)/main_ex2: $(SRC_FILES) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/main_ex2 $(SRC_FILES)

$(BIN_DIR)/test_ex2: $(TEST_FILES) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/test_ex2 $(TEST_FILES)

# Ensure bin directory exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean rule to remove all compiled binaries
clean:
	rm -f $(BIN_DIR)/*


