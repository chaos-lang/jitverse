#include "mir.h"
#include "mir-gen.h"

int main(void) {
    const int thread = 0;

    MIR_context_t ctx = MIR_init();
    MIR_gen_init(ctx, thread + 1);
    MIR_gen_set_optimize_level(ctx, thread, 3 /*-O3*/);

    MIR_module_t m = MIR_new_module(ctx, "m");

    MIR_type_t ret_types[] = {MIR_T_I64};
    MIR_item_t func = MIR_new_func(ctx, "fibonacci", 1, ret_types, 1, MIR_T_I64, "n");
    MIR_reg_t N = MIR_reg(ctx, "n", func->u.func);
    MIR_reg_t N_1 = MIR_new_func_reg(ctx, func->u.func, MIR_T_I64, "n_1");
    MIR_reg_t N_2 = MIR_new_func_reg(ctx, func->u.func, MIR_T_I64, "n_2");
    MIR_label_t small = MIR_new_label(ctx), out = MIR_new_label(ctx);

    MIR_item_t fwd = MIR_new_forward(ctx, "fibonacci");
    MIR_item_t proto = MIR_new_proto(ctx, "fibonacci_proto_", 1, ret_types, 1, MIR_T_I64, "n");

    MIR_append_insn(ctx, func,
                    MIR_new_insn(ctx, MIR_UBLE, MIR_new_label_op(ctx, small),
                                 MIR_new_reg_op(ctx, N), MIR_new_uint_op(ctx, 2)));
    MIR_append_insn(ctx, func,
                    MIR_new_insn(ctx, MIR_SUB, MIR_new_reg_op(ctx, N_1), MIR_new_reg_op(ctx, N),
                                 MIR_new_uint_op(ctx, 1)));
    MIR_append_insn(ctx, func,
                    MIR_new_insn(ctx, MIR_SUB, MIR_new_reg_op(ctx, N_2), MIR_new_reg_op(ctx, N),
                                 MIR_new_uint_op(ctx, 2)));

    MIR_append_insn(ctx, func,
                    MIR_new_call_insn(ctx, 4, MIR_new_ref_op(ctx, proto), MIR_new_ref_op(ctx, fwd),
                                      MIR_new_reg_op(ctx, N_1), MIR_new_reg_op(ctx, N_1)));
    MIR_append_insn(ctx, func,
                    MIR_new_call_insn(ctx, 4, MIR_new_ref_op(ctx, proto), MIR_new_ref_op(ctx, fwd),
                                      MIR_new_reg_op(ctx, N_2), MIR_new_reg_op(ctx, N_2)));
    MIR_append_insn(ctx, func,
                    MIR_new_insn(ctx, MIR_ADD, MIR_new_reg_op(ctx, N), MIR_new_reg_op(ctx, N_1),
                                 MIR_new_reg_op(ctx, N_2)));
    MIR_append_insn(ctx, func, MIR_new_insn(ctx, MIR_JMP, MIR_new_label_op(ctx, out)));
    MIR_append_insn(ctx, func, small);
    MIR_append_insn(ctx, func,
                    MIR_new_insn(ctx, MIR_MOV, MIR_new_reg_op(ctx, N), MIR_new_uint_op(ctx, 1)));
    MIR_append_insn(ctx, func, out);
    MIR_append_insn(ctx, func, MIR_new_ret_insn(ctx, 1, MIR_new_reg_op(ctx, N)));
    MIR_finish_func(ctx);

    MIR_finish_module(ctx);
    MIR_load_module(ctx, m);

    MIR_link(ctx, MIR_set_gen_interface, NULL);

    void *gen = MIR_gen(ctx, thread, func);
    uint64_t (*fibonacci)(uint64_t arg1) = (uint64_t(*)(uint64_t))gen;

    printf("%lu\n", (unsigned long)fibonacci(42));

    MIR_gen_finish(ctx);
/*
    FILE *f = fopen("generated.c_api.mir", "w");
    MIR_output(ctx, f);
    fclose(f);
*/
    MIR_finish(ctx);
    return 0;
}
