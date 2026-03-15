# Matrix Calculator in C

A simple **Matrix Calculator implemented in C** using modular programming and multiple source files.
This project demonstrates matrix operations such as addition, subtraction, multiplication, transpose, and determinant.

---

## Features

* Matrix Addition
* Matrix Subtraction
* Matrix Multiplication
* Matrix Transpose
* Determinant calculation (2×2 and 3×3 matrices)
* Modular programming using multiple files

---

## Project Structure

```
MatrixCalculator
│
├── main.c        # Main program
├── matrix.c      # Matrix operation functions
├── matrix.h      # Function declarations
├── README.md     # Project documentation
```

---

## Matrix Operations Implemented

### 1. Matrix Addition

Adds two matrices of the same order.

Formula:

C[i][j] = A[i][j] + B[i][j]

---

### 2. Matrix Subtraction

Subtracts two matrices of the same order.

Formula:

C[i][j] = A[i][j] - B[i][j]

---

### 3. Matrix Multiplication

Condition:

Number of columns of Matrix A = Number of rows of Matrix B

Formula:

C[i][j] = Σ A[i][k] × B[k][j]

---

### 4. Matrix Transpose

The transpose of a matrix converts rows into columns.

Example:

Original Matrix

1 2 3
4 5 6

Transpose

1 4
2 5
3 6

---

### 5. Determinant

#### Determinant of 2×2 Matrix

| a  b |
| c  d |

Formula:

det = ad − bc

---

#### Determinant of 3×3 Matrix

| a b c |
| d e f |
| g h i |

Formula:

det = a(ei − fh) − b(di − fg) + c(dh − eg)

---

## How to Compile the Program

Use a C compiler such as GCC.

```
gcc main.c matrix.c -o matrix
```

---

## How to Run the Program

```
./matrix
```

or on Windows

```
matrix
```

---

## Example Output

```
Enter rows and columns of Matrix A: 2 2
Enter elements of Matrix A:
1 2
3 4

1. Addition
2. Subtraction
3. Multiplication
4. Transpose
5. Determinant

Enter choice: 5

Determinant = -2
```

---

## Concepts Used

* C Programming
* Functions
* Arrays (2D arrays)
* Modular Programming
* Header Files
* Matrix Mathematics

---

## Author

Abdul Rehman
Telecommunications Engineering Student
