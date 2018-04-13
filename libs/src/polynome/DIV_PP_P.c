//About author:
//Ефимчик Никита Валерьевич, ФКТИ гр.№7307
//https://sites.google.com/site/efimchiknikita7307/home
//e-mail: efimchikofficial@gmail.com
struct mod_4
{
    int m;
    int **numerator;
    int **denominator;
};

int DEG_P_N(struct mod_4 a); // вычисление степени
struct mod_4 MUL_PP_P(struct mod_4 a, struct mod_4 b);
struct mod_4 SUB_PP_P(struct mod_4 a, struct mod_4 b); // вычитание многочленов
struct mod_4 ADD_PP_P(struct mod_4 a, struct mod_4 b); // сложение многочленов
#include <stdlib.h>
#include "DIV_PP_P .h"
// делал по алгоритму Позднякова, данного на лекции 31.03.2018
struct mod_4 DIV_PP_P(struct mod_4 polynomialDividend, struct mod_4 polynomialDivider)
{   struct mod_4 polynomialQuotient; // частное от деления
    // degree 0
    polynomialQuotient.m = 0;
    // alloc memory for numerator and denominator
    polynomialQuotient.numerator = malloc(sizeof(int*));
    polynomialQuotient.denominator = malloc(sizeof(int*));
    polynomialQuotient.numerator[0] = malloc(3 * sizeof(int));
    polynomialQuotient.denominator[0] = malloc(2 * sizeof(int));
    // dimension is 1
    polynomialQuotient.numerator[0][0] = 1;
    polynomialQuotient.denominator[0][0] = 1;
    //sign of numerator is +
    polynomialQuotient.numerator[0][1] = 0;
    // value of numerator is 0
    polynomialQuotient.numerator[0][2] = 0;
    // value of denominator is 1
    polynomialQuotient.denominator[0][1] = 1;
    // степень делимого меньше степени делителя. Если да, то частное это 0
    // пока степень остатка больше или равна степени делтеля
    // if degree of dividend less then degree of Divider then quotient is 0
    // while degree of remainder >= degree of Divider
    struct mod_4 polynomialTmp, polynomialRemainder = polynomialDividend;
    while(polynomialRemainder.m >= polynomialDivider.m)
    {
        //  polynomialTmp = (L(R(x)))/L(N(x)) * x ^(deg R(x) - deg N(x)), where  R - remainder , N - Divider ,
        // L() - лидирующий коэф. многочлена , deg() - макс степень многочлена
        // L() - leading coefficient of a polynomial , deg() - max degree of polynomial
        polynomialTmp.m = DEG_P_N(polynomialRemainder) - DEG_P_N(polynomialDivider);
        polynomialTmp.numerator[0] = DIV_QQ_Q(LED_P_Q(polynomialRemainder),LED_P_Q(polynomialDivider))[0];
        polynomialTmp.denominator[0] = DIV_QQ_Q(LED_P_Q(polynomialRemainder),LED_P_Q(polynomialDivider))[1];
        // прибавляем к частному "созданный" многочлен
        // add to Quotient created polynomial
        polynomialQuotient = ADD_PP_P(polynomialQuotient,polynomialTmp);
        // вычитаем из остатка "созданный" многочлен * делитель
        //subtracting  (created polynomial)* Divider from remainder
        polynomialRemainder = SUB_PP_P(polynomialRemainder,MUL_PP_P(polynomialDivider,polynomialTmp));
    }
    return  polynomialQuotient;
}