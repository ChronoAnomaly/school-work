CFLAGS		= -g
OBJFILES	= project2.o braided.o 

###################################################
# Default rules for compiling C++ programs 	  #
###################################################

.cpp.o:
		g++ $(CFLAGS) -c $*.cpp

project2:	$(OBJFILES)
		g++ -o project2 $(CFLAGS) $(OBJFILES) 

project2.o:	project2.cpp braided.h

braided.o:	braided.cpp braided.h	

clean:
		rm -f *.o
