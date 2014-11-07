CFLAGS		= -g

# You should probably be able to get by with just adding .o
# files to the OBJFILES line.

OBJFILES	= driver.o disk.o stub.o SAT.o FAT.o

.cpp.o:
	g++ $(CFLAGS) -c $*.cpp


driver:		$(OBJFILES)
	g++ -o driver $(OBJFILES)

test:	driver
	echo Test Suite 1 > test_results.txt
	./driver < TEST01 >> test_results.txt
	echo Test Suite 2 >> test_results.txt
	./driver < TEST02 >> test_results.txt
	echo Test Suite 3 >> test_results.txt
	./driver < TEST03 >> test_results.txt
	echo Test Suite 4 >> test_results.txt
	./driver < TEST04 >> test_results.txt
	echo Test Suite 5 >> test_results.txt
	./driver < TEST05 >> test_results.txt
	echo Test Suite 6 >> test_results.txt
	./driver < TEST06 >> test_results.txt

clean:
	rm *.o
