//
// Created by User on 4/13/2018.
//
#pragma once

struct mod_4 {
    int m;
    int** numerator;
    int** denominator;
};

int count_digits(int number) {
    int digits=0;
    if (number < 0) {
        number *= -1;
    }
    while (number>=10) {
        digits += 1;
        number /= 10;
    }
    return digits;
};

int* init_integer(int number) {
    int i;
    int size = count_digits(number);
    int* Z = (int *)malloc((size+3) * sizeof(int));
    Z[0] = size;
    Z[1] = 0;
    for (i=2; i<=size+2; i++) {
        Z[i] = number%10;
        number /= 10;
    }
    return Z;
};

int get_integer(int* Z) {
    int number=0,power=1,i;
    for (i=2; i<=Z[0]+2; i++) {
        number += Z[i] * power;
        power *= 10;
    }
    return number;
};

mod_4 *allocate_mod_4(int m) {
    mod_4 *P = (mod_4 *)malloc(sizeof(mod_4));
    P->m = m;
    P->numerator = (int **)malloc((m+1) * sizeof(int*));
    P->denominator = (int **)malloc((m+1) * sizeof(int*));
    return P;
}

mod_4 *init_mod_4() {
    int m, i;
    printf ("Enter power of polynomial:");
    scanf ("%d", &m);
    mod_4 *P = allocate_mod_4(m);

    for (i=0; i<=m; i++){
        int num=0,den=1;
        printf ("Enter coefficient for power %d. If it's not integer, enter as rational fraction\n(example 1/2): ", i);
        scanf ("%d/%d", &num, &den);
        if (den==1)
            printf ("%d*x^%d\n", num, i);
        else
            printf ("%d/%d*x^%d\n", num, den, i);
        P->numerator[i]=init_integer(num);
        P->denominator[i]=init_integer(den);
    }

    return P;
};

void print_mod_4(mod_4 P){
    int i;
    printf("%d: \n", P.m);
    for (i=0;i<=P.m;i++){
        printf ("%d/%d", get_integer(P.numerator[i]), get_integer(P.denominator[i]));
        if (i > 0)
            printf("*x");
        if (i > 1)
            printf("^%d", i);
        if (P.m-i > 0)
            printf(" + ");
    }
    printf("\n");
};
