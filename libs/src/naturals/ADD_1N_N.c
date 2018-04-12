
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