//Об авторе:
//Николаева Екатерина Валерьевна, ФКТИ гр.№7307
//https://sites.google.com/site/nikolaevayekaterina7307/
//e-mail: enterfox101@gmail.com
#pragma once
#include <stdlib.h>
#include "Polynome.c"
#include "../rational/ADD_QQ_Q.c"



mod_4 *ADD_PP_P(mod_4 P1, mod_4 P2) {
    //finding polynomials with bigger and smaller amount of coefficients (needed to know which polynomial takes more memory)
    mod_4 *max_p, *min_p;
    if (P1.m>P2.m){
        max_p = &P1;
        min_p = &P2;
    } else {
        max_p = &P2;
        min_p = &P1;
    }
    //allocate polynomial with max_p->m degree
    mod_4 *P = allocate_mod_4(max_p->m);

    //adding coef. of min_p with coef. of max_p
    int *F1[2], *F2[2], **F;
    int i,j;
    for (i=0;i<=min_p->m;i++){
        //for each coefficient create fractions for both polynomials
        F1[0] = max_p->numerator[i];
        F1[1] = max_p->denominator[i];
        F2[0] = min_p->numerator[i];
        F2[1] = min_p->denominator[i];
        //add them together
        F = ADD_QQ_Q(F1,F2);
        //set result coef. to result of the function
        P->numerator[i] = F[0];
        P->denominator[i] = F[1];
        //free memory
        free(F1[0]);
        free(F1[1]);
        free(F2[0]);
        free(F2[1]);
    }


    //copy the rest coef. of max_p into result
    for (i=min_p->m+1;i<=max_p->m;i++){
        //allocate memory
        P->numerator[i] = (int *)malloc((max_p->numerator[i][0]+3) * sizeof(int));
        P->denominator[i] = (int *)malloc((max_p->denominator[i][0]+3) * sizeof(int));
        //copy numerator
        for (j=0; j<=P->numerator[i][0]+2; j++) {
            P->numerator[i][j] = max_p->numerator[i][j];
        }
        //copy denominator
        for (j=0; j<=P->denominator[i][0]+2; j++) {
            P->denominator[i][j] = max_p->denominator[i][j];
        }
    }

    return P;
}

//full completion time - about 7 hours
