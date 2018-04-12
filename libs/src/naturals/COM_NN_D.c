#pragma once

int COM_NN_D(int* numOne, int* numTwo)
{
    int sizeOne = numOne[0];//number of digits of the first number
    int sizeTwo = numTwo[0];//number of digits of the second number

    if(sizeOne > sizeTwo) //if the number of digits of the first number is greater than the second
        return 2;
    else if(sizeOne < sizeTwo) //if less
        return 1;

    //if the number of digits is the same
    for(int i = 0; i <=sizeOne; i++) //we compare the highest digits of the numbers
    {
        if (numOne[i] > numTwo[i])
            return 2;
        else if(numOne[i] < numTwo[i])
            return 1;
    }
    return 0;
}