output = calculator.out
objects = main.o getop.o stack.o

$(output) : $(objects)
	gcc -o $(output) $(objects)

$(objects): %.o : %.c
	gcc -c $< -o $@

.PHONY : clean
clean:
	rm *.o