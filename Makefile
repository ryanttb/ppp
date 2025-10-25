# Makefile for C++ project using MSVC
# Compiler and flags
CC = cl
CFLAGS = /EHsc /W3 /O2
INCLUDES = 
LIBS = 

# Directories
OBJ_DIR = obj
BIN_DIR = bin

# Programs to build (add new ones here)
PROGRAMS = chaos\rule_of_three c06\calc

# Generate targets and objects
TARGETS = bin\chaos\rule_of_three.exe bin\c06\calc.exe
OBJECTS = obj\chaos\rule_of_three.obj obj\c06\calc.obj

# Default target
all: $(TARGETS)

# Create directories if they don't exist
$(OBJ_DIR):
	@if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"

$(BIN_DIR):
	@if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)"

# Build individual executables
bin\chaos\rule_of_three.exe: obj\chaos\rule_of_three.obj
	@if not exist "bin\chaos" mkdir "bin\chaos"
	$(CC) $(CFLAGS) obj\chaos\rule_of_three.obj /Fe$@ $(LIBS)

bin\c06\calc.exe: obj\c06\calc.obj
	@if not exist "bin\c06" mkdir "bin\c06"
	$(CC) $(CFLAGS) obj\c06\calc.obj /Fe$@ $(LIBS)

# Compile source files to object files
obj\chaos\rule_of_three.obj: chaos\rule_of_three.cpp
	@if not exist "obj\chaos" mkdir "obj\chaos"
	$(CC) $(CFLAGS) /c chaos\rule_of_three.cpp /Fo$@

obj\c06\calc.obj: c06\calc.cpp
	@if not exist "obj\c06" mkdir "obj\c06"
	$(CC) $(CFLAGS) /c c06\calc.cpp /Fo$@

# Clean build artifacts
clean:
	@if exist "$(OBJ_DIR)" rmdir /s /q "$(OBJ_DIR)"
	@if exist "$(BIN_DIR)" rmdir /s /q "$(BIN_DIR)"

# Run a specific program (usage: make run PROGRAM=chaos\rule_of_three)
run: bin\$(PROGRAM).exe
	bin\$(PROGRAM).exe

# Build and run rule_of_three specifically
test: bin\chaos\rule_of_three.exe
	bin\chaos\rule_of_three.exe

# Build and run calculator
calc: bin\c06\calc.exe
	bin\c06\calc.exe

# Show help
help:
	@echo Available targets:
	@echo   all     - Build all programs
	@echo   clean   - Remove all build artifacts
	@echo   test    - Build and run rule_of_three
	@echo   calc    - Build and run calculator
	@echo   run     - Run a specific program (use PROGRAM=dir\name)
	@echo   help    - Show this help

.PHONY: all clean run test calc help
