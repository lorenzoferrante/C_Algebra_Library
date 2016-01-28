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
 * Create an arbitrary matrix, given rows and colums dimension, and
 * sets the elements to 0.
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

/*===========================================================================
 * createFullMatrix
 * Create an arbitrary matrix, given rows and colums dimension, and
 * sets the elements with the arry passed to the function.
 *=========================================================================*/
matrix *createFullMatrix(size_t row, size_t col, double *data) {
    // Create a new matrix
    matrix *newMat;
    newMat = createMatrix(row, col);

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

/*===========================================================================
 * copyMatrix
 * Given a matrix, returns a perfect copy of it
 *=========================================================================*/
matrix *copyMatrix(matrix *m) {
    // Alloc and create a new matrix
    matrix *newMat = createFullMatrix(m->M, m->N, m->data);

    return newMat;
}

/*===========================================================================
 * trasposeMatrix
 * Given a marix, returns the traspose.
 *=========================================================================*/
matrix *trasposeMatrix(matrix *m) {
    // Invert rows and columns
    matrix *newMat = createMatrix(m->N, m->M);
    double *newElem;
    double *mElem = m->data;
    int i = 0, j = 0;

    // Cycle m columns
    for (; i < m->N; i++) {
        newElem = &(newMat->data[i]);
        // Cycle n rows
        for (; j < m->M; j++) {
            // Set the new element
            *newElem = *mElem;
            mElem++;
            newElem += newMat->M;
        }
    }

    return newMat;
}

/*===========================================================================
 * convertToNormaMatrix
 * Given a matrix, returns a new matrix with the same data, but in the
 * form matrix[i][j].
 *=========================================================================*/
double **convertToNormalMatrix(matrix *m) {
    int x = 0;
    size_t rows = m->M, cols = m->N;
    // Create a new matrix pointer and allocate
    // rows-pointers
    double **newMat = (double**) malloc(sizeof(double*) * rows);

    // For each rows allocate an arry of cols-element
    for (int i = 0; i < rows; ++i) {
        newMat[i] = malloc(sizeof(double) * cols);
    }

    // Populate the matrix
    for (int j = 0; j < rows; ++j) {
        for (int k = 0; k < cols; ++k) {
            newMat[j][k] = m->data[x];
            x++;
        }
    }

    return newMat;
}

