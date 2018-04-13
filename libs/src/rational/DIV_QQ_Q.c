//выполнила Николаева Екатерина
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "../integer/MUL_ZZ_Z.c"

int** DIV_QQ_Q (int** F1, int** F2) {

    int** F = (int **)malloc(2 * sizeof(int*));

    //умножение на перевернутую дробь
    F[0] = MUL_ZZ_Z(F1[0], F2[1]); //числитель
    F[1] = MUL_ZZ_Z(F1[1], F2[0]); //знаменатель

    //исправление знака знаменателя
    if (F[1][1] == 1) {
        F[1][1] = 0;
        if (F[0][1] == 1) {
            F[0][1] = 0;
        } else {
            F[0][1] = 1;
        }
    }

    return F;
}
//
//int main() {
//    int **F1, **F2, **result;
//    int den1, den2, num1, num2;
//
//    printf("Enter dividend (example 1/2): ");
//    scanf("%d/%d", &num1, &den1);
//    printf("Enter divisor (example 1/4): ");
//    scanf("%d/%d", &num2, &den2);
//
//    F1 = malloc(2 * sizeof(int*));
//    F2 = malloc(2 * sizeof(int*));
//    F1[0] = init_integer(num1);
//    F1[1] = init_integer(den1);
//    F2[0] = init_integer(num2);
//    F2[1] = init_integer(den2);
//
//    result = DIV_QQ_Q(F1, F2);
//
//    printf("Result: %d/%d\n",get_integer(result[0]),get_integer(result[1]));
//
//    return 0;
//}

//время выполнения - около 2-х часов
