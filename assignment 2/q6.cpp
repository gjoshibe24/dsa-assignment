#include <iostream>
#include <algorithm> // Required for std::sort
using namespace std;
// Define maximum sizes for arrays to avoid dynamic allocation for this example
const int MAX_NON_ZERO = 100; // Max non-zero elements for input matrices
const int MAX_MATRIX_DIM = 100; // Max rows/cols for full matrix representation
// Function to print a sparse matrix in triplet form
void printSparseMatrix(int matrix[][3], int numNonZero) {
    cout << "Row\tCol\tValue\n";
    for (int i = 0; i < numNonZero; ++i) {
        std::cout << matrix[i][0] << "\t" << matrix[i][1] << "\t" << matrix[i][2] << "\n";
    }
}
// Function to compare two triplets (used for sorting)
bool compareTriplets(const int* a, const int* b) {
    if (a[0] != b[0]) {
        return a[0] < b[0]; // Compare rows
    }
    return a[1] < b[1]; // Compare columns
}
// Function to transpose a sparse matrix
int transposeSparseMatrix(int matrix[][3], int numNonZero, int transposedMatrix[][3]) {
    for (int i = 0; i < numNonZero; ++i) {
        transposedMatrix[i][0] = matrix[i][1]; // New row is old column
        transposedMatrix[i][1] = matrix[i][0]; // New column is old row
        transposedMatrix[i][2] = matrix[i][2]; // Value remains the same
    }
    std::sort(transposedMatrix, transposedMatrix + numNonZero, compareTriplets);
    return numNonZero;
}
// Function to add two sparse matrices
int addSparseMatrices(int matrixA[][3], int numNonZeroA,
                      int matrixB[][3], int numNonZeroB,
                      int resultMatrix[][3]) {
    int i = 0, j = 0, k = 0;
    while (i < numNonZeroA && j < numNonZeroB) {
        if (matrixA[i][0] == matrixB[j][0] && matrixA[i][1] == matrixB[j][1]) {
            int sum = matrixA[i][2] + matrixB[j][2];
            if (sum != 0) {
                resultMatrix[k][0] = matrixA[i][0];
                resultMatrix[k][1] = matrixA[i][1];
                resultMatrix[k][2] = sum;
                k++;
            }
            i++;
            j++;
        } else if (matrixA[i][0] < matrixB[j][0] || 
                   (matrixA[i][0] == matrixB[j][0] && matrixA[i][1] < matrixB[j][1])) {
            resultMatrix[k][0] = matrixA[i][0];
            resultMatrix[k][1] = matrixA[i][1];
            resultMatrix[k][2] = matrixA[i][2];
            k++;
            i++;
        } else {
            resultMatrix[k][0] = matrixB[j][0];
            resultMatrix[k][1] = matrixB[j][1];
            resultMatrix[k][2] = matrixB[j][2];
            k++;
            j++;
        }
    }
    while (i < numNonZeroA) {
        resultMatrix[k][0] = matrixA[i][0];
        resultMatrix[k][1] = matrixA[i][1];
        resultMatrix[k][2] = matrixA[i][2];
        k++;
        i++;
    }
    while (j < numNonZeroB) {
        resultMatrix[k][0] = matrixB[j][0];
        resultMatrix[k][1] = matrixB[j][1];
        resultMatrix[k][2] = matrixB[j][2];
        k++;
        j++;
    }
    return k;
}
// Function to multiply two matrices using the transposed form of B
int multiplySparseMatricesUsingTranspose(int matrixA[][3], int numNonZeroA, int rowsA, int colsA,
                                         int matrixB[][3], int numNonZeroB, int rowsB, int colsB,
                                         int resultMatrix[][3]) {
    if (colsA != rowsB) {
        cout << "Error: Matrices cannot be multiplied. Columns of A must equal rows of B.\n";
        return 0;
    }
    // Step 1: Transpose Matrix B
    int transposedB[MAX_NON_ZERO][3]; // Assuming a maximum size for transposed B
    int numNonZeroTransposedB = transposeSparseMatrix(matrixB, numNonZeroB, transposedB);
    // Step 2: Multiply A with Transposed B
    int k_prod = 0; // Pointer for resultMatrix
    // Iterate through non-zero elements of A
    for (int i_A = 0; i_A < numNonZeroA; ++i_A) {
        int a_row = matrixA[i_A][0]; // Row index of A
        int a_col = matrixA[i_A][1]; // Column index of A
        int a_val = matrixA[i_A][2]; // Value of A
        // Iterate through non-zero elements of Transposed B
        for (int i_B = 0; i_B < numNonZeroTransposedB; ++i_B) {
            int b_row = transposedB[i_B][0]; // Row index of Transposed B (original column of B)
            int b_col = transposedB[i_B][1]; // Column index of Transposed B (original row of B)
            int b_val = transposedB[i_B][2]; // Value of Transposed B
            // Check if A's column matches Transposed B's column
            if (a_col == b_col) {
                // We have a valid multiplication
                // Now we need to check if the result position already exists
                bool found = false;
                for (int r = 0; r < k_prod; ++r) {
                    if (resultMatrix[r][0] == a_row && resultMatrix[r][1] == b_row) {
                        // If the position already exists, add to its value
                        resultMatrix[r][2] += (a_val * b_val);
                        found = true;
                        break;
                    }
                }
                // If not found, add a new entry to the result matrix
                if (!found) {
                    resultMatrix[k_prod][0] = a_row; // Row index for result
                    resultMatrix[k_prod][1] = b_row; // Column index for result
                    resultMatrix[k_prod][2] = a_val * b_val; // Product value
                    k_prod++;
                }
            }
        }
    }
    return k_prod; // Return the number of non-zero elements in the result matrix
}
int main() {
    // --- Example Matrix A (3x3) ---
    int matrixA[MAX_NON_ZERO][3];
    int numNonZeroA = 3;
    int rowsA = 3, colsA = 3;
    // Manually populate matrixA (must be sorted for add/multiply)
    matrixA[0][0] = 0; matrixA[0][1] = 0; matrixA[0][2] = 15;
    matrixA[1][0] = 1; matrixA[1][1] = 1; matrixA[1][2] = 11;
    matrixA[2][0] = 1; matrixA[2][1] = 2; matrixA[2][2] = 3;
    std::cout << "--- Matrix A ---\n";
    printSparseMatrix(matrixA, numNonZeroA);
    // --- Example Matrix B (3x3) ---
    int matrixB[MAX_NON_ZERO][3];
    int numNonZeroB = 4;
    int rowsB = 3, colsB = 3;
    // Manually populate matrixB (must be sorted)
    matrixB[0][0] = 0; matrixB[0][1] = 0; matrixB[0][2] = 5;
    matrixB[1][0] = 0; matrixB[1][1] = 1; matrixB[1][2] = 6;
    matrixB[2][0] = 1; matrixB[2][1] = 1; matrixB[2][2] = 7;
    matrixB[3][0] = 2; matrixB[3][1] = 2; matrixB[3][2] = 8;
    cout << "\n--- Matrix B ---\n";
    printSparseMatrix(matrixB, numNonZeroB);
    // (1) Addition of Matrix A and Matrix B
    int sumMatrix[MAX_NON_ZERO * 2][3]; // Max size is sum of non-zeros
    int numNonZeroSum = addSparseMatrices(matrixA, numNonZeroA,
                                          matrixB, numNonZeroB,
                                          sumMatrix);
    cout << "\n--- Sum of Matrix A and Matrix B ---\n";
    printSparseMatrix(sumMatrix, numNonZeroSum);
    // (2) Multiplication of Matrix A and Matrix B using Transposed B
    int productMatrix[MAX_MATRIX_DIM * MAX_MATRIX_DIM][3]; // Max size is rowsA * colsB
    int numNonZeroProduct = multiplySparseMatricesUsingTranspose(matrixA, numNonZeroA, rowsA, colsA,
                                                                 matrixB, numNonZeroB, rowsB, colsB,
                                                                 productMatrix);
    cout << "\n--- Product of Matrix A and Matrix B ---\n";
    printSparseMatrix(productMatrix, numNonZeroProduct);
    return 0;
}