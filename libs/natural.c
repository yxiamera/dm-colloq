#include "naturals.h"

char *str_repr(int *num) {
    char *str = (char *)malloc(*num + 2);
    for (int i = 0; i < *num + 1; ++i) {
        str[i] = num[i] + '0';
    }
    str[num[0] + 1] = 0;
    return str;
}

void print_natural(int *num) {
    printf("%s\n", str_repr(num));
}

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

/*
	Выполнил: Шалашников Максим Игоревич

	Назначение: Добавление натурального числа к натуральному числу
	Возвращаемое значение: Натуральное число
	Параметры: 2 Натуральных числа
*/


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

int* SUB_NN_N(int* input1, int* input2){
    int div1 = input1[0];  //считываем количество цифр в первом числе
    int div2 = input2[0];  //считываем количество цифр во втором числе
    int i, j;
    int counter;
    int* num1 = NULL; int* num2 = NULL; //поданые на вход числа, переписанные для удобства от младших разрядов к старшим
    int* diff = NULL;
    int* result_num = NULL;


    if (COM_NN_D(input1, input2) == 0){ //сравниваем числа; если два числа равны, то их разность равна нулю
        diff = (int*)calloc(1, sizeof(int));
        diff[0] = 0;
        return diff;
    }
    else{  //переписываем заданные числа начиная от младших разрядов к старшим
        num1 = (int*)calloc(div1, sizeof(int));
        num2 = (int*)calloc(div1, sizeof(int));
        for (i = 0; i < div1; i++){
            num1[i] = input1[div1 - i];
        }
        for (i = 0; i < div1; i++){
            if (i < div2){
                num2[i] = input2[div2 - i];
            }
            else{ //если количество разрядов второго числа меньше, чем у первого, то вместо недостающих разрядов добавляем нули
                num2[i] = 0;
            }
        }
        counter = 0; //переменная для подсчета цифр в искомой разности
        for (i = 0; i < div1; i++){
            if (num1[i] >= num2[i]){ //если цифра текущего разряда уменьшаемого числа больше либо равна цифре соответствующего разряда вычитаемого числа, вычитаем вторую из первой
                diff = (int*)realloc(diff, (counter + 1)*sizeof(int));
                diff[counter] = num1[i] - num2[i];
                counter++;
            }
            else if (num1[i] < num2[i]){ //иначе делаем "заем" - находим ближайший старший ненулевой разряд и уменьшаем его на единицу
                j = 1;
                while (num1[i + j] == 0){ //нулевые разряды, стоящие перед искомым ненулевым, заменяются на девятки
                    num1[i + j] = 9;
                    j++;
                }
                num1[i + j] = num1[i + j] - 1; //ближайший старший ненулевой разряд уменьшается на единицу
                diff = (int*)realloc(diff, (counter + 1)*sizeof(int));
                diff[counter] = num1[i] + 10 - num2[i]; //к текущей цифре уменьшаемого числа прибавляем 10 и вычитаем из нее соответствующую цифру второго числа
                counter++;
            }
        }
    }
    //теперь у нас есть массив цифр искомого числа diff
    //цифры в нем расположены от младшео разряда к старшему
    while (diff[counter - 1] == 0){ //в полученном числе ищем первый ненулевой старший разряд
        counter--;
    }
    result_num = (int*)calloc(counter + 1, sizeof(int)); //переписываем полученое число от старших разрядов к младшим
    result_num[0] = counter; //добавляем размерность полученного числа
    for (i = 1; i < counter + 1; i++){
        result_num[i] = diff[counter - i]; //сохраняем в массив цифры полученного числа в порядке от старшего разряда к младшим
    }
    return result_num;
}

int DIV_NN_Dk(int *a, int *b) {
    /*
     * Vasilev Andrey, 7307
     * Вычисление первой цифры деления большего натурального на меньшее,
     * домноженное на 10^k, где k - номер позиции этой цифры (номер считается с нуля)
     */
    const int NSIZE = a[0];
    int *multiplied_b = (int *)malloc(NSIZE * sizeof(int));
    // copy old_b, to new location
    multiplied_b[0] = NSIZE;
    for (int i = 1; i <= NSIZE; i++) {
        multiplied_b[i] = i <= b[0] ? b[i] : 0;
    }
    // calculate num
    int n = 0;
    print_natural(multiplied_b);
    print_natural(a);
    while (COM_NN_D(a, multiplied_b) == 2) {
        a = SUB_NN_N(a, multiplied_b);
        print_natural(a);
        n++;
    }
    return n;
}

// GCD of natural numbers
// About the author:
// Ermolenko Valery Eduardovich, 7307, FKTI
// https://sites.google.com/site/lazzyvaleriyermolenko1999/home
// e-mail: cagema.erm@gmail.com

//Петров Владислав
//ФКТИ гр №7307
//Выполнил за 30 минут
int *DIV_NN_N(int *NUMBER_1, int *NUMBER_2) {
    // Work in progress
    return NULL;
}

int *MOD_NN_N(int *a, int *b) {
    int* temp; // r
    if (a == NULL || b == NULL)
        return NULL;
    int *N;
    if ((COM_NN_D(a, b) == 2))//IF A > B
    {
        N = DIV_NN_N(a, b);// N: A = N*B + r
        temp = SUB_NDN_N(a, b, *N);//r = A - N*B
    } else {
        N = DIV_NN_N(b, a);//IF A <= B
        temp = SUB_NDN_N(b, a, *N);
    }
    return ((temp != NULL) ? temp : NULL);

}

int *GCF_NN_N(int *input1, int *input2) {
    // Execution time: 20 minutes
    // Logical lines of code: 15
    int *GCF;
    // If one number is divided into another without a remainder, then the GCD is the smaller of them
    if (MOD_NN_N(input1, input2) == 0) {
        GCF = input2;
    }
    if (MOD_NN_N(input2, input1) == 0) {
        GCF = input1;
    }

    while ((MOD_NN_N(input1, input2) != 0) || (MOD_NN_N(input2, input1) !=
                                               0)) { // While the remainder of division of one number by another is not equal to zero
        if (COM_NN_D(input1, input2) == 2) {
            GCF = SUB_NN_N(input1, input2);
        } else {
            if (COM_NN_D(input1, input2) == 1) {
                GCF = SUB_NN_N(input2, input1);
            } else {
                return GCF;
            }
        }
    }
    return GCF;
}

int NZER_N_B(int *input) {
    // Execution time: 10 minutes
    // Logical lines of code: 11
    int size = input[0]; // Size of the number
    int c, i;

    c = 0;
    for (i = 2; i <= size; i++) { // If each digit of a number is zero
        if (input[i] != c) {
            c = 1;
        }
    }
    if (c == 0) {
        return 0;
    } else {
        return 1; // The number is not zero
    }
}

//Добавление к натуральному числу 1
//Об авторе:
//Петрова Елизавета Михайловна гр. № 7307, ФКТИ
//https://sites.google.com/view/petrovaliza7307
//e-mail: ostenok@gmail.com


int *ADD_1N_N(int *input_num) {
    int div = input_num[0];   //считывает количество цифр в числе
    int index = div + 1;
    int i;
    int *result_num;

    if (input_num[index] != 9) { //если цифра в самом младшем разряде числа не равна 9, то
        input_num[index]++;     //увеличиваем эьу цфиру на единицу
    } else {
        while ((input_num[index] == 9) &&
               (index != 1)) {  //если цифра в младшем разряде равна 9, ищем в числе первую цифру, не равнуб 9
            input_num[index] = 0;    //все цифры числа, равные 9, заменяем нулями
            index--;
        }
        if (index == 0) {      //если в числе есть только цифры 9, то добавляем к числу один старший разряд
            div += 1;
            result_num = (int *) calloc((div + 1), sizeof(int));
            result_num[0] = div;
            result_num[1] = 1;  //в старшем разряде числа помещаем единицу
            for (i = 2; i < div + 1; i++) {
                result_num[i] = 0;   //все остальные цифры числа заменяем нулями
            }
        } else {
            result_num[index]++;  //если в числе была найдена цифра, не равная 9, она увеличивается на единицу
        }
    }
    return result_num;
}
//Время выполнения: 15 минут

int *MUL_NN_N(int *a, int *b) {
    int length = a[0] + b[0] + 1;//calculating length our composition
    int *c = (int *) malloc(length);
    c[0] = length;
    c[1] = 0;
    for (int i = 1; i < a[0]; i++) {
        for (int j = 2; j < b[0]; j++) {
            int *n = MUL_ND_N(a, b[j]);//calculating composition of numerals
            c = ADD_NN_N(c, n);//sum the composition of numerals
        }

    }
    for (int i = 0; i < length; i++)//calculating the end of our composition(have we zeroes before our result)
    {
        int k = -1;
        int *m = MUL_Nk_N(c, k);
        c = ADD_NN_N(c, m);
        c[i] %= 10;
    }
    while (c[length] == 0)//check our result(have we excess zeroes)
    {
        length--;
    }
    return c;

}

/*
	Выполнил: Шалашников Максим Игоревич

	Назначение: НОК натуральных чисел
	Возвращаемое значение: Натуральное число
	Параметры: 2 Натуральных числа
*/

int *LCM_NN_N(int *numberOne, int *numberTwo) {
    return DIV_NN_N(MUL_NN_N(numberOne, numberTwo), GCF_NN_N(numberOne, numberTwo));
}

/*
	Выполнил: Шалашников Максим Игоревич

	Назначение: умножение натурального числа на цифру
	Возвращаемое значение: Натуральное число
	Параметры: натуральное число и цифра
*/


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

//Петров Владислав
//ФКТИ гр №7307
//Выполнил за 20 мин
int *SUB_NDN_N(int *NUMBER_1, int *NUMBER_2, int NUMERAL) {
    int *rezult = NULL, comparison, *multiplication;
    multiplication = MUL_ND_N(NUMBER_2, NUMERAL);
    comparison = COM_NN_D(NUMBER_1, multiplication);
    if ((comparison == 2) || (comparison == 0))
        rezult = SUB_NN_N(NUMBER_1, multiplication);
    return rezult;
}


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

//Об авторе
//Муха Дарья ФКТИ Гр.№7307
//E-Mail: mukhaj99@gmail.com

// Check for zero: if the number is not zero, then "yes"(1) otherwise "no"(0)
// About the author:
// Ermolenko Valery Eduardovich, 7307, FKTI
// https://sites.google.com/site/lazzyvaleriyermolenko1999/home
// e-mail: cagema.erm@gmail.com
