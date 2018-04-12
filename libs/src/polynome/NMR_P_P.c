#include<stdio.h>
#include<stdin.h>

struct mod_4{
    int m;
    int **numenator;
    int **denuminator;
};

struct mod_4 NMR_P_P(struct mod_4 a){
    struct mod_4 b, c;
    b=DER_P_P(a);
    c=GCF_PP_P(b, a);
    return DIV_PP_P(a,c);

}
