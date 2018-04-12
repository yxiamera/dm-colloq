#pragma once
#include "../../integer.h"


int *MUL_ZM_Z(int *a)
{
    a[0] = 1 - a[0];
    return a;

}
