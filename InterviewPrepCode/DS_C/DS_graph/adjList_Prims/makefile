prog: main.o adjList.o linked_list.o min_heap.o
	gcc main.o adjList.o linked_list.o min_heap.o -o prog

main.o: main.c
	gcc -c main.c -o main.o

adjList.o: adjList.c adjList.h
	gcc -c adjList.c -o adjList.o

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c -o linked_list.o

min_heap.o: min_heap.c min_heap.h
	gcc -c min_heap.c -o min_heap.o

clean: 
	rm *.o prog
