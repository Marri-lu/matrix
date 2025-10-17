#ifndef MATRIX_H
#define MATRIX_H
#include "error_codes.h"
#include "row.h"

typedef struct Matrix {
    int row_count;
    Row *matr;
} Matrix;

void task(Matrix *mat, Row *row);
void print_matrix(const Matrix *mat);
void free_matrix(Matrix *mat);
Err input_matrix(Matrix *mat);

#endif
