#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct test {  // объявление прототипа структуры
    double x, y, z;
};

struct test create_static(double x, double y, double z) {  // функция создания структуры в статич. памяти
    struct test test_s = {x, y, z};  // переменная на структуру
    return test_s;
};

struct test* create_dinamic(double x, double y, double z) {  // функция создания структуры в динамич. памяти
    struct test* test_d = malloc(sizeof(struct test));  // указатель на структуру
    test_d->x = x;
    test_d->y = y;
    test_d->z = z;
    return test_d;  // возвращаем адрес на выделенную память
};

struct test sum(const struct test arg1, const struct test arg2) {  // ф. сложения 2х структур
    struct test result = {arg1.x + arg2.x, arg1.y + arg2.y, arg1.z + arg2.z};
    return result;
};

int main() {
    short max_points = 10;

    printf("Статика\n");

    struct test figure[max_points];  // статика
    for (int i = 0; i < max_points; i++) {
        figure[i].x = (i + 1) * 1;
        figure[i].y = (i + 2) * 2;
        figure[i].z = (i + 3) * 3;
    }

    struct test* ptr_v = figure;  // указатель на массив структур
    (*(ptr_v + 2)).x = 10.1;      // меняем figure[2].x смещение
    ptr_v[2].y = 11.1;            // меняем figure[2].y элемент массива
    (ptr_v + 2)->z = 12.1;        // меняем figure[2].z смещением упрощенный вар.

    for (int i = 0; i < max_points; i++) {
        printf("x: %.1lf; y: %.1lf; z: %.1lf.\n", figure[i].x, figure[i].y, figure[i].z);
    }

    printf("\nДинамика\n");

    struct test* ptr_d = malloc(max_points * sizeof(struct test));  // динамика
    for (int i = 0; i < max_points; i++) {
        ptr_d[i].x = (i + 1) * 1;
        ptr_d[i].y = (i + 2) * 2;
        ptr_d[i].z = (i + 3) * 3;
    }

    (*(ptr_d + 3)).x = 30.2;  // меняем ptr_d[3].x
    ptr_d[3].y = 31.2;        // меняем ptr_d[3].y
    (ptr_d + 3)->z = 32.2;    // меняем ptr_d[3].z

    for (int i = 0; i < max_points; i++) {
        printf("x: %.1lf; y: %.1lf; z: %.1lf.\n", ptr_d[i].x, ptr_d[i].y, ptr_d[i].z);
    }
    free(ptr_d);

    printf("\nСоздание структуры в статич. памяти при помощи функции\n");

    struct test func_static[max_points];
    for (int i = 0; i < max_points; i++) {  // создание структур в статич. памяти при помощи функции
        func_static[i] = create_static((i + 1) * 1, (i + 2) * 2, (i + 3) * 3);  // инициал. каждого элемента
    }

    (*(func_static + 4)).x = 40.3;  // меняем func_static[3].x
    func_static[4].y = 41.3;        // меняем func_static[3].y
    (func_static + 4)->z = 42.3;    // меняем func_static[3].z

    for (int i = 0; i < max_points; i++) {
        printf("x: %.1lf; y: %.1lf; z: %.1lf.\n", func_static[i].x, func_static[i].y, func_static[i].z);
    }

    printf("\nСоздание структуры в динамич. памяти при помощи функции\n");

    struct test* func_dinamic[max_points];  // указатель на область динам. памяти структуры
    for (int i = 0; i < max_points; i++) {  // создание структур в динамич. памяти при помощи функции
        func_dinamic[i] = create_dinamic(
            (i + 1) * 1, (i + 2) * 2,
            (i + 3) * 3);  // инициал. каждого элемента, получаем указатель на участок памяти для структуры
    }

    func_dinamic[5]->x = 40.4;        // меняем func_dinamic[3]->x
    func_dinamic[5]->y = 41.4;        // меняем func_dinamic[3]->y
    (*(func_dinamic + 5))->z = 42.4;  // меняем func_dinamic[3]->z

    for (int i = 0; i < max_points; i++) {
        printf("x: %.1lf; y: %.1lf; z: %.1lf.\n", (*(func_dinamic + i))->x, func_dinamic[i]->y,
               func_dinamic[i]->z);
        free(func_dinamic[i]);
    }

    printf("\nСложение элементов структур через функцию\n");

    struct test result = sum(func_static[5], func_static[8]);
    printf("x: %.1lf; y: %.1lf; z: %.1lf.\n", result.x, result.y, result.z);

    return 0;
};