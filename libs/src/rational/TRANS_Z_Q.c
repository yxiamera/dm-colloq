//Петров Владислав
//ФКТИ гр №7307
//Выполнил за 30 минут
int** TRANS_Z_Q(int *INTEGER)
{
int **FRACTION,i,j;
FRACTION=(int**)malloc(2*sizeof(int*));
FRACTION[0]=(int*)malloc((INTEGER[0]+2)*sizeof(int*));
FRACTION[1]=(int*)malloc(2*sizeof(int*));
FRACTION[0]=INTEGER;
FRACTION[1][0]=1;
FRACTION[1][1]=1;
return FRACTION;
}
