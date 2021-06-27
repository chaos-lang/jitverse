toyvm: toyvm.c Makefile
	gcc -Wall -g -o toyvm toyvm.c -lgccjit

factorial: toyvm
	./toyvm factorial.toy 10

fibonacci: toyvm
	./toyvm fibonacci.toy 42

clean:
	rm -f *.o toyvm
