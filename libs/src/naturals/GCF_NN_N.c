#pragma once
#include "MOD_NN_N.c"
#include "../../naturals.h"

int *GCF_NN_N(int *input1, int *input2) {
    // Execution time: 20 minutes
    // Logical lines of code: 15
    int *GCF;
    // If one number is divided into another without a remainder, then the GCD is the smaller of them
    if (MOD_NN_N(input1, input2) == 0) {
        GCF = input2;
    }
    if (MOD_NN_N(input2, input1) == 0) {
        GCF = input1;
    }

    while ((MOD_NN_N(input1, input2) != 0) || (MOD_NN_N(input2, input1) !=
                                               0)) { // While the remainder of division of one number by another is not equal to zero
        if (COM_NN_D(input1, input2) == 2) {
            GCF = SUB_NN_N(input1, input2);
        } else {
            if (COM_NN_D(input1, input2) == 1) {
                GCF = SUB_NN_N(input2, input1);
            } else {
                return GCF;
            }
        }
    }
    return GCF;
}
