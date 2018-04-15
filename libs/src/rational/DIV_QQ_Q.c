/*Об авторе:
Николаева Екатерина Валерьевна, ФКТИ гр.№7307
https://sites.google.com/site/nikolaevayekaterina7307/
e-mail: enterfox101@gmail.com*/
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "../integer/MUL_ZZ_Z.c"

struct natural{
	int n;
	int number[400];
};

struct integer{
	int n;
	int sign;
	int number[400];
};

struct rational{
	struct integer numerator;
	struct natural denomirator;
};

struct rational DIV_QQ_Q (struct rational F1, struct rational F2) {

    struct rational F;
    //-1 in struct integer mode if numerator of second fraction < 0

    if (F2.numerator.sign)
    {
        F1.numerator.sign = !(F1.numerator.sign);
        F2.numerator.sign = !(F2.numerator.sign);
    }
    //multiplication with "upside-down" fraction
    F.numerator = MUL_ZZ_Z(F1.numerator, F2.denominator); //numerator
    F.denominator = MUL_ZZ_Z(F1.denominator, F2.numerator); //denominator

    return F;
}
//full completion time - about 2 hours
