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
	@echo
	@echo Test Suite 2
	./driver < TEST02
	@echo
	@echo Test Suite 3
	./driver < TEST03
	@echo
	@echo Test Suite 4
	./driver < TEST04
	@echo
	@echo Test Suite 5
	./driver < TEST05
	@echo
	@echo Test Suite 6
	./driver < TEST06

clean:
	rm *.o
