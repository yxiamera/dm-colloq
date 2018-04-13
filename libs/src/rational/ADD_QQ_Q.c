//
// Created by User on 4/13/2018.
//

#include "../polynome/Polynome.c"

int** ADD_QQ_Q(int** F1, int** F2) {
    //сложение дробей без сокращения
    int** F = (int **)malloc(2 * sizeof(int*));
    F[0] = init_integer(get_integer(F1[0])*get_integer(F2[1])+get_integer(F2[0])*get_integer(F1[1]));
    F[1] = init_integer(get_integer(F1[1])*get_integer(F2[1]));
    return F;
}

