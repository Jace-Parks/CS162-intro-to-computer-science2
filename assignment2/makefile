CC = g++
exe_file = Bizza
$(exe_file): pizza.o restaurant.o menu.o pizzalogin.o assemble.o 
	$(CC) pizza.o restaurant.o menu.o pizzalogin.o assemble.o 
pizza.o: pizza.cpp
	$(CC) -c pizza.cpp
restaurant.o: restaurant.cpp
	$(CC) -c restaurant.cpp
menu.o: menu.cpp
	$(CC) -c menu.cpp
pizzalogin.o: pizzalogin.cpp
	$(CC) -c pizzalogin.cpp
assemble.o: assemble.cpp
	$(CC) -c assemble.cpp

clean: 
	rm -f *.out *.o $(exe_file)
