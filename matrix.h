#ifndef MATRIX_H
#define MATRIX_H

// utility functions
void inputMatrix(int *matrix, int row, int col);
void displayMatrix(int *matrix, int r, int c);
void displayMatrixFloat(float *matrix, int r, int c);

// matrix operations
void addMatrix(int *a, int *b, int *result, int row, int col);
void subtractMatrix(int *a, int *b, int *result, int row, int col);
void multiplyMatrix(int *a, int *b, int *result, int r1, int c1, int c2);
void transposeMatrix(int *matrix, int *result, int row, int col);
int  determinant(int *mat, int n);

// inverse of a matrix
// A^-1 = 1/|A| * Adjoint(A), only square matrices (2x2, 3x3)
// minor, cofactor, adjoint are static (internal use only, not exposed)
void inverseMatrix(int r, int c, int *mat, float *inverseMat);

#endif