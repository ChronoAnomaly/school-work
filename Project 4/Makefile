CFLAGS		= -g
OBJFILES	= DGraph.o project4.o

###################################################
# Default rules for compiling C++ programs 	  #
###################################################

.cpp .o:
		g++ $(CFLAGS) -c $*.cpp

project4:		$(OBJFILES)
		g++ -o project4 $(CFLAGS) $(OBJFILES)

DGraph.o:	DGraph.cpp

prject4.o:	project4.cpp

clean:
		rm -f *.o
