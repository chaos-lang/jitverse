[libgccjit](https://gcc.gnu.org/onlinedocs/jit/).

## Dependencies

```shell
apt install libgccjit-9-dev
```

## Compile

```shell
gcc -Wall -g -o toyvm toyvm.c -lgccjit
```

## Benchmark

```shell
hyperfine --warmup 3 './toyvm ./fibonacci.toy 42'
```
