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

struct rational DIV_QQ_Q(struct rational, struct rational);
int INT_Q_B(struct rational);
struct rational MUL_QQ_Q(struct rational, struct rational);
struct rational RED_Q_Q(struct rational);
struct integer TRANS_Q_Z(struct rational);
struct rational TRANS_Z_Q(struct integer);

#endif //DM_COLLOC_RATIONAL_H
