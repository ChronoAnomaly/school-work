CFLAGS		= -g
OBJFILES	= stack.o xFile.o tree.o

###################################################
# Default rules for compiling C++ programs 	  #
###################################################

.SUFFIXES:	.cpp .o

.cpp .o:
		g++ $(CFLAGS) -c $*.cpp

xFile:		$(OBJFILES)
		g++ -o xFile $(CFLAGS) $(OBJFILES)


xFile.o:	stack.h xFile.cpp tree.h

stack.o:	stack.h stack.cpp

tree.o:		tree.h tree.cpp

clean:
		rm -f *.o
