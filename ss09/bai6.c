#include <stdio.h>
#define MAX_SIZE 100

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int *rows, int *cols) {
    printf("Nhap so dong: ");
    scanf("%d", rows);
    printf("Nhap so cot: ");
    scanf("%d", cols);

    if (*rows <= 0 || *cols <= 0 || *rows > MAX_SIZE || *cols > MAX_SIZE) {
        printf("Kich thuoc khong hop le!\n");
        *rows = *cols = 0; // Ð?t l?i n?u không h?p l?
        return;
    }

    printf("Nhap cac gia tri trong ma tran:\n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            printf("Phan tu [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    if (rows == 0 || cols == 0) {
        printf("Ma tran rong.\n");
        return;
    }
    printf("Ma tran:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

void displayOddAndSum(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int sum = 0;
    printf("Cac phan tu le:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] % 2 != 0) {
                printf("%d ", matrix[i][j]);
                sum += matrix[i][j];
            }
        }
    }
    printf("\nTong cac phan tu le: %d\n", sum);
}

void displayBorderAndProduct(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    if (rows == 0 || cols == 0) {
        printf("Ma tran rong.\n");
        return;
    }
    long long product = 1;
    printf("Cac phan tu tren duong bien:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                printf("%d ", matrix[i][j]);
                product *= matrix[i][j];
            }
        }
    }
    printf("\nTich cac phan tu tren duong bien: %lld\n", product);
}

void displayMainDiagonal(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    printf("Cac phan tu tren duong cheo chinh:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", matrix[i][i]);
    }
    printf("\n");
}

void displaySecondaryDiagonal(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    printf("Cac phan tu tren duong cheo phu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", matrix[i][size - i - 1]);
    }
    printf("\n");
}

void displayRowWithMaxSum(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int maxSum = -1, maxRow = -1;
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        if (rowSum > maxSum) {
            maxSum = rowSum;
            maxRow = i;
        }
    }
    printf("Dong co tong lon nhat la dong %d (tong = %d):\n", maxRow + 1, maxSum);
    for (int j = 0; j < cols; j++) {
        printf("%d ", matrix[maxRow][j]);
    }
    printf("\n");
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows = 0, cols = 0, choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In gia tri cac phan tu la le va tinh tong\n");
        printf("4. In ra cac phan tu nam tren duong bien va tinh tich\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh\n");
        printf("6. In ra cac phan tu nam tren duong cheo phu\n");
        printf("7. In ra dong co tong gia tri cac phan tu lon nhat\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputMatrix(matrix, &rows, &cols);
                break;
            case 2:
                displayMatrix(matrix, rows, cols);
                break;
            case 3:
                displayOddAndSum(matrix, rows, cols);
                break;
            case 4:
                displayBorderAndProduct(matrix, rows, cols);
                break;
            case 5:
                if (rows == cols) {
                    displayMainDiagonal(matrix, rows);
                } else {
                    printf("Chi ap dung cho ma tran vuong.\n");
                }
                break;
            case 6:
                if (rows == cols) {
                    displaySecondaryDiagonal(matrix, rows);
                } else {
                    printf("Chi ap dung cho ma tran vuong.\n");
                }
                break;
            case 7:
                displayRowWithMaxSum(matrix, rows, cols);
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 8);

    return 0;
}

