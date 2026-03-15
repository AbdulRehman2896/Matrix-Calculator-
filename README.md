
# Matrix Calculator in C

A simple **Matrix Calculator implemented in C** using modular programming and multiple source files.
This project demonstrates matrix operations such as addition, subtraction, multiplication, transpose, determinant, and inverse.

---

## Features

* Matrix Addition
* Matrix Subtraction
* Matrix Multiplication
* Matrix Transpose
* Determinant calculation (any square matrix)
* Inverse calculation (2x2 and 3x3 matrices)
* Modular programming using multiple files

---

## Project Structure

```
MatrixCalculator
│
├── main.c          # Main program
├── matrix.c        # Matrix operation functions
├── utils.c         # Home screen menu and input functions
├── matrix.h        # Function declarations
├── utils.h         # Utility function declarations
├── runner.sh       # Build and run script
└── README.md       # Project documentation
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

Calculated recursively using cofactor expansion along the first row.
Works for any square matrix (1×1, 2×2, 3×3, and beyond).

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

#### Larger Matrices (n×n)

Uses recursive cofactor expansion:

det(A) = Σ (-1)^(0+j) × A[0][j] × det(minor(A, 0, j))

---

### 6. Inverse

The inverse of a square matrix A is defined as:

A⁻¹ = (1 / det(A)) × Adjoint(A)

#### Conditions

* Matrix must be square (n×n)
* Determinant must be non-zero (singular matrices have no inverse)

#### Steps

1. Calculate the determinant of A
2. Build the cofactor matrix where each element C[i][j] = (-1)^(i+j) × det(minor(i,j))
3. Transpose the cofactor matrix to get the Adjoint
4. Divide each element of the Adjoint by the determinant

#### Example (2×2)

Matrix A:

| 1  0 |
| 2  1 |

det(A) = 1

Adjoint:

|  1  0 |
| -2  1 |

Inverse:

|  1.0000  0.0000 |
| -2.0000  1.0000 |

---

## How to Compile & Run the Program

Use a C compiler such as GCC.
Just run the `runner.sh` file with this command:

```
chmod +x runner.sh
./runner.sh
```

---

## Example Output

```
╔══════════════════════════╗
║     MATRIX CALCULATOR    ║
╠══════════════════════════╣
║  1. Addition             ║
║  2. Subtraction          ║
║  3. Multiplication       ║
║  4. Transpose            ║
║  5. Determinant          ║
║  6. Inverse              ║
║  0. Exit                 ║
╚══════════════════════════╝
Enter choice: 6

┌─ Matrix A ───────────────┐
│ Rows: 2
│ Cols: 2
│
│ Enter elements row by row:
  Row 1:
    Col 1: 1
    Col 2: 0
  Row 2:
    Col 1: 2
    Col 2: 1
└──────────────────────────┘

Adjoint:
[
 1.0000  0.0000
-2.0000  1.0000
]

Inverse:
[
 1.0000  0.0000
-2.0000  1.0000
]
```

---

## Concepts Used

* C Programming
* Functions & Recursion
* Arrays (2D arrays via flat pointers)
* Modular Programming
* Header Files
* Matrix Mathematics (Cofactors, Adjoint, Inverse)

---

## Author

- Muhammad Abdullah Elahi (TC-25061)
- Abdul Rehman (TC-25065)

Department of Telecommunications Engineering, NEDUET
