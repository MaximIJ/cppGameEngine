#OBJS specifies which files to compile as part of the project
OBJS = examples/01_hello_SDL/01_hello_SDL.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w supresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2

#OBJS_NAME specifies the name of our executable
OBJS_NAME = examples/01_hello_SDL/01_hello_SDL

#This is the target that compiles our examples
#Add @ to supress the command string in terminal.
all : $(OBJS)
	$(info Compiling...)
	@$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJS_NAME)

clean :
	$(info Cleaning up ($(OBJS_NAME)))
	@rm -f $(OBJS_NAME)

test :
	@echo "Testing testing, attention please!!"
