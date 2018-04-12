#pragma once
#include <stdio.h>
#include <stdlib.h>
//Добавление к натуральному числу 1
//Об авторе:
//Петрова Елизавета Михайловна гр. № 7307, ФКТИ
//https://sites.google.com/view/petrovaliza7307
//e-mail: ostenok@gmail.com


int *ADD_1N_N(int *input_num) {
    int div = input_num[0];   //считывает количество цифр в числе
    int index = div;
    int i;
    int *result_num;

    if (input_num[index] != 9){ //если цифра в самом младшем разряде числа не равна 9, то
        input_num[index]++;     //увеличиваем эьу цфиру на единицу
        return input_num;
    }
    else{
        while ((input_num[index] == 9) && (index != 0)){  //если цифра в младшем разряде равна 9, ищем в числе первую цифру, не равнуб 9
            input_num[index] = 0;    //все цифры числа, равные 9, заменяем нулями
            index--;
        }
        if (index == 0){      //если в числе есть только цифры 9, то добавляем к числу один старший разряд
            div += 1;
            result_num = (int*)calloc((div + 1), sizeof(int));
            result_num[0] = div;
            result_num[1] = 1;  //в старшем разряде числа помещаем единицу
            for (i = 2; i < div + 1; i++){
                result_num[i] = 0;   //все остальные цифры числа заменяем нулями
            }
        }
        else{
            input_num[index] += 1;  //если в числе была найдена цифра, не равная 9, она увеличивается на единицу
            return input_num;
        }
    }
    return result_num;
}
//Время выполнения: 15 минут
