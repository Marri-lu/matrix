#ifndef ERRORS_H
#define ERRORS_H

typedef enum {   
    ERR_OK = 0,
    ERR_MEM = 1,
    ERR_INPUT_EL = 2,
    ERR_INPUT_SIZE = 3,
    ERR_INPUT_MAT = 4,
    ERR_INPUT_ROW = 5,
    ERR_EOF = 6,
} Err;

#endif
