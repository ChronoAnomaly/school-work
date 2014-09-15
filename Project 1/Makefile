CFLAGS		= -g
OBJFILES	= project1.o list.o

###################################################
# Default rules for compiling C++ programs 	  #
###################################################

.cpp .o:
		g++ $(CFLAGS) -c $*.cpp

project1:		$(OBJFILES)
		g++ -o project1 $(CFLAGS) $(OBJFILES)

project1.o:		project1.cpp list.cpp list.h

list.o:			list.cpp list.h

debug:	
		g++ -g -o test project1.cpp list.cpp


clean:
		rm -f *.o
