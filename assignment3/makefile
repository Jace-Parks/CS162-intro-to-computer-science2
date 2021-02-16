CC = g++
exe_file = Zoo_Tycoon
$(exe_file): assemble.o zoo.o animal.o monkey.o meerkat.o otter.o misc.o
	$(CC) assemble.o zoo.o animal.o monkey.o meerkat.o otter.o misc.o
assemble.o: assemble.cpp
	$(CC) -c assemble.cpp
zoo.o: zoo.cpp
	$(CC) -c zoo.cpp
animal.o: animal.cpp
	$(CC) -c animal.cpp
monkey.o: monkey.cpp
	$(CC) -c monkey.cpp
meerkat.o: meerkat.cpp
	$(CC) -c meerkat.cpp
otter.o: otter.cpp
	$(CC) -c otter.cpp
misc.o: misc.cpp
	$(CC) -c misc.cpp

clean:
	rm -f *.out *.o $(exe_file)
