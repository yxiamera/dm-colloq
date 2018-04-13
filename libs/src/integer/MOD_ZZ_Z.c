#pragma once
#include "../../integer.h"
#include "./SUB_ZZ_Z.c"
#include "./MUL_ZZ_Z.c"
//About author:
//Ефимчик Никита Валерьевич, ФКТИ гр.№7307
//https://sites.google.com/site/efimchiknikita7307/home
//e-mail: efimchikofficial@gmail.com

int* MOD_ZZ_Z(int *dividend, int *divider)
{
    int* quotient, *remainder;
    // dividend > divider
    if(COM_NN_D(dividend,divider) == 1)
    {
        printf("Invalid input");
        exit(42);
    }

    quotient = DIV_ZZ_Z(dividend, divider); // calculate quotient dividend/divider // DIV_ZZ_Z must malloc memory
    //!  DIV_ZZ_Z already has checked that divided and divider - integers and divider != 0
    remainder = SUB_ZZ_Z(dividend, MUL_ZZ_Z(quotient, divider)); // SUB_ZZ_Z must malloc memory
    // remainder = dividend - quotient * divider;
    free(quotient);
    return remainder;
}