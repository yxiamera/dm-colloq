//
// Created by User on 4/11/2018.
//

#ifndef DM_COLLOC_INTEGER_H
#define DM_COLLOC_INTEGER_H

#include <stdio.h>
#include <malloc.h>


// For debugging and testing
char *str_repr(int *num); // String representation of natural, e.g. [3, 1, 2, 3] is represented as "3123"
void print_natural(int* num); // Outputs string representation to stdout

// For Pozdnyakov S.N.
int  COM_NN_D(int *numOne, int *numTwo);
int NZER_N_B(int *input);
int *ADD_1N_N(int *input_num);
int* ADD_NN_N(int *numberOne, int *numberTwo);
int* SUB_NN_N(int* input1, int* input2);
int *MUL_ND_N(int *numberOne, int number);
int *MUL_Nk_N(int *A, int k);
int *MUL_NN_N(int *a, int *b);
int *SUB_NDN_N(int *NUMBER_1, int *NUMBER_2, int NUMERAL);
int  DIV_NN_Dk(int *a, int *b);
int *DIV_NN_N(int *NUMBER_1,int *NUMBER_2);
int *MOD_NN_N(int *a, int *b);
int *GCF_NN_N(int *input1, int *input2);
int *LCM_NN_N(int *numberOne, int *numberTwo);




#endif //DM_COLLOC_INTEGER_H
