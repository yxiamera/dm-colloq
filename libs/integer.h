#pragma once

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "src/integer/ABS_Z_N.c"
#include "src/integer/ADD_ZZ_Z.c"
#include "src/integer/DIV_ZZ_Z.c"
#include "src/integer/MOD_ZZ_Z.c"
#include "src/integer/MUL_ZM_Z.c"
#include "src/integer/MUL_ZZ_Z.c"
#include "src/integer/POZ_Z_D.c"
#include "src/integer/SUB_ZZ_Z.c"
#include "src/integer/TRANS_N_Z.c"
#include "src/integer/TRANS_Z_N.c"

int *ABS_Z_N(int *);
int POZ_Z_D(int *);
int *MUL_ZM_Z(int *);
int *TRANS_N_Z(int *);
int *TRANS_Z_N(int *);
int *ADD_ZZ_Z(int *, int *);
int *SUB_ZZ_Z(int *, int *);
int *MUL_ZZ_Z(int *, int *);
int *DIV_ZZ_Z(int *, int *);
int *MOD_ZZ_Z(int *, int *);
