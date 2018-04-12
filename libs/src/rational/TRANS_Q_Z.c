#include <stdio.h>
#include <stdlib.h>
//Преобразование дробного в целое (если знаменатель равен 1)
//Об авторе:
//Петрова Елизавета Михайловна гр. № 7307, ФКТИ
//https://sites.google.com/view/petrovaliza7307
//e-mail: ostenok@gmail.com


int* TRANS_Q_Z (int** fract){
    int* integer;
    int i;
    int div = fract[0][0]; //количество цифр в искомом целом числе совпадает с количеством цифр числителя исходной рациональной дроби
    int sign = fract[0][1]; //знак искомого целого числа совпадает со знаком числителя исходной рациональной дроби

    integer = (int*)calloc(div + 2, sizeof(int));
    integer[0] = div;
    integer[1] = sign;
    for (i = 2; i < div + 2; i++){ //искомое целое число будет совпадать с числителем исходной рациональной дроби
        integer[i] = fract[0][i];
    }
    return integer;
}
//Время выполнения: 15 минут
//Логических строк кода: 6 (???)
