#include<stdio.h>
#include<stdin.h>

struct mod_4{
    int m;
    int **numenator;
    int **denuminator;
};

struct mod_4 MUL_PP_P(struct mod_4 a, struct mod_4 b){
    struct mod_4 c, d;
    int i;
    c.m=a.m+b.m;
    d.m=0;
    d.numenator=NULL;
    d.denuminator=NULL;
    for(i=0; i<b.m; i++){
        d=MUL_Pxk_P(a, i);
        d=MUL_P_Q(d, b.numenator[i+2], b.denuminator[i+2]);
        c=ADD_P_P(c, d);
    }
    return c;
};
