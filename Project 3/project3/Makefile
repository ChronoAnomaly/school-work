CFLAGS		=

# You should probably be able to get by with just adding .o
# files to the OBJFILES line.

OBJFILES	= driver.o disk.o stub.o

.cpp.o:
	g++ $(CFLAGS) -c $*.cpp


driver:		$(OBJFILES)
	g++ -o driver $(OBJFILES)

clean:
	rm *.o
