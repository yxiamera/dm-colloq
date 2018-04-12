//
// Created by Nick2 on 30.03.2018.
//
struct mod_4
{
    int *m;
    int **numerator;
    int **denominator;
};
int COM_NN_D(int *m1, int *m2) // сравнение натуральных чисел
{
    //delete when constructing

}
int * SUB_ZZ_Z(int * a, int* b); // вычитание цеых чисел
int** LED_P_Q(struct mod_4 a) // старший коэф многочлена
{

}
int **DIV_QQ_Q(int** a, int** b) // деление дробей
{

}
struct mod_4 MUL_Pxk_P(struct mod_4 a, struct mod_4 b); // умножение на x^k если использовать алгоритм данный
// на лекции то эта функция не нужна

int* DEG_P_N(struct mod_4 a); // вычисление степени
struct mod_4 MUL_PP_P(struct mod_4 a, struct mod_4 b);
struct mod_4 SUB_PP_P(struct mod_4 a, struct mod_4 b); // вычитание многочленов
struct mod_4 ADD_PP_P(struct mod_4 a, struct mod_4 b); // сложение многочленов
#include <stdlib.h>
#include "DIV_PP_P .h"
// делал по алгоритму Позднякова, данного на лекции 31.03.2018
struct mod_4 DIV_PP_P(struct mod_4 polynomialDividend, struct mod_4 polynomialDivider)
{   struct mod_4 polynomialQuotient; // частное от деления
    // инициализация структуры
    polynomialQuotient.m = malloc(sizeof(int));
    // степень 0
    polynomialQuotient.m = 0;
    // выделяем память под числитель и знаменатель
    polynomialQuotient.numerator = malloc(sizeof(int*));
    polynomialQuotient.denominator = malloc(sizeof(int*));
    polynomialQuotient.numerator[0] = malloc(3 * sizeof(int));
    polynomialQuotient.denominator[0] = malloc(3 * sizeof(int));
    // ставим размерность 1
    polynomialQuotient.numerator[0][0] = 1;
    polynomialQuotient.denominator[0][0] = 1;
    //знак числителя +
    polynomialQuotient.numerator[0][1] = 0;
    // значение числителя 0
    polynomialQuotient.numerator[0][2] = 0;
    // знак знаменателя +
    polynomialQuotient.denominator[0][1] = 0;
    // значение знаменателя 1
    polynomialQuotient.numerator[0][2] = 1;
    // степень делимого меньше степени делителя. Если да, то частное это 0
    struct mod_4 polynomialTmp, polynomialRest = polynomialDividend; // временная структура для выполнения операций
    // пока степень остатка больше или равна степени делтеля
    while(COM_NN_D(polynomialRest.m ,polynomialDivider.m) != 1)
    {
        //  polynomialTmp = (L(R(x)))/L(N(x)) * x ^(deg R(x) - deg N(x)), где R - остаток , N - делитель ,
        // L() - лидирующий коэф. многочлена , deg() - макс степень многочлена
        polynomialTmp.m = SUB_ZZ_Z(DEG_P_N(polynomialRest),DEG_P_N(polynomialDivider));
        polynomialTmp.numerator[0] = DIV_QQ_Q(LED_P_Q(polynomialRest),LED_P_Q(polynomialDivider))[0];
        polynomialTmp.denominator[0] = DIV_QQ_Q(LED_P_Q(polynomialRest),LED_P_Q(polynomialDivider))[1];
        // прибавляем к частному "созданный" многочлен
        polynomialQuotient = ADD_PP_P(polynomialQuotient,polynomialTmp);
        // вычитаем из остатка "созданный" многочлен * вычитаемое
        polynomialRest = SUB_PP_P(polynomialRest,MUL_PP_P(polynomialDivider,polynomialTmp));
    }
    return  polynomialQuotient;
}