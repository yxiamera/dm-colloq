//выполнила Николаева Екатерина
#include <stdio.h>
#include <stdlib.h>

typedef struct mod_4 {
    int m;
    int** numerator;
    int** denominator;
}mod_4;

int count_digits(int number) {
    int digits=0;
    if (number < 0) {
        number *= -1;
    }
    while (number>=10) {
        digits += 1;
        number /= 10;
    }
    return digits;
};

int* init_integer(int number) {
    int i;
    int size = count_digits(number);
    int* Z = malloc((size+3) * sizeof(int));
    Z[0] = size;
    Z[1] = 0;
    for (i=2; i<=size+2; i++) {
        Z[i] = number%10;
        number /= 10;
    }
    return Z;
};

int get_integer(int* Z) {
    int number=0,power=1,i;
    for (i=2; i<=Z[0]+2; i++) {
        number += Z[i] * power;
        power *= 10;
    }
    return number;
};

mod_4 *allocate_mod_4(int m) {
    mod_4 *P = malloc(sizeof(mod_4));
    P->m = m;
    P->numerator = malloc((m+1) * sizeof(int*));
    P->denominator = malloc((m+1) * sizeof(int*));
    return P;
}

mod_4 *init_mod_4() {
    int m, i;
    printf ("Enter power of polynomial:");
    scanf ("%d", &m);
    mod_4 *P = allocate_mod_4(m);

    for (i=0; i<=m; i++){
        int num=0,den=1;
        printf ("Enter coefficient for power %d. If it's not integer, enter as rational fraction\n(example 1/2): ", i);
        scanf ("%d/%d", &num, &den);
        if (den==1)
            printf ("%d*x^%d\n", num, i);
        else
            printf ("%d/%d*x^%d\n", num, den, i);
        P->numerator[i]=init_integer(num);
        P->denominator[i]=init_integer(den);
    }

    return P;
};

void print_mod_4(mod_4 P){
    int i;
    printf("%d: \n", P.m);
    for (i=0;i<=P.m;i++){
        printf ("%d/%d", get_integer(P.numerator[i]), get_integer(P.denominator[i]));
        if (i > 0)
            printf("*x");
        if (i > 1)
            printf("^%d", i);
        if (P.m-i > 0)
            printf(" + ");
    }
    printf("\n");
};

int** ADD_QQ_Q(int** F1, int** F2) {
    //сложение дробей без сокращения
    int** F = malloc(2 * sizeof(int*));
    F[0] = init_integer(get_integer(F1[0])*get_integer(F2[1])+get_integer(F2[0])*get_integer(F1[1]));
    F[1] = init_integer(get_integer(F1[1])*get_integer(F2[1]));
    return F;
}

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
        P->numerator[i] = malloc((max_p->numerator[i][0]+3) * sizeof(int));
        P->denominator[i] = malloc((max_p->denominator[i][0]+3) * sizeof(int));
        for (j=0; j<=P->numerator[i][0]+2; j++) {
            P->numerator[i][j] = max_p->numerator[i][j];
        }
        for (j=0; j<=P->denominator[i][0]+2; j++) {
            P->denominator[i][j] = max_p->denominator[i][j];
        }
    }

    return P;
}

int main()
{
    mod_4 P1 = *init_mod_4();
    print_mod_4(P1);
    mod_4 P2 = *init_mod_4();
    print_mod_4(P2);

    print_mod_4(*ADD_PP_P(P1,P2));

    return 0;
}

//время создания - около 7-ми часов
