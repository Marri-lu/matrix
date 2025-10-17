#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "error_codes.h"
#include "row.h"

Err main() {
    do {
        Matrix mat;
        if (input_matrix(&mat) != ERR_OK) {
            return ERR_INPUT_MAT;
        }
        printf("Матрица: \n");
        print_matrix(&mat);

        Row row;
        row.row_size = mat.row_count;
        row.row_values = (int *)malloc(sizeof(int) * mat.row_count);

        if (row.row_values == NULL) {
            printf("Ошибка памяти\n");
            free_matrix(&mat);
            return ERR_MEM;
        } 

        task(&mat, &row);

        printf("Вектор: \n");
        print_row(&row);
        free_row(&row);
        free_matrix(&mat);
    } while(1);
    return ERR_OK;
}
