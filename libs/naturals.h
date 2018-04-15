//
// Created by User on 4/11/2018.
//
#pragma once

#include <stdio.h>
#include <malloc.h>
#include "src/naturals/ADD_1N_N.c"
#include "src/naturals/ADD_NN_N.c"
#include "src/naturals/COM_NN_D.c"
#include "src/naturals/DIV_NN_Dk.c"
#include "src/naturals/DIV_NN_N.c"
#include "src/naturals/GCF_NN_N.c"
#include "src/naturals/LCM_NN_N.c"
#include "src/naturals/MOD_NN_N.c"
#include "src/naturals/MUL_ND_N.c"
#include "src/naturals/MUL_Nk_N.c"
#include "src/naturals/MUL_NN_N.c"
#include "src/naturals/NZER_N_B.c"
#include "src/naturals/SUB_NDN_N.c"
#include "src/naturals/SUB_NN_N.c"


// For debugging and testing
char *str_repr(int *num); // String representation of natural, e.g. [3, 1, 2, 3] is represented as "3123"
void print_natural(int* num); // Outputs string representation to stdout

// For Pozdnyakov S.N.
int  COM_NN_D(int *, int *);
int NZER_N_B(int *);
struct natural ADD_1N_N(struct natural);
struct natural ADD_NN_N(struct natural, struct natural);
struct natural SUB_NN_N(struct natural, struct natural);
struct natural MUL_ND_N(struct natural, int );
struct natural MUL_Nk_N(struct natural, int );
struct natural MUL_NN_N(struct natural, struct natural);
struct natural SUB_NDN_N(struct natural, struct natural, int );
int  DIV_NN_Dk(struct natural, struct natural);
struct natural DIV_NN_N(struct natural, struct natural);
struct natural MOD_NN_N(struct natural, struct natural);
struct natural GCF_NN_N(struct natural, struct natural);
struct natural LCM_NN_N(struct natural, struct natural);

char *str_repr(int *num) {
    char *str = (char *)malloc(*num + 2);
    for (int i = 0; i < *num + 1; ++i) {
        str[i] = num[i] + '0';
    }
    str[num[0] + 1] = 0;
    return str;
}

void print_natural(int *num) {
    printf("%s\n", str_repr(num));
}
