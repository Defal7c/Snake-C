all:
	gcc src/*.c -lncurses -I include/ -o snake
clean:
	rm snake
	rm snake.exe
