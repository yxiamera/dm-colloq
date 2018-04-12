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

/* //стандартный алгоритм евклида
int GCD(int a, int b){
    if (a == 0 || b == 0){
        return 0 // error
    }
    int c;
    do {
        c = a%b;
        a = b;
        b = c;
    } while (b!=0);
    return a;
};*/

mod_4 *MOD_PP_P(mod_4 P1, mod_4 P2){
    //всегда выводит нулевой многочлен
    mod_4 *P = allocate_mod_4(0);
    P->numerator[0] = init_integer(0);
    P->denominator[0] = init_integer(1);
    return P;
};

mod_4 *GCF_PP_P(mod_4 P1, mod_4 P2){
    mod_4 *A, *B, *C;
    A = allocate_mod_4(P1.m);
    *A = P1;
    B = allocate_mod_4(P2.m);
    *B = P2;
    //алгоритм
    do {
        C = MOD_PP_P(*A, *B);
        free (A->numerator);
        free (A->denominator);
        free (A);
        A = B;
        B = C;
    } while (!(B->m==0 && B->numerator[0][0]==0 && B->numerator[0][2]==0));
    free (B->numerator);
    free (B->denominator);
    free (B);
    free (C->numerator);
    free (C->denominator);
    free (C);
    return A;
}

int main()
{
    mod_4 *P1 = init_mod_4();
    print_mod_4(*P1);
    mod_4 *P2 = init_mod_4();
    print_mod_4(*P2);

    mod_4 *P = GCF_PP_P(*P1,*P2);
    printf("Answer\n");
    print_mod_4(*P);
}

//время выполнения - около 4-х часов
