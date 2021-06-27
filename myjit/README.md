[MyJIT](http://myjit.sourceforge.net/)

## Dependencies

Dependency is a Git submodule: `myjit/`

```shell
cd myjit/ && make jitlib-core.o
```

## Compile

```shell
gcc -O2 -c -g -Winline -Wall -std=c99 -pedantic -D_XOPEN_SOURCE=600 fib.c
gcc -O2 -o fib -g -Wall -std=c99 -pedantic fib.o myjit/jitlib-core.o -ldl
```

## Benchmark

```shell
hyperfine --warmup 3 './fib'
```
