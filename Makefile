# leads comments in a line 
# Build all: default target
all : myshell

#specify the compiler
CXX = g++

#specify the compiler options
COMP = -c
OBJ = -o

#specify the name of the ultimate executable file
EXEC = myshell

#GDB debugger options
GDB = -ggdb

#Specify the object files
OBJFILES = main.o myshell.o




# Separate compilation to build object files
main.o : main.cpp myshell.h 
	$(CXX) $(COMP) $(GDB) main.cpp

myshell.o : myshell.cpp myshell.h 
	$(CXX) $(COMP) $(GDB) myshell.cpp

# Linking
#myshell is a target which depends upon main.o and myshell.o 
#"g++ main.o myshell.o -o myshell" is the command to produce the executable file
#You need to use a TAB before g++ 
$(EXEC): $(OBJFILES)
	$(CXX) $(OBJFILES)  $(OBJ) $(EXEC)
	@echo 'myshell has been created'

# A valgrind target to check for memory leaks
valgrind :
	valgrind --leak-check=yes $(EXEC)
	#@echo 'valgrind.out has been created'


# Testing
check : all
	./$(EXEC)

# Clean up all build targets so that one may get a clean build
clean :
	rm -f *.o $(EXEC)

	
