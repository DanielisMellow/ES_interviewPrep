prog: main.o adj_list.o list.o min_heap.o
	gcc main.o adj_list.o list.o min_heap.o -o prog

main.o: main.c
	gcc -c main.c -o main.o

adj_list.o: adj_list.c adj_list.h
	gcc -c adj_list.c -o adj_list.o

list.o: list.c list.h
	gcc -c list.c -o list.o

min_heap.o: min_heap.c min_heap.h
	gcc -c min_heap.c -o min_heap.o

clean:
	rm *.o prog
