[GNU Lightning](https://www.gnu.org/software/lightning/).

## Dependencies

```shell
curl http://ftp.gnu.org/gnu/lightning/lightning-2.1.3.tar.gz -o /tmp/lightning-2.1.3.tar.gz && \
tar -xvf /tmp/lightning-2.1.3.tar.gz -C /tmp && \
cd /tmp/lightning-2.1.3 && \
./configure && \
make && \
make check && \
make install && \
cd -
```

## Compile

```shell
gcc -O3 fib.c -o fib -llightning
```

## Benchmark

```shell
hyperfine --warmup 3 './fib'
```
