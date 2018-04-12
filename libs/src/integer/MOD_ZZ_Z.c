#pragma once
#include "../../integer.h"
#include "./SUB_ZZ_Z.c"
#include "./MUL_ZZ_Z.c"
//About author:
//Ефимчик Никита Валерьевич, ФКТИ гр.№7307
//https://sites.google.com/site/efimchiknikita7307/home
//e-mail: efimchikofficial@gmail.com

int* MOD_ZZ_Z(int *bigInt, int *smallInt)
{
    int* integer, *rest;
    // integer - неполное частное, rest - остаток от деления, bigInt - делимое, smallInt - делитель,  bigInt > smallInt
    if(COM_NN_D(bigInt,smallInt) == 1)
    {
        printf("Invalid input");
        exit(42);
    }
    integer = DIV_ZZ_Z(bigInt, smallInt); // вычисляем неполное частное
    //!Проверку на то что bigInt и smallInt - натуральные числа и то что делитель отличен от 0
    //! делает человек, заведующий функцией  DIV_ZZ_Z
    rest = SUB_ZZ_Z(bigInt, MUL_ZZ_Z(integer, smallInt)); // остаток это  делимое - произведение неполного частного на делитель
   // rest = bigInt - integer * smallInt;
    free(integer);
    return rest;
}