#pragma once

#include "MUL_NN_N.c"


int *LCM_NN_N(int *numberOne, int *numberTwo) {
    return DIV_NN_N(MUL_NN_N(numberOne, numberTwo), GCF_NN_N(numberOne, numberTwo));
}