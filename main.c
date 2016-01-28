//
// Created by Lorenzo Ferrante on 27/01/16.
//

#include "Algebra.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    // Create an example matrix
    double data[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    double *dataToPass = data;
    matrix *oldMat = createFullMatrix(2, 3, dataToPass);

    // Copy oldMat
    matrix *cpMat = copyMatrix(oldMat);
    printf("%lf\n", cpMat->data[5]);

    // Normalize matrix
    double **newMat = convertToNormalMatrix(cpMat);
    printf("%lf\n", newMat[1][0]);

    return 0;
}
