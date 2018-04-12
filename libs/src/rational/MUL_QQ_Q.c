//About author:
//Ефимчик Никита Валерьевич, ФКТИ гр.№7307
//https://sites.google.com/site/efimchiknikita7307/home
//e-mail: efimchikofficial@gmail.com
int* MUL_ZZ_Z(int*  a,int* b) // умножение
{
    //delete when constructing
}
int NZER_N_B(int * a)
{
    //delete when constructing
}
#include <stdio.h>
#include <stdlib.h>
#include "MUL_QQ_Q.h"

int **MUL_QQ_Q(int **fractionMultiplied, int **fractionMultiplier)
{    int ** fraction = malloc(2 * sizeof(int*)); // это - дробь{ fraction[0] - числитель  fraction[1] - знаменатель}
    if( NZER_N_B(fractionMultiplied[1]) == 1 ||  NZER_N_B(fractionMultiplier[1]) == 1) // проверка что знаменатель не равен 0
    {
        printf("Invalid input");
        exit(42);
    }
    //
    fraction[0] = MUL_ZZ_Z(fractionMultiplied[0],fractionMultiplier[0] ); // числитель произведения
    fraction[1] = MUL_ZZ_Z(fractionMultiplied[1],fractionMultiplier[1]); // знаменатель произведения

    return  fraction;
}
