#include <stdio.h>
#include <stdlib.h>
//Степень многочлена
//Об авторе:
//Петрова Елизавета Михайловна гр. № 7307, ФКТИ
//https://sites.google.com/view/petrovaliza7307
//e-mail: ostenok@gmail.com


long long DEG_P_N (struct mod_4* pol){
    int i;
    long long pow = pol.m; //считываем старшую степень многочлена

    for (i = 0; i < pow; i++){
        if (pol.numeratot[i][0] != 0){ //если коэффициент при старшей степени не равен нулю, то текущая старшая степень ялвяется искомой
            return pow;
        }
        else{   //если коэффициент при степени равен нулю, то уменьшаем значение степени
            pow = pow - 1;
        }
    }
    return pow;
}
//Время выполнения: 10 минут
//Логических строк кода: 6 (???)
