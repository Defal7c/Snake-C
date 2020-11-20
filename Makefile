all:
	gcc src/*.c -I include/ -o snake
	i686-w64-mingw32-gcc src/*.c -I include/ -o snake.exe	
clean:
	rm snake
	rm snake.exe
