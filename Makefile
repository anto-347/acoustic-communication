make:
	gcc -c src/main.c -Iinclude -o build/obj/main.obj
	gcc -c src/sound.c -Iinclude -o build/obj/sound.obj
	gcc -c src/sinusoide.c -Iinclude -o build/obj/sinusoide.obj
	gcc -c src/message.c -Iinclude -o build/obj/message.obj
	gcc -c src/utils.c -Iinclude -o build/obj/utils.obj

	gcc build/obj/main.obj build/obj/sound.obj build/obj/sinusoide.obj build/obj/message.obj build/obj/utils.obj -o build/bin/app -lasound -lm -g

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

apple_silicon:
	gcc -c src/main_mac.c -Iinclude -I/opt/homebrew/include -o build/obj/main_mac.obj
	gcc -c src/sound_mac.c -Iinclude -I/opt/homebrew/include -o build/obj/sound_mac.obj
	gcc -c src/sinusoide.c -Iinclude -o build/obj/sinusoide.obj
	gcc -c src/message.c -Iinclude -o build/obj/message.obj
	gcc -c src/utils.c -Iinclude -o build/obj/utils.obj

	gcc build/obj/main_mac.obj build/obj/sound_mac.obj build/obj/sinusoide.obj build/obj/message.obj build/obj/utils.obj -o build/bin/app -L/opt/homebrew/lib -lportaudio -lm -g

intel:
	gcc -c src/main_mac.c -Iinclude -I/usr/local/include -o build/obj/main_mac.obj
	gcc -c src/sound_mac.c -Iinclude -I/usr/local/include -o build/obj/sound_mac.obj
	gcc -c src/sinusoide.c -Iinclude -o build/obj/sinusoide.obj
	gcc -c src/message.c -Iinclude -o build/obj/message.obj
	gcc -c src/utils.c -Iinclude -o build/obj/utils.obj

	gcc build/obj/main_mac.obj build/obj/sound_mac.obj build/obj/sinusoide.obj build/obj/message.obj build/obj/utils.obj -o build/bin/app -L/usr/local/lib -lportaudio -lm -g