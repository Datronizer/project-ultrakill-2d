# Compiling
CC = g++
CFLAGS = -I./include/
LDFLAGS = -lraylib 

# Dirs
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Find all the .cpp files in the src directory
SRCS = $(wildcard $(SRC_DIR)/*.cpp) \
		$(wildcard $(SRC_DIR)/objects/*.cpp) \
        $(wildcard $(SRC_DIR)/entities/*.cpp)

# Create the object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Main exec name
TARGET = game

#-------------------------------------------------------------------------------
# Default target
all : $(TARGET)

# Link all object files into a single executable
$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compile each .cpp file into an object file
$(BUILD_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build directory
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Rebuild everything
rebuild: clean all

# Just in case something breaks
debug: 
	@echo "SOURCES: $(SRCS)"
	@echo "OBJS: $(OBJS)"