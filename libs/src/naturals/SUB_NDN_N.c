#pragma once

#include "MUL_ND_N.c"

int *SUB_NDN_N(int *NUMBER_1, int *NUMBER_2, int NUMERAL) {
    int *rezult = NULL, comparison, *multiplication;
    multiplication = MUL_ND_N(NUMBER_2, NUMERAL);
    comparison = COM_NN_D(NUMBER_1, multiplication);
    if ((comparison == 2) || (comparison == 0))
        rezult = SUB_NN_N(NUMBER_1, multiplication);
    return rezult;
}