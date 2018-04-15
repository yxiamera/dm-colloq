/*Об авторе:
Николаева Екатерина Валерьевна, ФКТИ гр.№7307
https://sites.google.com/site/nikolaevayekaterina7307/
e-mail: enterfox101@gmail.com*/
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "./ABS_Z_N.c"

struct natural{
	int n;
	int number[400];
};

struct integer{
	int n;
	int sign;
	int number[400];
};

struct integer DIV_ZZ_Z(struct integer Z1, struct integer Z2) {
    struct integer Z;
    int save_sign = 1;
    /*detecting sign of result
    if both numbers are positive or negative
    set result sign to positive*/
    if (Z1.sign==Z2.sign){
        save_sign = 0;
    }
    //getting positive numbers
    struct natural N1 = ABS_Z_N(Z1);
    struct natural N2 = ABS_Z_N(Z2);
    //division
    Z = DIV_NN_N(N1, N2);
    //set sign of the result
    Z.sign = save_sign;

    return Z;
};
//full completion time - about 2 hours
