# JITverse

All the JITs in the universe compared based on:

- Performance (WIP)
- Microprocessor architecture support (WIP)
- Maximum number of available registers (TODO)
- Ease of integration (TODO)
- Compilation speed (TODO)

## Performance

| Algorithm   | LibJIT              | libgccjit            | MCJIT       | AsmJit      | DynASM      | QBE     | MIR                 | GNU Lightning        | MyJit                 | GCC                   | NASM                 |
| ----------- | ------------------- | -------------------- | ----------- | ----------- | ----------- | ------- | ------------------- | -------------------- | --------------------- | --------------------- | -------------------- |
| `fib(42)`   | 1.553 s ±  0.023 s  | 545.1 ms ±   7.0 ms  | -           | -           | -           | -       | 1.094 s ±  0.011 s  | 1.339 s ±  0.008 s   | 1.824 s ±  0.069 s    | 774.8 ms ±  18.5 ms   | 805.1 ms ±   7.1 ms  |

*Mean elapsed time against 10 runs. Lower is better.*

*`fib(42)` is the recursive Fibonacci sequence algorithm.*

*C compilers and assemblers added as reference.*

### Summary:

```
Summary
  './libgccjit/toyvm ./libgccjit/fibonacci.toy 42' ran
    1.42 ± 0.04 times faster than './gcc/fib'
    1.48 ± 0.02 times faster than './nasm/fib'
    2.01 ± 0.03 times faster than './mir/fib'
    2.46 ± 0.03 times faster than './gnu_lightning/fib'
    2.85 ± 0.06 times faster than './libjit/fib'
    3.35 ± 0.13 times faster than './myjit/fib'
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
