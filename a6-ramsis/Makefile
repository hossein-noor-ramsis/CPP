# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++20 -O2 -Iinclude -Isrc -Iutils -Iserver -Iexamples

ifeq ($(OS),Windows_NT)
	LDFLAGS += -l Ws2_32
endif

# Directories
SRC_DIRS := src utils server
OBJ_DIR := build
BIN_DIR := .
TARGET := $(BIN_DIR)/UTrello

# Find all .cpp files in the given source directories
SOURCES := $(foreach dir,$(SRC_DIRS),$(shell find $(dir) -name '*.cpp'))
OBJECTS := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compilation rule with automatic directory creation
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Optional test target
test: $(TARGET)
	./judge.sh -t

.PHONY: all clean test
