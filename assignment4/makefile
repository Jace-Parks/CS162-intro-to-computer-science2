CC = g++
exe_file = Wumpus
$(exe_file): grid.o room.o event.o wumpus.o bats.o pit.o gold.o assemble.o misc.o player.o 
	$(CC) grid.o room.o event.o wumpus.o bats.o pit.o gold.o assemble.o misc.o player.o 
grid.o: grid.cpp
	$(CC) -c grid.cpp
room.o: room.cpp
	$(CC) -c room.cpp
event.o: event.cpp
	$(CC) -c event.cpp
wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp
bats.o: bats.cpp
	$(CC) -c bats.cpp
pit.o: pit.cpp
	$(CC) -c pit.cpp
gold.o: gold.cpp
	$(CC) -c gold.cpp
assemble.o: assemble.cpp
	$(CC) -c assemble.cpp
misc.o: misc.cpp
	$(CC) -c misc.cpp
player.o: player.cpp
	$(CC) -c player.cpp

clean:
	rm -f *.out *.o $(exe_file)

