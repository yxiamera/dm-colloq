#pragma once

#include "../../naturals.h"
#include "SUB_NN_N.c"
int DIV_NN_Dk(int *a, int *b) {
    /*
     * Vasilev Andrey, 7307
     * Вычисление первой цифры деления большего натурального на меньшее,
     * домноженное на 10^k, где k - номер позиции этой цифры (номер считается с нуля)
     */
    const int NSIZE = a[0];
    int *multiplied_b = (int *)malloc(NSIZE * sizeof(int));
    // copy old_b, to new location
    multiplied_b[0] = NSIZE;
    for (int i = 1; i <= NSIZE; i++) {
        multiplied_b[i] = i <= b[0] ? b[i] : 0;
    }
    // calculate num
    int n = 0;
    while (COM_NN_D(a, multiplied_b) == 2) {
        a = SUB_NN_N(a, multiplied_b);
        n++;
    }
    return n;
}