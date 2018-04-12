#pragma once
#include "COM_NN_D.c"

int* ADD_NN_N(int *numberOne, int *numberTwo) {
    int i,j,int_part,n;
    int One_size = numberOne[0];//select the size of the first array
    int Two_size = numberTwo[0];//select the size of the second array
    if ((numberOne[1]!=0)||(numberTwo[1]!=0)){ //check for a natural number
        printf ("Error! This is not a natural number\n");
        return 0;
    }
    if (COM_NN_D(numberOne,numberTwo)==2){ // if Number 1 > number 2
        for (i=One_size,j=Two_size;j>1;i--,j--){
            numberOne[i]=numberOne[i]+numberTwo[j];
            if (numberOne[i]>9){
                int_part=numberOne[i]/10; //div numberOne[1]
                numberOne[i-1]=numberOne[i-1]+int_part; // div numberOne[i] to numberOne[i-1]
                numberOne[i]=numberOne[i]%10; // replacement by balance
            }
        }
        n=One_size; // the size of a finite number
        if (numberOne[1]!=0){ //if the size is larger than the original
            n++;
            numberOne=(int*)realloc(numberOne,n*sizeof(int));
            for (i=n-1;i>0;i--){ //move the elements of the array
                numberOne[i]=numberOne[i-1];
            }
            numberOne[1]=0;//assign the sign coefficient
            numberOne[0]++;
        }
        return numberOne;
    }else{ //same thing only when Number 2 > Number 1
        for (i=Two_size,j=One_size;j>0;i--,j--){
            numberTwo[i]=numberTwo[i]+numberOne[j];
            if (numberTwo[i]>9){
                int_part=numberTwo[i]/10;
                numberTwo[i-1]=numberTwo[i-1]+int_part;
                numberTwo[i]=numberTwo[i]%10;
            }
        }
        n=Two_size;
        if (numberTwo[1]!=0){
            n++;
            numberTwo=(int*)realloc(numberTwo,n*sizeof(int));
            for (i=n-1;i>0;i--){
                numberTwo[i]=numberTwo[i-1];
            }
            numberTwo[1]=0;
            numberTwo[0]++;
        }
        return numberTwo;
    }
}
