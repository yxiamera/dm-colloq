#include "ADD_PP_P.c"
#include "Polynome.c"

mod_4 *SUB_PP_P(mod_4 polynomialMinuend, mod_4 polynomialSubtrahend)
{
    for (int i = 0; i <= polynomialSubtrahend.m; i++) {
        polynomialSubtrahend.numerator[i][1] = 1 - polynomialSubtrahend.numerator[i][1];
    }
    print_mod_4(polynomialSubtrahend);
    return ADD_PP_P(polynomialMinuend, polynomialSubtrahend);
}