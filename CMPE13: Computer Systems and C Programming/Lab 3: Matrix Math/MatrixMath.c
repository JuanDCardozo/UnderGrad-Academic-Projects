// Standard Libraries
#include <stdio.h>
#include <math.h>

//User Created Libraries
#include "MatrixMath.h"

/******************************************************************************
 * Extra Credit Matrix Operation
 *****************************************************************************/

/**
 * Calculate the adjugate matrix of a 3x3 matrix. This is the transpose of the cofactor matrix.
 * @param mat The input 3x3 matrix.
 * @param result The output 3x3 matrix.
 */
void MatrixAdjugate(float mat[3][3], float result[3][3])
{
    int i, j, p, q, n, m;
    float num[2][2];
    for (i = 0; 3 > i; i++) {
        for (j = 0; 3 > j; j++) {
            m = 0;
            n = 0;
            for (p = 0; 3 > p; p++) {
                for (q = 0; 3 > q; q++) {
                    if (i != q && j != p) {
                        num[m][n] = mat[q][p];
                        if (n < 1) {
                            n++;
                        } else {
                            n = 0;
                            m++;

                        }
                    }
                }
                result[q][p] = pow(-1, p + q)*(num[n][n] * num[m][m])-(num[n][m] * num[n][m]);
            }
            MatrixTranspose(result, result);
        }
    }
}
/******************************************************************************
 * Matrix - Simple Arithmetic
 *****************************************************************************/

/**
 * MatrixMultiply performs a matrix-matrix multiplication operation on two 3x3
 * matrices and returns the result in the third argument.
 */
void MatrixMultiply(float mat1[3][3], float mat2[3][3], float result[3][3])
{
    int i = 0, j = 0, p = 0;
    float sum = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            sum = 0;
            for (p = 0; p < 3; p++) {
                sum += (mat1[i][p] * mat2[p][j]);
            }
            result[i][j] = sum;
        }
    }
}

/**
 * MatrixAdd performs a matrix addition operation on two 3x3 matrices and
 * returns the result in the third argument.
 */
void MatrixAdd(float mat1[3][3], float mat2[3][3], float result[3][3])
{
    int i, j;
    for (i = 0; 3 > i; i++) {
        for (j = 0; 3 > j; j++) {
            result[i][j] = (mat1[i][j])+ (mat2[i][j]);
        }//End of j for-loop
    }// End of i for-loop
}

/**
 * MatrixEquals checks if the two matrix arguments are equal. The result is
 * 0 if FALSE and 1 if TRUE to follow the standard C conventions of TRUE and
 * FALSE.
 */
int MatrixEquals(float mat1[3][3], float mat2[3][3])
{
    //Declare temporal varialbes
    int i, j;
    for (i = 0; 3 > i; ++i) {
        for (j = 0; 3 > j; ++j) {
            //Check if the numbers are equal.
            if (fabs((mat1[i][j] - mat2[i][j])) > FP_DELTA) {

                return 0;

            }
        }// End of j for-loop
    }//End of i for-loop
    return 1;
}

/******************************************************************************
 * Matrix - Scalar Operations
 *****************************************************************************/

/**
 * MatrixScalarMultiply performs the multiplication of a matrix by a scalar.
 * The result is returned in the third argument.
 */
void MatrixScalarMultiply(float x, float mat[3][3], float result[3][3])
{
    int i, j;
    for (i = 0; 3 > i; i++) {
        for (j = 0; 3 > j; j++) {
            result[i][j] = (mat[i][j]) * x;
        }//End of j for-loop
    }// End of i for-loop
}

/**
 * MatrixScalarAdd performs the addition of a matrix by a scalar. The result
 * is returned in the third argument.
 */
void MatrixScalarAdd(float x, float mat[3][3], float result[3][3])
{
    int i, j;
    for (i = 0; 3 > i; i++) {
        for (j = 0; 3 > j; j++) {
            result[i][j] = (mat[i][j]) + x;
        }//End of j for-loop
    }// End of i for-loop
}


/******************************************************************************
 * Unary Matrix Operations
 *****************************************************************************/

/**
 * MatrixDeterminant calculates the determinant of a matrix and returns the
 * value as a float.
 */
float MatrixDeterminant(float mat[3][3])
{
    //Declare Variable
    float det;

    return det = (mat[0][0]*((mat[1][1] * mat[2][2]) - (mat[2][1] * mat[1][2])) -
            mat[0][1]*(mat[1][0] * mat[2][2] - mat[2][0] * mat[1][2]) +
            mat[0][2]*(mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1]));

}

/**
 * MatrixTrace calculates the trace of a matrix. The result is returned as a
 * float.
 */
float MatrixTrace(float mat[3][3])
{
    //Declare Temporal Variables
    int i;
    float trace = 0;

    //Add every element in the diagonal
    for (i = 0; 3 > i; i++) {
        trace += (mat[i][i]);
    }// End of i for-loop
    return trace;
}

/**
 * MatrixTranspose calculates the transpose of a matrix and returns the
 * result through the second argument
 */
void MatrixTranspose(float mat[3][3], float result[3][3])
{
    int i, j;
    for (i = 0; 3 > i; i++) {
        for (j = 0; 3 > j; j++) {
            result[i][j] = mat[j][i];
        }// End of j for-loop
    }//End of i for-loop
}

/**
 * MatrixInverse calculates the inverse of a matrix and returns the
 * result through the second argument.
 */
void MatrixInverse(float mat[3][3], float result[3][3])
{
    // Get the Adjugate of the Matrix (Transpose of the cofactors of matrix)
    //MatrixAdjugate( mat, result);
    result[0][0] = (mat[1][1] * mat[2][2]) - (mat[2][1] * mat[1][2]);
    result[0][1] = -(mat[1][0] * mat[2][2]) - (mat[2][0] * mat[1][2]);
    result[0][2] = (mat[1][0] * mat[2][1]) - (mat[2][0] * mat[1][1]);
    result[1][0] = -(mat[0][1] * mat[2][2]) - (mat[2][1] * mat[0][2]);
    result[1][1] = (mat[0][0] * mat[2][2]) - (mat[2][1] * mat[0][2]);
    result[1][2] = -(mat[0][0] * mat[2][1]) - (mat[2][0] * mat[0][1]);
    result[2][0] = (mat[0][1] * mat[1][2]) - (mat[1][1] * mat[0][2]);
    result[2][1] = -(mat[0][0] * mat[1][2]) - (mat[1][0] * mat[0][2]);
    result[2][2] = (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]);

    // Divide each factor by the matrix's determinant
    MatrixScalarMultiply((1 / (MatrixDeterminant(mat))), result, result);
}

/**
 * MatrixPrint sends a 3x3 array to standard output with clean formatting.
 * The formatting does not need to look like the expected output given to you
 * in MatricMath.c but each element of the matrix must be separated and have
 * distinguishable position (more than a single line of output).
 */
void MatrixPrint(float mat[3][3])
{
    printf("____________________________\n"
            "| %6.2f | %6.2f | %6.2f |\n"
            "----------------------------\n"
            "| %6.2f | %6.2f | %6.2f |\n"
            "----------------------------\n"
            "| %6.2f | %6.2f | %6.2f |\n"
            "----------------------------\n"
            , (double) mat[0][0], (double) mat[0][1], (double) mat[0][2]
            , (double) mat[1][0], (double) mat[1][1], (double) mat[1][2]
            , (double) mat[2][0], (double) mat[2][1], (double)mat[2][2]);
}


