make:
	gcc -c src/main.c -Iinclude -o build/obj/main.obj
	gcc -c src/sound.c -Iinclude -o build/obj/sound.obj
	gcc -c src/sinusoide.c -Iinclude -o build/obj/sinusoide.obj
	gcc -c src/message.c -Iinclude -o build/obj/message.obj

	gcc build/obj/main.obj build/obj/sound.obj src/sinusoide.c src/message.c -o build/bin/app -lasound -lm -g

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