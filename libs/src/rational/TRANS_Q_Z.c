//From a fraction to integer (denominator of a fraction is 1)
//About the author:
//Petrova Elizaveta Mikhailovna, group ¹7307
//https://sites.google.com/view/petrovaliza7307
//e-mail: ostenok@gmail.com


int* TRANS_Q_Z (int** fract){
    int* integer;
    int i;
    int div = fract[0][0]; //number of digits
    int sign = fract[0][1];

    integer = (int*)calloc(div + 2, sizeof(int));
    integer[0] = div;
    integer[1] = sign;
    for (i = 2; i < div + 2; i++){ //result integer is equal to the numerator of the fraction
        integer[i] = fract[0][i];
    }
    return integer;
}