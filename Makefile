#OBJS specifies which files to compile as part of the project
OBJS_EXAMPLE = examples/01_hello_SDL/01_hello_SDL.cpp

OBJS = src/main.cpp

OBJS_CODE = src/codeGraph/main.cpp

#CC specifies which compiler we're using
CC = clang

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w supresses all warnings
COMPILER_FLAGS = -Wall -Wextra -pedantic

COMPILER_FLAGS_DEBUG = -Wall -Wextra -pedantic -ggdb

COMPILER_FLAGS_LLVM_IR = -S -emit-llvm

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2

#OBJS_NAME specifies the name of our executable
OBJS_NAME_EXAMPLE = examples/01_hello_SDL/01_hello_SDL

OBJS_NAME = src/main

OBJS_NAME_CODE = src/codeGraph/main

OBJS_NAME_LLVM_IR = src/main.ll

#This is the target that compiles our examples
#Add @ to supress the command string in terminal.
binary : $(OBJS)
	$(info Compiling...)
	@$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJS_NAME)

code : $(OBJS)
	$(info Compiling...)
	@$(CC) $(OBJS_CODE) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJS_NAME_CODE)

llvm-ir : $(OBJS)
	$(info Generating LLVM_IR...)
	@$(CC) $(COMPILER_FLAGS_LLVM_IR) -o $(OBJS_NAME_LLVM_IR) $(OBJS)

debug : $(OBJS)
	$(info Compiling...)
	@$(CC) $(OBJS) $(COMPILER_FLAGS_DEBUG) $(LINKER_FLAGS) -o $(OBJS_NAME)

clean :
	$(info Cleaning up ( $(OBJS_NAME) $(OBJS_NAME_LLVM_IR) ))
	@rm -f $(OBJS_NAME) $(OBJS_NAME_CODE)

clear :
	clear

test : $(OBJS_EXAMPLE)
	$(info Compiling Examples...)
	@$(CC) $(OBJS_EXAMPLE) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJS_NAME_EXAMPLE)
	#@echo "Testing testing, attention please!!"

all : clean binary llvm-ir

run : $(OBJS_CODE)
	$(info Running codeGraph...)
	@./src/codeGraph/main
