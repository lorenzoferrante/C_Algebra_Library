//
// Created by Lorenzo Ferrante on 27/01/16.
//

#ifndef ALGEBRA_ALGEBRA_H
#define ALGEBRA_ALGEBRA_H

#include <stdlib.h>
#include <stdio.h>

/*============================
 * New type matrix.
 *==========================*/
typedef struct _matrix {
    size_t M, N;
    double *data;
} matrix;

/*============================
 * Display error clearly
 *==========================*/
extern void assert(int assertion, char *message);

/*============================
 * Useful Matrix functions
 *==========================*/
extern matrix *createMatrix(size_t row, size_t col);
extern matrix *createFullMatrix(size_t row, size_t col, double *data);
extern matrix *copyMatrix(matrix *m);
extern matrix *trasposeMatrix(matrix *m);
extern double **convertToNormalMatrix(matrix *m);

#endif //ALGEBRA_ALGEBRA_H
