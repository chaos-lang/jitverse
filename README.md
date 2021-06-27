# JITverse

All the JITs in the universe compared based on:

- Performance (WIP)
- Microprocessor architecture support (WIP)
- Maximum number of available registers (TODO)
- Ease of integration (TODO)
- Compilation speed (TODO)

## Performance

| Algorithm   | LibJIT     | libgccjit            | MCJIT       | AsmJit      | DynASM      | QBE     | MIR    | GNU Lightning        | MyJit                 | GCC                   | NASM                 |
| ----------- | ---------- | -------------------- | ----------- | ----------- | ----------- | ------- | ------ | -------------------- | --------------------- | --------------------- | -------------------- |
| `fib(42)`   | -          | 536.2 ms ±   5.9 ms  | -           | -           | -           | -       | -      | 1.331 s ±  0.005 s   | 1.807 s ±  0.072 s    | 765.5 ms ±  21.8 ms   | 792.1 ms ±   5.4 ms  |

*Lower is better. Mean elapsed time against 10 runs.*

*`fib(42)` is the recursive Fibonacci sequence algorithm.*

*C compilers and assemblers added as reference.*

### Summary:

```
Summary
  './libgccjit/toyvm ./libgccjit/fibonacci.toy 42' ran
    1.43 ± 0.04 times faster than './gcc/fib'
    1.48 ± 0.02 times faster than './nasm/fib'
    2.48 ± 0.03 times faster than './gnu_lightning/fib'
    3.37 ± 0.14 times faster than './myjit/fib'
```

Peformed using:

- `gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0`
- `NASM version 2.14.02`
- `hyperfine 1.11.0`

See the related directories for more details.

# Microprocessor Architecture Support

| Architecture | LibJIT | libgccjit | MCJIT | AsmJit | DynASM | QBE | MIR | GNU Lightning | MyJit |
| ------------ | ------ | --------- | ----- | ------ | ------ | --- | --- | ------------- | ----- |
| x86          | -      | Yes       | -     | Yes    | Yes    | -   | -   | Yes           | Yes   |
| x86-64       | -      | Yes       | -     | Yes    | Yes    | -   | -   | Yes           | Yes   |
| ARM32        | -      | Yes       | -     | No     | Yes    | -   | -   | Yes           | Yes   |
| AArch64      | -      | Yes       | -     | Yes    | Yes    | -   | -   | Yes           | No    |
| IA-64        | -      | Yes       | -     | No     | No     | -   | -   | Yes           | No    |
| RISC-V       | -      | Yes       | -     | No     | No     | -   | -   | Yes           | No    |
| MIPS         | -      | Yes       | -     | No     | Yes    | -   | -   | Yes           | No    |
| HPPA         | -      | Yes       | -     | No     | No     | -   | -   | Yes           | No    |
| SPARC        | -      | Yes       | -     | No     | No     | -   | -   | Yes           | Yes   |
| PowerPC      | -      | Yes       | -     | No     | Yes    | -   | -   | Yes           | No    |
| Alpha        | -      | Yes       | -     | No     | No     | -   | -   | Yes           | No    |
| S390         | -      | Yes       | -     | No     | No     | -   | -   | Yes           | No    |
