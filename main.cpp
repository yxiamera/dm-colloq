#include <iostream>
#include "libs/naturals.h"
#include "tests/natural_tests.h"
#include "libs/integer.h"
#include "libs/rational.h"
#include "libs/polynome.h"

//TEST(MUL_N)


int main(int argc, char** argv) {
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
    mod_4 P1 = *init_mod_4();
    print_mod_4(P1);
    mod_4 P2 = *init_mod_4();
    print_mod_4(P2);
    printf("Result:");
    print_mod_4(*SUB_PP_P(P1,P2));

    return 0;
}