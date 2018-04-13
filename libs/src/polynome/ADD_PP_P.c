//выполнила Николаева Екатерина
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Polynome.c"
#include "../rational/ADD_QQ_Q.c"



mod_4 *ADD_PP_P(mod_4 P1, mod_4 P2) {
    //определяем многочлены с большей и меньшей степенью
    mod_4 *max_p, *min_p;
    if (P1.m>P2.m){
        max_p = &P1;
        min_p = &P2;
    } else {
        max_p = &P2;
        min_p = &P1;
    }
    mod_4 *P = allocate_mod_4(max_p->m);

    //складываем коэффициенты min_p с коэфф. многочлена max_p , т.к. степени их одночленов больше чем степень многочлена min_p
    int *F1[2], *F2[2], **F;
    int i,j;
    for (i=0;i<=min_p->m;i++){
        F1[0] = max_p->numerator[i];
        F1[1] = max_p->denominator[i];
        F2[0] = min_p->numerator[i];
        F2[1] = min_p->denominator[i];
        F = ADD_QQ_Q(F1,F2);
        P->numerator[i] = F[0];
        P->denominator[i] = F[1];
        free(F1[0]);
        free(F1[1]);
        free(F2[0]);
        free(F2[1]);
    }


    //переносим оставшиеся коэффициенты из max_p
    for (i=min_p->m+1;i<=max_p->m;i++){
        P->numerator[i] = (int *)malloc((max_p->numerator[i][0]+3) * sizeof(int));
        P->denominator[i] = (int *)malloc((max_p->denominator[i][0]+3) * sizeof(int));
        for (j=0; j<=P->numerator[i][0]+2; j++) {
            P->numerator[i][j] = max_p->numerator[i][j];
        }
        for (j=0; j<=P->denominator[i][0]+2; j++) {
            P->denominator[i][j] = max_p->denominator[i][j];
        }
    }

    return P;
}

//int main()
//{
//    mod_4 P1 = *init_mod_4();
//    print_mod_4(P1);
//    mod_4 P2 = *init_mod_4();
//    print_mod_4(P2);
//
//    print_mod_4(*ADD_PP_P(P1,P2));
//
//    return 0;
//}

//время создания - около 7-ми часов
