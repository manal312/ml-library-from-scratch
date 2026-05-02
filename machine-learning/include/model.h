#ifndef MODEL_H
#define MODEL_H
#include "matrix.h"
#include "common.h"

void create_mnist_model(mem_arena* arena, model_context* model);

model_var* mv_create(
    mem_arena* arena, model_context* model,
    u32 rows, u32 cols, u32 flags
);

model_var* mv_relu(
    mem_arena* arena, model_context* model,
    model_var* input, u32 flags
);
model_var* mv_softmax(
    mem_arena* arena, model_context* model,
    model_var* input, u32 flags
);

model_var* mv_add(
    mem_arena* arena, model_context* model,
    model_var* a, model_var* b, u32 flags
);
model_var* mv_sub(
    mem_arena* arena, model_context* model,
    model_var* a, model_var* b, u32 flags
);
model_var* mv_matmul(
    mem_arena* arena, model_context* model,
    model_var* a, model_var* b, u32 flags
);
model_var* mv_cross_entropy(
    mem_arena* arena, model_context* model,
    model_var* p, model_var* q, u32 flags
);

model_program model_prog_create(
    mem_arena* arena, model_context* model, model_var* out_var
);
void model_prog_compute(model_program* prog);
void model_prog_compute_grads(model_program* prog);

model_context* model_create(mem_arena* arena);
void model_compile(mem_arena* arena, model_context* model);
void model_feedforward(model_context* model);
void model_train(
    model_context* model,
    const model_training_desc* training_desc
);

#endif 