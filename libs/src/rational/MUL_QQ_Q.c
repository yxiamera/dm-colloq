#pragma once
//About author:
//Ефимчик Никита Валерьевич, ФКТИ гр.№7307
//https://sites.google.com/site/efimchiknikita7307/home
//e-mail: efimchikofficial@gmail.com
#include <stdio.h>
#include <stdlib.h>
//#include "MUL_QQ_Q.h"

int **MUL_QQ_Q(int **fractionMultiplied, int **fractionMultiplier)
{    int ** fraction = malloc(2 * sizeof(int*)); // it's a fraction { fraction[0] - numerator  fraction[1] - denominator}
    if( NZER_N_B(fractionMultiplied[1]) == 1 ||  NZER_N_B(fractionMultiplier[1]) == 1) //  checking that denominator != 0
    {
        printf("Invalid input");
        exit(42);
    }
    //
    fraction[0] = MUL_ZZ_Z(fractionMultiplied[0],fractionMultiplier[0] ); // numerator of composition
    // MUL_ZZ_Z must malloc memory
    fraction[1] = MUL_ZZ_Z(fractionMultiplied[1],fractionMultiplier[1]); // denominator of composition
    return  fraction;
}
