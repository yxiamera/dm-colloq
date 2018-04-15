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

struct integer ABS_Z_N(struct integer );
struct integer POZ_Z_D(struct integer );
struct integer MUL_ZM_Z(struct integer );
struct integer TRANS_N_Z(struct integer );
struct integer TRANS_Z_N(struct integer );
struct integer ADD_ZZ_Z(struct integer , struct integer );
struct integer SUB_ZZ_Z(struct integer , struct integer );
struct integer MUL_ZZ_Z(struct integer , struct integer );
struct integer DIV_ZZ_Z(struct integer , struct integer );
struct integer MOD_ZZ_Z(struct integer , struct integer );
