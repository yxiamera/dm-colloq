#pragma once

#include "SUB_NDN_N.c"

int *MOD_NN_N(int *a, int *b) {
    int* temp; // r
    if (a == NULL || b == NULL)
        return NULL;
    int *N;
    if ((COM_NN_D(a, b) == 2))//IF A > B
    {
        N = DIV_NN_N(a, b);// N: A = N*B + r
        temp = SUB_NDN_N(a, b, *N);//r = A - N*B
    } else {
        N = DIV_NN_N(b, a);//IF A <= B
        temp = SUB_NDN_N(b, a, *N);
    }
    return ((temp != NULL) ? temp : NULL);

}