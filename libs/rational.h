//
// Created by User on 4/12/2018.
//

#ifndef DM_COLLOC_RATIONAL_H
#define DM_COLLOC_RATIONAL_H

#include "src/rational/DIV_QQ_Q.c"
#include "src/rational/INT_Q_B.c"
#include "src/rational/MUL_QQ_Q.c"
#include "src/rational/RED_Q_Q.c"
#include "src/rational/TRANS_Q_Z.c"
#include "src/rational/TRANS_Z_Q.c"

int **DIV_QQ_Q(int **, int **);
int INT_Q_B(int **);
int **MUL_QQ_Q(int **, int **);
int **RED_Q_Q(int **);
int *TRANS_Q_Z(int **);
int **TRANS_Z_Q(int *);

#endif //DM_COLLOC_RATIONAL_H
