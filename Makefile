build: build-fib

build-fib: build-fib-gcc build-fib-nasm build-fib-libgccjit build-fib-gnu-lightning build-fib-myjit

build-fib-gcc:
	cd gcc && \
	gcc -O3 fib.c -o fib

build-fib-nasm:
	cd nasm && \
	nasm -f elf64 fib.asm && \
	ld -arch x86_64 fib.o -o fib

build-fib-libgccjit:
	cd libgccjit && \
	gcc -Wall -g -o toyvm toyvm.c -lgccjit

build-fib-gnu-lightning:
	cd gnu_lightning && \
	gcc -O3 fib.c -o fib -llightning

build-fib-myjit:
	cd myjit/myjit/ && \
	make jitlib-core.o
	cd myjit/ && \
	gcc -O2 -c -g -Winline -Wall -std=c99 -pedantic -D_XOPEN_SOURCE=600 fib.c && \
	gcc -O2 -o fib -g -Wall -std=c99 -pedantic fib.o myjit/jitlib-core.o -ldl


bench: bench-fib

bench-fib:
	hyperfine --warmup 3 \
		'./libgccjit/toyvm ./libgccjit/fibonacci.toy 42' \
		'./gnu_lightning/fib' \
		'./myjit/fib' \
		'./gcc/fib' \
		'./nasm/fib'


validate: validate-fib

validate-fib:
	echo "fib(42)" && \
	./libgccjit/toyvm ./libgccjit/fibonacci.toy 42 && \
	./gnu_lightning/fib && \
	./myjit/fib \
	./gcc/fib && \
	./nasm/fib
