#pragma once
#include "../../naturals.h"

int *MUL_Nk_N(int *A, int k)
{
    int i, k1;

    if ((!A[0])&&(!A[2]))
    //there's no point in adding more memory when 10^k*0 = 0
        k1 = 0;
    else k1 = k;
    //allocate a new number with bigger size
    int* B = malloc((A[0]+3+k1) * sizeof(int));

    //set size of this new number
    B[0] = A[0]+k1;
    //set sign
    B[1] = A[1];

    //copy first A[0] digits from the old number
    for (i = 2; i<=A[0]+2; i++)
        B[i] = A[i];
    //fill last k digits with zeros
    for (i = A[0]+3; i<B[0]+3; i++)
        B[i] = 0;

    return B;
}
