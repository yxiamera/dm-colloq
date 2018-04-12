#pragma once

int *MUL_Nk_N(int *A, int k) {
    int i;

    //основной алгоритм
    int *B = (int *)malloc((A[0] + 2 + k) * sizeof(int));

    //копируем "служебные" значения
    B[0] = A[0] + k;
    B[1] = A[1];
    //вставляем нули
    for (i = 2; i < k + 2; i++)
        B[i] = 0;
    //копируем цифры исходного числа
    for (i = k + 2; i < B[0] + 2; i++)
        B[i] = A[i - k];

    return B;
}