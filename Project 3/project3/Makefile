CFLAGS		= -g

# You should probably be able to get by with just adding .o
# files to the OBJFILES line.

OBJFILES	= driver.o disk.o stub.o SAT.o FAT.o

.cpp.o:
	g++ $(CFLAGS) -c $*.cpp


driver:		$(OBJFILES)
	g++ -o driver $(OBJFILES)

test:	clean driver
	@echo
	@echo Test Suite 1
	./driver < TEST01

clean:
	rm *.o
