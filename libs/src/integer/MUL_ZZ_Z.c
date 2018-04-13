#pragma once
#include "../../integer.h"
#include "../../naturals.h"
/*
	Выполнил:
	Ермоленко Валерий Эдуардович гр. 7307
	Умножение целых чисел		
	На выполнение понадобилось 40 минут
	Логических строк кода: 31
*/

int* MUL_ZZ_Z(int *numberOne,int *numberTwo) {
	int i,j,One_size,Two_size, *result;
	if ((POZ_Z_D(numberOne)==2)&&(POZ_Z_D(numberTwo)==2)){ //if numberOne(+) and numberTwo(+)
		for (i = 1; i < One_size; i++){    //Z -> N
			numberOne[i] = numberOne[i+1];
		}
		numberOne[One_size] = NULL;
		One_size = One_size - 1;
		for (i = 1; i < Two_size; i++){
			numberTwo[i] = numberTwo[i+1];
		}
		numberTwo[Two_size] = NULL;
		Two_size = Two_size - 1;
		result = MUL_NN_N(numberOne,numberTwo); //simply the mul of two numbers
	}
	if ((POZ_Z_D(numberOne)==2)&&(POZ_Z_D(numberTwo)!=2)){// if numberOne(+) and numberTwo(-)
		numberTwo=ABS_Z_N(numberTwo);// Absolute value of number
		for (i = 1; i < One_size; i++){    //Z -> N
			numberOne[i] = numberOne[i+1];
		}
		numberOne[One_size] = NULL;
		One_size = One_size - 1;

		result = MUL_NN_N(numberOne,numberTwo); //simply the mul of two numbers
	}
	
	if ((POZ_Z_D(numberOne)!=2)&&(POZ_Z_D(numberTwo)==2)){// if numberOne(-) and numberTwo(+)
		numberOne=ABS_Z_N(numberOne);// Absolute value of number

		for (i = 1; i < Two_size; i++){
			numberTwo[i] = numberTwo[i+1];
		}
		numberTwo[Two_size] = NULL;
		Two_size = Two_size - 1;
		result = MUL_NN_N(numberOne,numberTwo);
	}
	
	if ((POZ_Z_D(numberOne)!=2)&&(POZ_Z_D(numberTwo)!=2)){// if numberOne(-) and numberTwo(-)
		numberTwo = ABS_Z_N(numberTwo);// Absolute value of number
		numberOne = ABS_Z_N(numberOne);// Absolute value of number
		result = MUL_NN_N(numberOne,numberTwo);//simply the mul of two numbers
	}
	return result;
}
