#include <stdio.h>

void output(int a[][100], int row, int col) {  // второе значение всегда должно быть задано
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%3d", a[i][j]);  // вывод шириной 3 символа
        }
        printf("\n");
    }
}

void sort(int a[][100], int row, int col) {}

int main() {
    int row = 5;
    int col = 10;
    int matrix[row][100];  // второе значение всегда должно быть задано для передачи в функцию
    int m = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = m;
            m++;
        }
    }
    output(matrix, row, col);
    return 0;
}