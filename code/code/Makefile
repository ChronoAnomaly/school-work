CFLAGS		= -g
OBJFILES	= lecture4.o

###################################################
# Default rules for compiling C++ programs 	  #
###################################################

.cpp .o:
		g++ $(CFLAGS) -c $*.cpp

lecture4:		$(OBJFILES)
		g++ -o lecture4 $(CFLAGS) $(OBJFILES)

lecture4.o:		lecture4.cpp sequence.h

clean:
		rm -f *.o
