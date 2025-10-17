#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "matrix.h"
#include "error_codes.h"
#include "row.h"

Err input_matrix(Matrix *mat) {
    printf("Введите количество рядов: ");
    int input = input_size(&mat->row_count);
    if (input != 0) {
        return ERR_INPUT_SIZE;   
    }
    mat->matr = malloc(sizeof(Row) * mat->row_count);
    if (mat->matr == NULL) {
        printf("Ошибка памяти\n");
        return ERR_MEM;
    }
    for (int i = 0; i < mat->row_count; i++) {
        if (input_row(mat->matr + i) != ERR_OK) {
            for (int j = 0; j < i; j++) {
                free_row(mat->matr + j);
            }
            free(mat->matr);
            return ERR_INPUT_ROW;
        }
    }
    return ERR_OK;
}

void free_matrix(Matrix *mat) {
    for (int i = 0; i < mat->row_count; i++) {
        free_row(mat->matr + i);
    }
    free(mat->matr);
}

void print_matrix(const Matrix *mat) {
    for (int i = 0; i < mat->row_count; i++) {
        print_row(mat->matr + i);
    }
}

int min(const int a, const int b) {
    if (a < b) {
        return a;
    }
    return b;
}

void task(Matrix *mat, Row *row) {
    Row* prev;
    int ind = 0;
    int min_size = 0;
    for (int i = 0; i < mat->row_count; i++) {
        row->row_values[i] = 0;
        ind = (i - 1 + mat->row_count) % mat->row_count;

        prev = mat->matr + (ind);
        
        min_size = min(mat->matr[i].row_size, prev->row_size);

        for (int j = 0; j < min_size; j++) {
            if (prev->row_values[j] < mat->matr[i].row_values[j]) {
                row->row_values[i] += mat->matr[i].row_values[j];
            }
        }
    }
}
