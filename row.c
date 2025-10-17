#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "error_codes.h"
#include "matrix.h"
#include "row.h"

void free_row(Row *row) {
    free(row->row_values);
}

Err input_row(Row *row) {
    printf("Введите размер ряда: ");
    int input = input_size(&row->row_size);
    if (input != ERR_OK) {
        return ERR_INPUT_SIZE;   
    }
    if (row == NULL) {
        printf("Ошибка памяти\n");
        return ERR_MEM;
    }
    row->row_values = (int *)malloc(sizeof(int) * row->row_size);
    if (row->row_values == NULL) {
        printf("Ошибка памяти\n");
        free(row);
        return ERR_MEM;
    }
    for (int i = 0; i < row->row_size; i++) {
        printf("Введите %d элемент ряда: ", i + 1);
        input = input_int(row->row_values + i);
        if (input != ERR_OK) {
            free_row(row);
            return ERR_INPUT_EL;   
        }
    }
    return ERR_OK;
}

void print_row(const Row *row) {
    for (int i = 0; i < row->row_size; i++) {
        printf("%d", row->row_values[i]);
        printf(" ");
    }
    printf("\n");
}

