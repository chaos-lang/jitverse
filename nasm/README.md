[NASM](https://www.nasm.us/).

## Dependencies

```shell
apt install nasm
```

## Compile

```shell
nasm -f elf64 fib.asm
ld -arch x86_64 fib.o -o fib
```

## Benchmark

```shell
hyperfine --warmup 3 './fib'
```
