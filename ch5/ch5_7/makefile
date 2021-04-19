output = test.out

test.out: main.o readlines.o qsort.o alloc.o getlinex.o
	gcc -o ${output} main.o readlines.o qsort.o alloc.o getlinex.o

main.o: main.c getlinex.h qsort.h
	gcc -c main.c -o main.o

readlines.o: readlines.c getlinex.h alloc.h
	gcc -c readlines.c -o readlines.o

getlinex.o: getlinex.c
	gcc -c getlinex.c -o getlinex.o

alloc.o: alloc.c
	gcc -c alloc.c -o alloc.o

qsort.o: qsort.c
	gcc -c qsort.c -o qsort.o


.PHONY : clean
clean:
	rm *.o