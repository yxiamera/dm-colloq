#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "../../integer.h"

//Абсолютная величина числа, результат - натуральное
//Об авторе:
//Петрова Елизавета Михайловна гр. № 7307, ФКТИ
//https://sites.google.com/view/petrovaliza7307
//e-mail: ostenok@gmail.com


int* ABS_Z_N(int* num) {
    int* result_num;
    int i;
    int div = num[0]; //количество цифр в изначальном числе

    result_num = (int*)calloc(div + 1, sizeof(int));
    result_num[0] = div;  //количество цифр в модуле числа совпадает с количеством цифр в самом числе
    for (i = 1; i < div + 1; i++){  //копируем цифры исходного числа в искомое натуральное, начиная от старших разрядов к младшим
        result_num[i] = num[i + 1];
    }
    return result_num;
}
//Время выполнения: 10 минут
//Логических строк кода: 3 (???)
