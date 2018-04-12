#pragma once

#include "MUL_Nk_N.c"

int *MUL_NN_N(int *a, int *b) {
    int length = a[0] + b[0] + 1;//calculating length our composition
    int *c = (int *) malloc(length);
    c[0] = length;
    c[1] = 0;
    for (int i = 1; i < a[0]; i++) {
        for (int j = 2; j < b[0]; j++) {
            int *n = MUL_ND_N(a, b[j]);//calculating composition of numerals
            c = ADD_NN_N(c, n);//sum the composition of numerals
        }

    }
    for (int i = 0; i < length; i++)//calculating the end of our composition(have we zeroes before our result)
    {
        int k = -1;
        int *m = MUL_Nk_N(c, k);
        c = ADD_NN_N(c, m);
        c[i] %= 10;
    }
    while (c[length] == 0)//check our result(have we excess zeroes)
    {
        length--;
    }
    return c;

}
