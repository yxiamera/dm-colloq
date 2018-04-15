#pragma once

#include "src/polynome/ADD_PP_P.c"
#include "src/polynome/DEG_P_N.c"
#include "src/polynome/DIV_PP_P.c"
#include "src/polynome/GCF_PP_P.c"
#include "src/polynome/LED_P_Q.c"
#include "src/polynome/MUL_PP_P.c"
#include "src/polynome/MUL_PQ_P.c"
#include "src/polynome/NMR_P_P.c"
#include "src/polynome/SUB_PP_P.c"

mod_4 *ADD_PP_P(mod_4, mod_4);
long long DEG_P_N(mod_4*);
mod_4 DIV_PP_P(mod_4, mod_4);
mod_4 *GCF_PP_P(mod_4, mod_4);
int LED_P_Q(mod_4);
mod_4 MUL_PP_P(mod_4, mod_4);
int MUL_PQ_P(mod_4*, int**);
mod_4 NMR_P_P(mod_4);
mod_4 SUB_PP_P(mod_4, mod_4);