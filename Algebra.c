//
// Created by Lorenzo Ferrante on 27/01/16.
//

#include "Algebra.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*===========================================================================
 * assert
 * If the assertion is non-zero (i.e. true), then it returns.
 * If the assertion is zero (i.e. false), then it display the string and
 * aborts the program.
 * This is ment to act like Python's assert keyword.
 * Copied from:
 * https://github.com/jcchurch/C-Linear-Algebra/blob/master/matrix.c
 *=========================================================================*/
void assert(int assertion, char* message) {
    if (assertion == 0) {
        fprintf(stderr, "%s\n", message);
        exit(1);
    }
}

/*===========================================================================
 * createMatrix
 * Create an arbitrary matrix, given rows and colums dimension.
 *=========================================================================*/
matrix *createMatrix(size_t row, size_t col) {
    // Create a new matrix pointer
    matrix *newMat;
    assert(row > 0 && col > 0, "Matrix must be at least 1 by 1.");

    // Allocate memory for the new matrix
    newMat = (matrix*) malloc(sizeof(matrix));

    // Check if the is not NULL
    assert(newMat != NULL, "Out of memory!");

    newMat->M = row;
    newMat->N = col;
    newMat->data = (double*) malloc(sizeof(double) * row * col);

    // Check if data is not NULL
    assert(newMat->data != NULL, "Out of memory!");

    // Set to 0 all the elements of the matrix
    memset(newMat->data, 0.0, row * col * sizeof(double));

    return newMat;
}

matrix *createFullMatrix(size_t row, size_t col, double *data) {
    // Create a new matrix pointer
    matrix *newMat;
    assert(row > 0 && col > 0, "Matrix must be at least 1 by 1.");

    // Allocate memory for the new matrix
    newMat = (matrix*) malloc(sizeof(matrix));

    // Check if the is not NULL
    assert(newMat != NULL, "Out of memory!");

    newMat->M = row;
    newMat->N = col;
    newMat->data = (double*) malloc(sizeof(double) * row * col);

    // Check if data is not NULL
    assert(newMat->data != NULL, "Out of memory!");

    /* ================================
     *  BUG: number of data elements
     *  must be the same as
     *  newMat->data elements.
     * ==============================*/
    // Full the array with the data passed
    for (int i = 0; i < row * col; ++i) {
        newMat->data[i] = data[i];
    }

    return newMat;
}
