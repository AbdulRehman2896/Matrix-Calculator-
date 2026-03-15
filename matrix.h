#ifndef MATRIX_H
#define MATRIX_H

void inputMatrix(int matrix[10][10], int row, int col);
void displayMatrix(int matrix[10][10], int row, int col);

void addMatrix(int a[10][10], int b[10][10], int result[10][10], int row, int col);
void subtractMatrix(int a[10][10], int b[10][10], int result[10][10], int row, int col);
void multiplyMatrix(int a[10][10], int b[10][10], int result[10][10], int r1, int c1, int c2);

void transposeMatrix(int matrix[10][10], int result[10][10], int row, int col);

int determinant2x2(int matrix[10][10]);
int determinant3x3(int matrix[10][10]);

#endif