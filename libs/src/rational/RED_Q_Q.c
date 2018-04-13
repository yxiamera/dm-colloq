/*
	Выполнил: Шалашников Максим Игоревич
	
	Назначение: Сокращение дроби
	Возвращаемое значение: Целое число и натуральное
	Параметры: Целое число и натуральное
*/


int** RED_Q_Q(int **fraction) {
	int *NOD;
	int *numberOne,*numberTwo;
	numberOne=fraction[0];//Numerator
	numberTwo=fraction[1];//Denominator
	if (POZ_Z_D(numberOne)==2){ // if numerator >0
		NOD=GCF_NN_N(numberOne,numberTwo); // find GCF
		numberOne = DIV_ZZ_Z (numberOne,NOD); //divide the numerator by GCF
		numberTwo = DIV_ZZ_Z (numberTwo,NOD); //divide the denomerator by GCF
	}
	if (POZ_Z_D(numberOne)!=2){ // if numerator <0
		numberOne=ABS_Z_N(numberOne);//Absolute value of number
		NOD=GCF_NN_N(numberOne,numberTwo); // find GCF
		numberOne = DIV_ZZ_Z (numberOne,NOD);//divide the numerator by GCF
		numberTwo = DIV_ZZ_Z (numberTwo,NOD);//divide the denomerator by GCF
	}
	fraction[0]=numberOne;
	fraction[1]=numberTwo;
	return fraction;
}