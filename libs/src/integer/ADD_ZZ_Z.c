/*
	Выполнил: Шалашников Максим Игоревич
	
	Назначение: Сложение целых чисел
	Возвращаемое значение: Целое число
	Параметры: 2 Целых числа
*/
#pragma once
#include "../../integer.h"
#include "./POZ_Z_D.c"
#include "./MUL_ZM_Z.c"


int* ADD_ZZ_Z(int *numberOne,int *numberTwo) {
	int i,j,One_size,Two_size, *result;
	if ((POZ_Z_D(numberOne)==2)&&(POZ_Z_D(numberTwo)==2)){ //if numberOne(+) and numberTwo(+)
		result = ADD_NN_N(numberOne,numberTwo); //simply the sum of two numbers
	}
	if ((POZ_Z_D(numberOne)==2)&&(POZ_Z_D(numberTwo)!=2)){// if numberOne(+) and numberTwo(-)
		numberTwo=ABS_Z_N(numberTwo);// Absolute value of number
		if (COM_NN_D(numberOne,numberTwo)==2){//numberOne>numberTwo
			result = SUB_NN_N(numberOne,numberTwo); //difference of two numbers
		}
		if (COM_NN_D(numberOne,numberTwo)!=2){//numberOne<numberTwo
			result = SUB_NN_N(numberTwo,numberOne);//numberTwo-numberOne
			result = MUL_ZM_Z(result);//result*(-1)
		}
	}
	if ((POZ_Z_D(numberOne)!=2)&&(POZ_Z_D(numberTwo)==2)){// if numberOne(-) and numberTwo(+)
		numberOne=ABS_Z_N(numberTwo);// Absolute value of number
		if (COM_NN_D(numberOne,numberTwo)==2){//numberOne>numberTwo
			result = SUB_NN_N(numberOne,numberTwo);
			result = MUL_ZM_Z(result);
		}
		if (COM_NN_D(numberOne,numberTwo)!=2){//numberOne<numberTwo
			result = SUB_NN_N(numberTwo,numberOne);
		}
	}
	if ((POZ_Z_D(numberOne)!=2)&&(POZ_Z_D(numberTwo)!=2)){// if numberOne(-) and numberTwo(-)
		numberTwo = ABS_Z_N(numberTwo);// Absolute value of number
		numberOne = ABS_Z_N(numberTwo);// Absolute value of number
		result = ADD_NN_N(numberOne,numberTwo);//simply the sum of two numbers
		result = MUL_ZM_Z(result);//result*(-1)
	}
	return result;
}