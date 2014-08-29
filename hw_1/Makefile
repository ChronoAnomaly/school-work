CFLAGS		= -g
OBJFILES	= stack.o xFile.o tree.o

###################################################
# Default rules for compiling C++ programs 	  #
###################################################

.SUFFIXES:	.cpp .o

.cpp .o:
		g++ $(CFLAGS) -c $*.cpp

xFile:		$(OBJFILES)
		g++ -o xFIle $(CFLAGS) $(OBJFILES)


xFile.o:	stack.h xFile.cpp tree.h

stack.o:	Stack.h Stack.cpp

tree.o:		tree.h tree.cpp

clean:
		rm -f *.o
