//выполнила Николаева Екатерина
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "./ABS_Z_N.c"

//int count_digits(int number) {
//    int digits=0;
//    if (number < 0) {
//        number *= -1;
//    }
//    while (number>=10) {
//        digits += 1;
//        number /= 10;
//    }
//    return digits;
//};
//
//int* init_integer(int number) {
//    int i;
//    int size = count_digits(number);
//    int* Z = (int *)malloc((size+3) * sizeof(int));
//    Z[0] = size;
//    if (number < 0) {
//        Z[1] = 1;
//        number *= -1;
//    } else {
//        Z[1] = 0;
//    }
//    for (i=2; i<=size+2; i++) {
//        Z[i] = number%10;
//        number /= 10;
//    }
//    return Z;
//};
//
//int get_integer(int* Z) {
//    int number=0,power=1,i;
//    for (i=2; i<=Z[0]+2; i++) {
//        number += Z[i] * power;
//        power *= 10;
//    }
//    if (Z[1] == 1) {
//        number *= -1;
//    }
//    return number;
//};

int* DIV_ZZ_Z(int* Z1, int* Z2) {
    //определяем знак результата
    int b=1;
    if (Z1[1]==Z2[1]){
        b=0;
    }
    //получаем натуральные числа
    int* N1 = ABS_Z_N(Z1);
    int* N2 = ABS_Z_N(Z2);
    //деление
    int* Z = DIV_NN_N(N1,N2);
    Z[1] = b;

    free(N1);
    free(N2);

    return Z;
};

//int main() {
//    int answer;
//
//    printf("Dividend: ");
//    scanf("%d", &answer);
//    int* Z1 = init_integer(answer);
//    printf("Divider: ");
//    scanf("%d", &answer);
//    int* Z2 = init_integer(answer);
//
//    int* Z = DIV_ZZ_Z(Z1,Z2);
//    printf("%d div %d = %d\n",get_integer(Z1),get_integer(Z2),get_integer(Z));
//
//    return 0;
//};

//общее время создания - около 2-х часов
