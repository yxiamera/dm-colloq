#include <iostream>
#include "libs/naturals.h"
#include "tests/natural_tests.h"
#include "libs/integer.h"
#include "libs/rational.h"

//TEST(MUL_N)


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}