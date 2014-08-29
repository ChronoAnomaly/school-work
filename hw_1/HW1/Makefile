CFLAGS		= -g
OBJFILES	= Stack.o Queue.o hw1.o

###################################################
# Default rules for compiling C++ programs 	  #
###################################################

.SUFFIXES:	.cpp .o

.cpp .o:
		g++ $(CFLAGS) -c $*.cpp

hw1:		$(OBJFILES)
		g++ -o hw1 $(CFLAGS) $(OBJFILES)

hw1.o:		hw1.cpp Queue.h Stack.h

Stack.o:	Stack.cpp Stack.h

Queue.o:	Queue.cpp Queue.h

clean:
		rm -f *.o
