#include "libjit/include/jit/jit.h"

static jit_value_t call_fib(jit_function_t function, const jit_value_t n, const jit_value_t sub) {
  jit_value_t temp = jit_insn_sub(function, n, sub);
  jit_value_t temp_args[1];
  temp_args[0] = temp;
  return jit_insn_call
         (function, "fib", function, 0, temp_args, 1, 0);
}

static void call(jit_function_t function, const int n) {
  jit_nint result;
  jit_nint arg1 = n;
  void *args[1] = { &arg1 };
  jit_function_apply(function, args, &result);
  printf("%d\n", (int)result);
}

int main() {
  jit_context_t context = jit_context_create();
  jit_context_build_start(context);
  jit_type_t params[1];
  jit_type_t signature;
  params[0] = jit_type_nint;
  signature = jit_type_create_signature
         (jit_abi_cdecl, jit_type_nint, params, 1, 1);
  jit_function_t function = jit_function_create(context, signature);
  jit_value_t n = jit_value_get_param(function, 0);

  jit_label_t label = jit_label_undefined;
  jit_value_t two = jit_value_create_nint_constant(function, jit_type_nint, 2);
  jit_value_t check = jit_insn_lt(function, n, two);
  jit_insn_branch_if_not(function, check, &label);
  jit_insn_return(function, n);

  jit_insn_label(function, &label);
  jit_value_t tmp1 = call_fib(function, n, two);
  jit_value_t one = jit_value_create_nint_constant(function, jit_type_nint, 1);
  jit_value_t tmp2 = call_fib(function, n, one);

  jit_value_t ret = jit_insn_add(function, tmp1, tmp2);
  jit_insn_return(function, ret);
  jit_function_compile(function);

  jit_context_build_end(context);

  call(function, 42);

  jit_context_destroy(context);
}
