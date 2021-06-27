[GCC](https://gcc.gnu.org/), native C code as a reference.

## Dependencies

```shell
gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
```

## Compile

```shell
gcc -O3 fib.c -o fib
```

## Benchmark

```shell
hyperfine --warmup 3 './fib'
```
