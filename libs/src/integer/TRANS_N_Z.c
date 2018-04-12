#pragma once
#include "../../integer.h"

//������ ���������
//���� �� �7307
//�������� �� 30 �����

int  *TRANS_N_Z(int *NUMBER)
{
int i;
NUMBER=(int*)realloc(NUMBER,(NUMBER[0]+2)*sizeof(int));
for(i=NUMBER[0]+1;i>1;i--)
{
NUMBER[i]=NUMBER[i-1];
}
NUMBER[1]=0;
return NUMBER;
}

