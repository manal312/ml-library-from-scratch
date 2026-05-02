#define _CRT_SECURE_NO_WARNINGS

#include "common.h"
#include "matrix.h"
#include "model.h"
#include "utils.h"


int main(void) {
    mem_arena* perm_arena = arena_create(GiB(1), MiB(1));

    matrix* train_images = mat_load(perm_arena, 60000, 784, "train_images.mat");
    matrix* test_images = mat_load(perm_arena, 10000, 784, "test_images.mat");
    matrix* train_labels = mat_create(perm_arena, 60000, 10);
    matrix* test_labels = mat_create(perm_arena, 10000, 10);

    {
        matrix* train_labels_file = mat_load(perm_arena, 60000, 1, "train_labels.mat");
        matrix* test_labels_file = mat_load(perm_arena, 10000, 1, "test_labels.mat");

        for (u32 i = 0; i < 60000; i++) {
            u32 num = train_labels_file->data[i];
            train_labels->data[i * 10 + num] = 1.0f;
        }

        for (u32 i = 0; i < 10000; i++) {
            u32 num = test_labels_file->data[i];
            test_labels->data[i * 10 + num] = 1.0f;
        }
    }

    draw_mnist_digit(test_images->data);
    for (u32 i = 0; i < 10; i++) {
        printf("%.0f ", test_labels->data[i]);
    }
    printf("\n\n");

    model_context* model = model_create(perm_arena);
    create_mnist_model(perm_arena, model);
    model_compile(perm_arena, model);

    memcpy(model->input->val->data, test_images->data, sizeof(f32) * 784);
    model_feedforward(model);

    printf("pre-training output: ");
    for (u32 i = 0; i < 10; i++) {
        printf("%.2f ", model->output->val->data[i]);
    }
    printf("\n");

    model_training_desc training_desc = {
        .train_images = train_images,
        .train_labels = train_labels,
        .test_images = test_images,
        .test_labels = test_labels,

        .epochs = 10,
        .batch_size = 50,
        .learning_rate = 0.01f
    };
    model_train(model, &training_desc);
    
    memcpy(model->input->val->data, test_images->data, sizeof(f32) * 784);
    model_feedforward(model);
    printf("post-training output: ");
    for (u32 i = 0; i < 10; i++) {
        printf("%f ", model->output->val->data[i]);
    }
    printf("\n\n");


    arena_destroy(perm_arena);

    return 0;
}