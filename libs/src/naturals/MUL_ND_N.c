#pragma once

int *MUL_ND_N(int *numberOne, int number) {
    int i, One_size;
    numberOne[0] = One_size;
    numberOne[One_size] = numberOne[One_size] * number;
    if (numberOne[One_size] > 9) {
        int int_part = numberOne[i] / 10; //div numberOne[1]
        numberOne[i - 1] = numberOne[i - 1] + int_part; // div numberOne[i] to numberOne[i-1]
        numberOne[i] = numberOne[i] % 10; // replacement by balance
    }
    int n = One_size; // the size of a finite number
    if (numberOne[1] != 0) { //if the size is larger than the original
        n++;
        numberOne = (int *) realloc(numberOne, n * sizeof(int));
        for (i = n - 1; i > 0; i--) { //move the elements of the array
            numberOne[i] = numberOne[i - 1];
        }
        numberOne[1] = 0;//assign the sign coefficient
        numberOne[0]++;
    }
    return numberOne;
}