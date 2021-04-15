output = calculator.out
objects = main.o getop.o stack.o isnumfmt.o

$(output) : $(objects)
	gcc -o $(output) $(objects) -lm

$(objects): %.o : %.c
	gcc -c $< -o $@

.PHONY : clean
clean:
	rm *.o