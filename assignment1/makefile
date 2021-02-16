CC = g++
exe_file = run
$(exe_file): login.o
	$(CC) login.o -o $(exe_file)
login_catalog.o: login.cpp
	$(CC) -c login.cpp

clean:
	rm -f *.out *.o $(exe_file)
