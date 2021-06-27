[libjit](https://www.gnu.org/software/libjit/).

## Dependencies

```shell
git submodule update libjit
```

## Compile

```shell
make -C ../ build-fib-libjit
```

## Benchmark

```shell
hyperfine --warmup 3 './fib'
```
