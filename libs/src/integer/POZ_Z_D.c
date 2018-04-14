#pragma once
#include "../../integer.h"


/*
	Выполнил:
	Ермоленко Валерий Эдуардович гр. 7307
 	https://sites.google.com/site/lazzyvaleriyermolenko1999/home
	Определение положительности числа (2 - положительное, 0 — равное нулю, 1 - отрицательное)
	На выполнение понадобилось 5 минут
	Логических строк кода: 9
*/

int POZ_Z_D(int *input) {
	int size = input[0];
	
	if (input[1] == 1) {
		return 1;
	}
	else {
		if (input[2] != 0){
		return 2;
		}
		else {
			return 0;
		}
	}
}

