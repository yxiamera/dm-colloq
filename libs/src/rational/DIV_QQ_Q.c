//выполнила Николаева Екатерина
#include <stdio.h>
#include <stdlib.h>

int count_digits(int number) {
    int digits=0;
    if (number < 0) {
        number *= -1;
    }
    while (number>=10) {
        digits += 1;
        number /= 10;
    }
    return digits;
};

int* init_integer(int number) {
    int i;
    int size = count_digits(number);
    int* Z = malloc((size+3) * sizeof(int));
    Z[0] = size;
    if (number < 0) {
        Z[1] = 1;
        number *= -1;
    } else {
        Z[1] = 0;
    }
    for (i=2; i<=size+2; i++) {
        Z[i] = number%10;
        number /= 10;
    }
    return Z;
};

int get_integer(int* Z) {
    int number=0,power=1,i;
    for (i=2; i<=Z[0]+2; i++) {
        number += Z[i] * power;
        power *= 10;
    }
    if (Z[1] == 1) {
        number *= -1;
    }
    return number;
};

int* MUL_ZZ_Z(int *a, int *b) {
    return init_integer(get_integer(a)*get_integer(b));
}

int** DIV_QQ_Q (int** F1, int** F2) {

    int** F = malloc(2 * sizeof(int*));

    //умножение на перевернутую дробь
    F[0] = MUL_ZZ_Z(F1[0], F2[1]); //числитель
    F[1] = MUL_ZZ_Z(F1[1], F2[0]); //знаменатель

    //исправление знака знаменателя
    if (F[1][1] == 1) {
        F[1][1] = 0;
        if (F[0][1] == 1) {
            F[0][1] = 0;
        } else {
            F[0][1] = 1;
        }
    }

    return F;
}

int main() {
    int **F1, **F2, **result;
    int den1, den2, num1, num2;

    printf("Enter dividend (example 1/2): ");
    scanf("%d/%d", &num1, &den1);
    printf("Enter divisor (example 1/4): ");
    scanf("%d/%d", &num2, &den2);

    F1 = malloc(2 * sizeof(int*));
    F2 = malloc(2 * sizeof(int*));
    F1[0] = init_integer(num1);
    F1[1] = init_integer(den1);
    F2[0] = init_integer(num2);
    F2[1] = init_integer(den2);

    result = DIV_QQ_Q(F1, F2);

    printf("Result: %d/%d\n",get_integer(result[0]),get_integer(result[1]));

    return 0;
}

//время выполнения - около 2-х часов
