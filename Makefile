# Makefile for C++ project using MSVC
# Compiler and flags
CC = cl
CFLAGS = /EHsc /W3 /O2
INCLUDES = 
LIBS = 

# Directories
SRC_DIR = chaos
OBJ_DIR = obj
BIN_DIR = bin

# Source files (manually list them)
SOURCES = chaos\rule_of_three.cpp
OBJECTS = obj\rule_of_three.obj
TARGETS = bin\rule_of_three.exe

# Default target
all: $(TARGETS)

# Create directories if they don't exist
$(OBJ_DIR):
	@if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"

$(BIN_DIR):
	@if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)"

# Build individual executables
bin\rule_of_three.exe: obj\rule_of_three.obj
	@if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)"
	$(CC) $(CFLAGS) obj\rule_of_three.obj /Fe$@ $(LIBS)

# Compile source files to object files
obj\rule_of_three.obj: chaos\rule_of_three.cpp
	@if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"
	$(CC) $(CFLAGS) /c chaos\rule_of_three.cpp /Fo$@

# Clean build artifacts
clean:
	@if exist "$(OBJ_DIR)" rmdir /s /q "$(OBJ_DIR)"
	@if exist "$(BIN_DIR)" rmdir /s /q "$(BIN_DIR)"

# Run a specific program (usage: make run PROGRAM=rule_of_three)
run: bin\$(PROGRAM).exe
	bin\$(PROGRAM).exe

# Build and run rule_of_three specifically
test: bin\rule_of_three.exe
	bin\rule_of_three.exe

# Show help
help:
	@echo Available targets:
	@echo   all     - Build all programs
	@echo   clean   - Remove all build artifacts
	@echo   test    - Build and run rule_of_three
	@echo   run     - Run a specific program (use PROGRAM=name)
	@echo   help    - Show this help

.PHONY: all clean run test help
