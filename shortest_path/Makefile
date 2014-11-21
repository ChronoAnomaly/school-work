CFLAGS		= -g
OBJFILES	= shortest_path.o

###################################################
# Default rules for compiling C++ programs 	  #
###################################################

.cpp .o:
		g++ $(CFLAGS) -c $*.cpp

shortest_path:		$(OBJFILES)
		g++ -o shortest\ path $(CFLAGS) $(OBJFILES)

shortest_path.o:	shortest_path.cpp

clean:
		rm -f *.o
