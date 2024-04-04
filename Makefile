################################################################################
#### Variables and settings
################################################################################

# Executable name
EXEC 				:= program

# bin, assets, and install directories (bin and build root directories are kept for clean)
BIN_DIR_ROOT 		:= bin
RES_DIR 			:= res

# Sources (searches recursively inside the source directory)
SRC_DIR 			:= src
SRCS 				:= $(sort $(shell find $(SRC_DIR) -name '*.cpp'))

# Includes
INCLUDE_DIR 		:= include
INCLUDES 			:= -I$(INCLUDE_DIR)

# C++ compiler settings
CXX 				:= clang++
CXXFLAGS 			:= -std=c++20 -O3 $(INCLUDES)
WARNINGS 			:= -Wall -Wpedantic -Wextra

# Linker flags
LDFLAGS 			:=

# Libraries to link
LDLIBS 				:= -lraylib

################################################################################
#### COMPILATION
################################################################################
all: build run over

build:
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(SRCS) $(WARNINGS) $(LDLIBS)

run:
	./$(EXEC)

over:
	read -p "Press enter to continue"
	clear