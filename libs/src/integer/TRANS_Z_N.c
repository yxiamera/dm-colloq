#pragma once
#include "../../integer.h"
#include<stdio.h>

//�� ������:
//�������� ������ ������������, ���� ��.�7307
//*������ �� ������������ ����
//e-mail: andrey98vas@gmail.com
int *TRANS_Z_N(int *a){
    int i;
    int *b;
    b=(int *)malloc((a[0]-1)* sizeof(int));
    b[0]=a[0]-1;
    for(i=1;i<a[0]-1;i++){
        if(i>1)b[i]=a[i-1];
    };
    return b;
}
