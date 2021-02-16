CC = g++
exe_file = linked_list
$(exe_file): linked_list.o linked_list_node.o misc.o
	$(CC) linked_list.o linked_list_node.o misc.o
linked_list.o: linked_list.cpp
	$(CC) -c linked_list.cpp
linked_list_node.o: linked_list_node.cpp
	$(CC) -c linked_list_node.cpp
misc.o: misc.cpp
	$(CC) -c misc.cpp

clean:
	rm -f *.out *.o $(exe_file)
