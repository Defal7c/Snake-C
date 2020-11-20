all:
	gcc src/*.c -I include/ -o snake
clean:
	rm snake
