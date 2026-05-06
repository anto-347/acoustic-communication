make:
	gcc -c src/main.c -Iinclude -o build/obj/main.o
	gcc -c src/sound.c -Iinclude -o build/obj/sound.o

	gcc build/obj/main.o build/obj/sound.o -o build/bin/app -lasound -lm -g

run:
	./build/bin/app

init:
	rm -rf build
	mkdir build
	mkdir build/obj
	mkdir build/bin

clean:
	rm -rf build/bin/*
	rm -rf build/obj/*