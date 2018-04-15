//Об авторе:
//Николаева Екатерина Валерьевна, ФКТИ гр.№7307
//https://sites.google.com/site/nikolaevayekaterina7307/
//e-mail: enterfox101@gmail.com
#pragma once
#include <stdlib.h>
#include "../integer/MUL_ZZ_Z.c"

int** DIV_QQ_Q (int** F1, int** F2) {

    //allocate memory for resulting fraction
    int** F = (int **)malloc(2 * sizeof(int*));;

    //multiplication with "upside-down" fraction
    F[0] = MUL_ZZ_Z(F1[0], F2[1]); //numerator
    F[1] = MUL_ZZ_Z(F1[1], F2[0]); //denominator

    //fix sign for denominator
    if (F[1][1] == 1) {         //if denominator is negative
        F[1][1] = 0;            //set it to positive
        //"multiply" numerator by -1
        if (F[0][1] == 1) {     //if it's negative
            F[0][1] = 0;        //set it to positive
        } else {                //else (if it's positive)
            F[0][1] = 1;        //set it to negative
        }
    }

    return F;
}

//full completion time - about 2 hours
