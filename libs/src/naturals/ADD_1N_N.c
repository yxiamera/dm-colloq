#pragma once
#include <stdio.h>
#include <stdlib.h>
//Adding 1 to a natural number
//About the author:
//Petrova Elizaveta Mikhailovna, group ¹7307
//https://sites.google.com/view/petrovaliza7307
//e-mail: ostenok@gmail.com


int *ADD_1N_N(int *input_num) {
    int div = input_num[0];   //
    int index = div;
    int i;
    int *result_num;

    if (div == 0){ //if initial number is 0
        input_num = (int*)realloc(input_num, 2*sizeof(int));
        input_num[0] = 1;
        input_num[1] = 1;
        return input_num;
    }
    if (input_num[index] != 9){ //if the last digit in the number is not 9,
        input_num[index]++;     //add 1 to this digit
        return input_num;
    }
    else{
        while ((input_num[index] == 9) && (index != 0)){  //if the last digit is 9 then search for the digit which is not 9
            input_num[index] = 0;    //replace all the 9's with 0
            index--;
        }
        if (index == 0){      //if there are no digit which is not 9, add another one digit
            div += 1;
            result_num = (int*)calloc((div + 1), sizeof(int));
            result_num[0] = div;
            result_num[1] = 1;  //the highest digit is 1
            for (i = 2; i < div + 1; i++){
                result_num[i] = 0;   //other digits are 0
            }
        }
        else{
            input_num[index] += 1;  //if a non-9 digit if found add 1 to this digit
            return input_num;
        }
    }
    return result_num;
}
//Time for doing: 15 минут
