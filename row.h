#ifndef ROW_H
#define ROW_H
#include "error_codes.h"

typedef struct Row {
    int row_size;
    int *row_values;
} Row;

void print_row(const Row *row);
Err input_row(Row *row);
void free_row(Row *row);

#endif
