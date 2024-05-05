#include <stdio.h>

void output(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%3d", a[i]);  // вывод шириной 3 символа
    }
    printf("\n");
}

void bubbleSort(int arr[], int n) {    // пузырьковая сортировка
    for (int i = 0; i < n - 1; i++) {  // основной проход по массиву
        for (int j = 0; j < n - i - 1; j++) {  // в конце массива всплывает макс значение
            if (arr[j] < arr[j + 1]) {  //-обратная сортировка; норм сортировка - (arr[j] > arr[j + 1])
                int temp = arr[j];    // int элемент массива
                arr[j] = arr[j + 1];  // меняем местами элементы
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = 5;
    int array[n];
    int m = 1;
    for (int i = 0; i < n; i++) {  // заполняем массив {1, 2, 3, 4, 5}
        array[i] = m;
        m++;
    }
    output(array, n);
    bubbleSort(array, n);
    output(array, n);
    return 0;
}