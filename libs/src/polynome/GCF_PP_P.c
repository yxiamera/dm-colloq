//Об авторе:
//Николаева Екатерина Валерьевна, ФКТИ гр.№7307
//https://sites.google.com/site/nikolaevayekaterina7307/
//e-mail: enterfox101@gmail.com
#pragma once
#include <stdlib.h>
#include "Polynome.c"
#include "../rational/MOD_PP_P.c"

mod_4 *GCF_PP_P(mod_4 P1, mod_4 P2){
    //setup variables
    mod_4 *A, *B, *C;
    A = allocate_mod_4(P1.m);
    *A = P1;
    B = allocate_mod_4(P2.m);
    *B = P2;
    //Ecluid algorithm
    do {
        //get modulo of A and B polynomials
        C = MOD_PP_P(*A, *B);
        //empty A
        free (A->numerator);
        free (A->denominator);
        free (A);
        //assign A and B polynomial pointers for next cycle
        A = B;
        B = C;
        //do while polynomial B (= C) != 0;
    } while (!(B->m==0 && B->numerator[0][0]==0 && B->numerator[0][2]==0));
    //empty polynomial pointers
    free (B->numerator);
    free (B->denominator);
    free (B);
    free (C->numerator);
    free (C->denominator);
    free (C);
    return A;
}

//full completion time - about 4 hours
