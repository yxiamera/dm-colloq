#pragma once
#include "../../integer.h"
#include <stdio.h>
#include <stdlib.h>
//Вычитание целых чисел (результат - целое число)
//Об авторе:
//Петрова Елизавета Михайловна гр. № 7307, ФКТИ
//https://sites.google.com/view/petrovaliza7307
//e-mail: ostenok@gmail.com


int* SUB_ZZ_Z(int* input1, int* input2){
    int* result_num;
    int* num1;
    int* num2;
    int i;


    num1 = ABS_Z_N(input1); //подсчитываем абсолютное значение введенных чисел (натуральные числа)
    num2 = ABS_Z_N(input2);
    if (((POZ_Z_D(input1) == 2) && (POZ_Z_D(input2) == 2)) || ((POZ_Z_D(input1) == 0) && (POZ_Z_D(input2) == 0)) || ((POZ_Z_D(input1) == 2) && (POZ_Z_D(input2) == 0)) || ((POZ_Z_D(input1) == 0) && (POZ_Z_D(input2) == 2))){
        //если оба числа одновременно положительные, или одновременно равны нулю,
        // или одно из чисел положительное, а второе равно нулю, то
        if ((COM_NN_D(num1, num2) == 2) || (COM_NN_D(num1, num2) == 0)){
            //если по модулю первое число больше либо равно второму
            result_num = (SUB_NN_N(num1, num2)); //вычитаем второе число из первого
        }
        else{ //если второе число по модулю больше первого, вычитаем первое число из второго
            result_num = (SUB_NN_N(num2, num1));
            result_num = (int*)realloc(result_num, result_num[0] + 2); //представляем полученную разность в виде положительного целого числа
            for (i = result_num[0] + 1; i > 1; i--){
                result_num[i] = result_num[i - 1];
            }
            result_num[1] = 0;
            return (MUL_ZM_Z(result_num)); //меняем у полученного числа знак
        }
    }
    if (((POZ_Z_D(input1) == 2) && (POZ_Z_D(input2) == 1)) || ((POZ_Z_D(input1) == 0) && (POZ_Z_D(input2) == 1))){
        //если первое число воложительное, а второе отрицательное, или первое число равно нулю, а второе отрицательное, то
        result_num = (ADD_NN_N(num1, num2)); //складываем модули двух чисел
    }
    if (((POZ_Z_D(input1) == 1) && (POZ_Z_D(input2) == 2)) || ((POZ_Z_D(input1) == 1) && (POZ_Z_D(input2) == 0))){
        //если первое число отрицательное, а второе положительное, или первое число отрицательное, а второе равно нулю
        result_num = (ADD_NN_N(num1, num2)); //подсчитываем сумму модулей чисел
        result_num = (int*)realloc(result_num, result_num[0] + 2); //представляем полученную сумму в виде положительного целого числа
        for (i = result_num[0] + 1; i > 1; i--){
            result_num[i] = result_num[i - 1];
        }
        result_num[1] = 0;
        return (MUL_ZM_Z(result_num)); //меняем у полечнной суммы знак
    }
    if (((POZ_Z_D(input1) == 1) && (POZ_Z_D(input2) == 1))){
        //если оба числа одновременно отрицательные, то
        if ((COM_NN_D(num2, num1) == 2) || (COM_NN_D(num2, num1) == 0)){
            //если второе число по модулю больше первого или модули двух чисел равны
            result_num = SUB_NN_N(num2, num1); //вычитаем первое число из второго
        }
        else{ //если второе число по модулю меньше первого, то
            result_num = SUB_NN_N(num1, num2); //вычитаем из первого числа второе
            result_num = (int*)realloc(result_num, result_num[0] + 2); //представляем полученную разность в виде полжительного целого числа
            for (i = result_num[0] + 1; i > 1; i--){
                result_num[i] = result_num[i - 1];
            }
            result_num[1] = 0;
            return (MUL_ZM_Z(result_num)); //меняем у полученного числа знак
        }
    }
    result_num = (int*)realloc(result_num, result_num[0] + 2); //полчуенное результат представляем как положительное целое число
    for (i = result_num[0] + 1; i > 1; i--){
        result_num[i] = result_num[i - 1];
    }
    result_num[1] = 0; //знаковый коэффициент равен 0, так как число положительное
    return result_num;
}
//Время выполнения работы: 30 минут