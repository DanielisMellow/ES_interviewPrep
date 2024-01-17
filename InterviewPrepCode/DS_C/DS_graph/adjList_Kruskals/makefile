program: main.o adj_list.o disjoint_set.o linkd_lst.o  
	gcc main.o adj_list.o disjoint_set.o linkd_lst.o -o program

main.o: main.c
	gcc -c main.c -o main.o 

adj_list.o: adj_list.c adj_list.h
	gcc -c adj_list.c -o adj_list.o

disjoint_set.o: disjoint_set.c disjoint_set.h
	gcc -c disjoint_set.c -o disjoint_set.o

linkd_lst.o: linkd_lst.c linkd_lst.h
	gcc -c linkd_lst.c -o linkd_lst.o

clean: 
	rm *.o program
