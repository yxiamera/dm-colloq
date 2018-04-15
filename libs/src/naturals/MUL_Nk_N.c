/*Об авторе:
Николаева Екатерина Валерьевна, ФКТИ гр.№7307
https://sites.google.com/site/nikolaevayekaterina7307/
e-mail: enterfox101@gmail.com*/
#pragma once

struct natural{
	int n;
	int number[400];
};

struct natural MUL_Nk_N(struct natural A, int k) {
    struct natural B;
    int i;

    //if A is not 0
    if ((A.n==1)&&(!A.number[0]))
    {
        //copy first A[0] digits from the old number with shifting
        for (i = A.n-1; i >= 0; i--)
            B.number[i+k] = A.number[i];
        //set size of new number
        B.n = A.n + k;
        //filling first k digits of B with zeros
        for (i = 0; i < k; i++)
            B.number[i] = 0;
    }
    else B = A;

    return B;
}

//full completion time - 30 minutes
