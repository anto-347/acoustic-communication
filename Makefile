make:
	gcc main.c -o build/main -lasound -lm

run:
	./build/main

init:
	rm -rf /build
	mkdir build

clean:
	rm -rf /build/*