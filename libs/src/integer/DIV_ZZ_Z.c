//Об авторе:
//Николаева Екатерина Валерьевна, ФКТИ гр.№7307
//https://sites.google.com/site/nikolaevayekaterina7307/
//e-mail: enterfox101@gmail.com
#pragma once
#include <stdlib.h>
#include "./ABS_Z_N.c"

int* DIV_ZZ_Z(int* Z1, int* Z2) {
    //detecting sign of result
    int b=1;
    if (Z1[1]==Z2[1]){  //if both numbers are positive or negative
        b=0;            //set result sign to positive
    }
    //getting positive numbers
    int* N1 = ABS_Z_N(Z1);
    int* N2 = ABS_Z_N(Z2);
    //division
    int* Z = DIV_NN_N(N1,N2);
    //set sign of the result
    Z[1] = b;

    //free memory
    free(N1);
    free(N2);

    return Z;
};

//full completion time - about 2 hours
