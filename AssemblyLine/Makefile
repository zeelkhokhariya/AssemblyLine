	CC=clang++
	CFLAGS=-std=c++11        -g
	objects	=	Event.o	Queue.o	OrderedItem.o	Node.o	ListItem.o	PriorityQueue.o	PartArrival.o   Simulation.o    Parts.o finishedproduct.o   product.o   startAssembly.o endAssembly.o	ProductArrival.o	# .. etc .. put a list of your .o files here
# this rule will build A2 as the executable from the object files

all:	main testing

main:	A2main.o	$(objects)

	$(CC) $(CFLAGS)	-o	A2	$<	$(objects)
testing: Test.o Test.cpp catch.hpp
		
	$(CC) $(CFLAGS)	-Wall	-o	Tester	$<	$(objects)	


 # this rule will build a .o file from a .cpp file.

%.o: %.cpp

	$(CC) -c -o $@ $< $(CFLAGS)
clean:
	rm -f A2main.o $(objects)
	

#clang -std=c++11 -o -g Test test.cpp