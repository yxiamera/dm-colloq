#include <iostream>
#include "libs/naturals.h"
#include "tests/natural_tests.h"
#include "libs/integer.h"
#include "libs/rational.h"

//TEST(MUL_N)

int *read_number(){
    int *mas, i;
    char number;
    mas = (int*)calloc(2,sizeof(int));
    mas[0] = 0;
    printf("Input the number: ");
    scanf("%c",&number);
    while (isdigit(number) == 0){
        scanf("%c",&number);
    }
    while (number != '\n'){
        mas[0]++;
        if(mas[0] == 1 && number == '-'){
            mas[1] = 1;
            mas[0]--;
        } else if (mas[0] == 1){
            mas[1] = 0;
            mas = (int*)realloc(mas,(mas[0] + 2)*sizeof(int));
            mas[mas[0] + 1] = (number - '0');
        } else{
            mas = (int*)realloc(mas,(mas[0] + 2)*sizeof(int));
            mas[mas[0] + 1] = (number - '0');
        }
        scanf("%c",&number);
    }

    return mas;
}

int *read_number1(){
    int *mas, i;
    char number;
    mas = (int*)calloc(1,sizeof(int));
    mas[0] = 0;
    printf("Input the number: ");
    scanf("%c",&number);
    while (isdigit(number) == 0){
        scanf("%c",&number);
    }
    while (number != '\n'){
        mas[0]++;
        mas = (int*)realloc(mas,(mas[0] + 1)*sizeof(int));
        mas[mas[0]] = (number - '0');
        scanf("%c",&number);
    }

    return mas;
}
void module_1()
{
    int *mas;
    int choose;
    printf("Selected action\n");
    printf("1 - Comparison of positive integers: 2 - if the first is greater than the second, 0 if equal, 1 otherwise..\n");
    printf("2 - Check to zero: if the number is not zero, then \"Yes \"otherwise\" no\"\n");
    printf("3 - Appendix 1 to the natural number\n");
    printf("4 - Addition of positive integers\n");
    printf("5 - Subtraction of the first large natural numbers smaller or equal to the second\n");
    printf("6 - Multiplying a positive integer by a number\n");
    printf("7 - Multiplying a positive integer by 10^kn");
    printf("8 -Multiplication of natural numbers\n");
    printf("9 - Subtraction from the natural other natural multiplied by the number for the case with nonnegative result\n");
    printf("10 - Calculation of the first digit of the division of larger positive by less multiplied by 10^k, where k is the number of the position of this figure (the number is zero)\n");
    printf("11 - Quotient of dividing a larger natural number by a smaller or equal natural number with the remainder(the divisor is nonzero)\n");
    printf("12 - The remainder from dividing the larger natural numbers less than or equal to the natural with the remainder(the divisor is nonzero)\n");
    printf("13 - The GCD of natural numbers\n");
    printf("14 - The LCM of positive integers\n\n");

    printf("What is your choice?: \n");

    scanf("%d",&choose);
    switch(choose){
        case 1:{
            int result;
            result = COM_NN_D(read_number1(),read_number1());
            printf("Answer is: %d\n", result);
            break;
        }
        case 2:{
            int result;
            result = NZER_N_B(read_number1());
            if(result == 1) printf("Answer is: Yes\n"); else printf("Answer is: No\n");
            break;
        }
        case 3:{
            int *mas, i;
            mas = ADD_1N_N(read_number1());
            printf("Answer is: ");
            for (i = 1; i < mas[0] + 1; i++){
                printf("%d",mas[i]);
            }
            free(mas);
            break;
        }
        case 4:{
            int *mas, i;
            mas = ADD_NN_N(read_number1(),read_number1());
            printf("Answer is: ");
            for(i = 1; i < mas[0] + 1; i++){
                printf("%d",mas[i]);
            }
            free(mas);
            break;
        }
        case 5:{
            int *mas, i;
            mas = SUB_NN_N(read_number1(), read_number1());
            printf("Answer is: ");
            for(i = 1; i < mas[0] + 1; i++){
                printf("%d",mas[i]);
            }
            free(mas);
            break;
        }
        case 6:{
            int *mas, i;
            printf("Input the digit: ");
            scanf("%d",&i);
            mas = MUL_ND_N(read_number1(),i);
            printf("Answer is: ");
            for(i = 1; i < mas[0] + 1; i++){
                printf("%d",mas[i]);
            }
            free(mas);
            break;
        }
        case 7:{
            int *mas, i;
            printf("Input the power of 10: ");
            scanf("%d",&i);
            mas = MUL_Nk_N(read_number1(),i);
            printf("Answer is: ");
            for(i = 1; i < mas[0] + 1; i++){
                printf("%d",mas[i]);
            }
            free(mas);
            break;
        }
        case 8:{
            int *mas, i;
            mas = MUL_NN_N(read_number1(),read_number1());
            printf("Answer is: ");
            for(i = 1; i < mas[0] + 1; i++){
                printf("%d",mas[i]);
            }
            free(mas);
            break;
        }
        case 9:{
            int *mas, i;
            printf("Input the digit: ");
            scanf("%d",&i);
            mas = SUB_NDN_N(read_number1(),read_number1(),i);
            printf("Answer is: ");
            for(i = 1; i < mas[0] + 1; i++){
                printf("%d",mas[i]);
            }
            free(mas);
            break;
        }
        case 10:{
            int *mas, i;
            mas = DIV_NN_Dk(read_number1(),read_number1());
            printf("Answer is: ");
            for(i = 1; i < mas[0] + 1; i++){
                printf("%d",mas[i]);
            }
            free(mas);
            break;
        }
        case 11:{
            int *mas, i;
            mas = DIV_NN_N(read_number1(),read_number1());
            printf("Answer is: ");
            for(i = 1; i < mas[0] + 1; i++){
                printf("%d",mas[i]);
            }
            free(mas);
            break;
        }
        case 12:{

        }
    }
}

void module_2()
{
    printf("Selected action\n");
    printf("1 - The absolute value of the number, the result-natural\n");
    printf("2 - Determination of the positivity of the number (2-positive, 0-zero, 1-negative)\n");
    printf("3 - Multiplying the whole by (-1)\n");
    printf("4 - Convert natural to integer\n");
    printf("5 - The conversion of a non-negative in natural\n");
    printf("6 - Addition of integers\n");
    printf("7 - Subtraction of integers\n");
    printf("8 - Multiplication of integers\n");
    printf("9 - Quotient of dividing a larger integer by less than or equal to the positive integer with the remainder(the divisor is nonzero)\n");
    printf("10 - Remainder from dividing a larger integer by less than or equal to the positive integer with the remainder(the divisor is nonzero)\n");
}

void module_3()
{
    printf("Selected action\n");
    printf("1 - Fraction reduction\n");
    printf("2 - Checking for an integer, if the rational number is an integer, then Yes, otherwise no»\n");
    printf("3 - Conversion of a decimal\n");
    printf("4 - Convert fractional to integer (if the denominator is 1)\n");
    printf("5 - Addition of fractions\n");
    printf("6 - Subtraction of fractions\n");
    printf("7 - Multiplying fractions\n");
    printf("8 - Division of fractions (the divisor is nonzero)\n");
}

void module_4()
{
    printf("Selected action\n");
    printf("1 - Addition of polynomials\n");
    printf("2 - Subtraction of polynomials\n");
    printf("3 - Multiplication of a polynomial by a rational number\n");
    printf("4 - Multiplication of a polynomial by x^k\n");
    printf("5 - The highest coefficient of the polynomial\n");
    printf("6 - The degree of the polynomial\n");
    printf("7 - The imposition of polynomial LCM of denominators of coefficients and the GCD of the numerators\n");
    printf("8 - Multiplication of polynomials\n");
    printf("9 - Quotient of division of a polynomial by a polynomial in division with remainder\n");
    printf("10 - Remainder of division of a polynomial by a polynomial in division with remainder\n");
    printf("11 - GCD of polynomials\n");
    printf("12 - The derivative of a polynomial\n");
    printf("13 - The transformation of the polynomial — time roots in the simple\n");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    setlocale(LC_ALL,"Rus");

    int *number1, *number2, choose, warning;
    char *number;

    printf("You're welcome! Selected action\n");
    printf("1 - Positive integers with zero\n2 - Integer\n3 - Rational numbers (fractions)\n4 - Polynomial with rational coefficients\n0 - Exit\nWhat is your choice?: ");
    scanf("%d", &choose);
    warning = 0;

    while(choose < 0 || choose > 4){
        warning++;
        if(warning == 3){
            printf("You made 3 mistakes. Please try again later\n");
            return 0;
        } else printf("Number of errors committed: %d Remained attempts to: %d. What is your choice?: ",warning, 3-warning);
        scanf("%d",&choose);
    }
    warning = 0;

    switch(choose){
        case 1: {
            module_1();
            break;
        }
        case 2: {
            module_2();
            break;
        }
        case 3: {
            module_3();
            break;
        }
        case 4:{
            module_4();
            break;
        }
        case 0:{
            printf("Goodbye!");
            return 0;
            break;
        }
    }
    return RUN_ALL_TESTS();
}