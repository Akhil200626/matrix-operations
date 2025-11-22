#include <stdio.h>

#define MAX 10

void readMatrix(int matrix[MAX][MAX], int r, int c);
void displayMatrix(int matrix[MAX][MAX], int r, int c);
void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int R[MAX][MAX], int r, int c);
void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int R[MAX][MAX], int r1, int c1, int c2);
void transposeMatrix(int A[MAX][MAX], int T[MAX][MAX], int r, int c);

int main() {
    int A[MAX][MAX], B[MAX][MAX], R[MAX][MAX], T[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;

    while (1) {
        printf("\n--- MATRIX OPERATIONS ---\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter rows and columns for matrices: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter Matrix A:\n");
            readMatrix(A, r1, c1);
            printf("Enter Matrix B:\n");
            readMatrix(B, r1, c1);

            addMatrix(A, B, R, r1, c1);

            printf("Result of Addition:\n");
            displayMatrix(R, r1, c1);
            break;

        case 2:
            printf("Enter rows and columns for Matrix A: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter rows and columns for Matrix B: ");
            scanf("%d %d", &r2, &c2);

            if (c1 != r2) {
                printf("Matrix multiplication not possible!\n");
                break;
            }

            printf("Enter Matrix A:\n");
            readMatrix(A, r1, c1);
            printf("Enter Matrix B:\n");
            readMatrix(B, r2, c2);

            multiplyMatrix(A, B, R, r1, c1, c2);

            printf("Result of Multiplication:\n");
            displayMatrix(R, r1, c2);
            break;

        case 3:
            printf("Enter rows and columns for matrix: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter Matrix A:\n");
            readMatrix(A, r1, c1);

            transposeMatrix(A, T, r1, c1);

            printf("Transpose of Matrix:\n");
            displayMatrix(T, c1, r1);
            break;

        case 4:
            return 0;

        default:
            printf("Invalid Choice!\n");
        }
    }
}

void readMatrix(int matrix[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &matrix[i][j]);
}

void displayMatrix(int matrix[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int R[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            R[i][j] = A[i][j] + B[i][j];
}

void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int R[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            R[i][j] = 0;
            for (int k = 0; k < c1; k++)
                R[i][j] += A[i][k] * B[k][j];
        }
}

void transposeMatrix(int A[MAX][MAX], int T[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            T[j][i] = A[i][j];
}
