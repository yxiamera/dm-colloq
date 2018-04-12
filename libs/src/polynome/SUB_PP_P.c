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
int *SUB_ZZ_Z(int *big, int *small) // вычитание целых чисел
{
    //delete when constructing

}
int POZ_Z_D(int *a) //проверка положительность
{

}
#include <stdlib.h>
#include <mem.h>
#include "SUB_PP_P.h"
struct mod_4 SUB_PP_P(struct mod_4 polynomialMinuend, struct mod_4 polynomialSubtrahend)
{
    unsigned long long int i = 0; // переменная для определения места коэффицента(счетчик)
    struct mod_4 polynomialResult; // Результирующий многочлне
    // Наибольшая степень нового многочлена = max(степень уменьшаемого, степень вычитаемого)
    if (COM_NN_D(polynomialMinuend.m, polynomialSubtrahend.m) == 2)
        polynomialResult.m = polynomialMinuend.m;
    else
        polynomialResult.m = polynomialSubtrahend.m;

    // массив состоящий только из одной единицы. Создан для корректной работы функции SUB_ZZ_Z
    int* One = malloc(sizeof(int) * 3);
    // размерность
    One[0] = 1;
    // знак
    One[1] = 0;
    // значение
    One[2] = 1;

    // если степень вычитаемого больше степени уменьшаемого то все коэффиценты при степенях больших самой большой
    // степени уменьшаемого копируются в результирующий многочлен с обратным знаком(был + станет - и наоборот)
    while ( COM_NN_D( polynomialSubtrahend.m, polynomialMinuend.m) == 2 )
    {   // переносим коэффицент
        polynomialResult.numerator = realloc(polynomialResult.numerator,
                                             (size_t) ((i+1) * sizeof( unsigned long long int* )));
        polynomialResult.denominator = realloc(polynomialResult.denominator,
                                             (size_t) ((i+1) * sizeof( unsigned long long int* )));
        polynomialResult.numerator[i] = malloc(sizeof(int) *  polynomialSubtrahend.numerator[i][0]);
        // копируем данные в другую ячеёку памяти дабы не изменять значения в polynomialSubtrahend, т.к они в дальнейшем используются
           memcpy(polynomialResult.numerator[i],polynomialSubtrahend.numerator[i], sizeof(polynomialSubtrahend.numerator[i]));
        memcpy(polynomialResult.denominator[i],polynomialSubtrahend.denominator[i], sizeof(polynomialSubtrahend.denominator[i]));
        // инвертируем знак у числителя
        if (polynomialSubtrahend.numerator[i][1] == 0)
            polynomialResult.numerator[i][1] = 1;
        else
            polynomialResult.numerator[i][1] = 0;
        // уменьшаем степень вычитаемого на 1
        polynomialSubtrahend.m = SUB_ZZ_Z(polynomialSubtrahend.m, One);
        i++;

    }
    // Теперь степени вычитаемго и уменьшаемого равны.
    // Вычитаем из соответствующих коэффицентов уменьшаемого соответствующие коэффиценты
    // вычитаемого и записываем в результирующий многочлен
    while (POZ_Z_D(polynomialMinuend.m) != 1) // пока степень m не отрицательная
    {   //! Теперь все зависит от того как работает  SUB_ZZ_Z. Если она меняет polynomialMinuend.numerator[i], то нужно
        //! выполнить memcpy, если нет то все норм.
        polynomialResult.numerator[i] = SUB_ZZ_Z(polynomialMinuend.numerator[i],polynomialSubtrahend.numerator[i]);
        polynomialResult.denominator[i] = SUB_ZZ_Z(polynomialMinuend.denominator[i],polynomialSubtrahend.denominator[i]);
        i++;
        polynomialMinuend.m = SUB_ZZ_Z(polynomialMinuend.m,One);
    }
    return polynomialResult;

}