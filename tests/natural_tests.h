//
// Created by User on 4/12/2018.
//

#ifndef DM_COLLOC_NATURAL_TESTS_H
#define DM_COLLOC_NATURAL_TESTS_H
#include <gtest/gtest.h>


TEST(str_repr, basic_test) {
    int test1[] = {3, 1, 2, 1},
            test2[] = {2, 1, 1},
            test3[] = {0};
    EXPECT_STREQ(str_repr(test1), "3121");
    EXPECT_STREQ(str_repr(test2), "211");
    EXPECT_STREQ(str_repr(test3), "0");
}

TEST(COM_NN_D, basic_test) {
    int test1[] = {3, 1, 2, 3},
            test2[] = {4, 1, 2, 3, 4},
            test3[] = {3, 1, 2, 3},
            test4[] = {0};
    EXPECT_EQ(COM_NN_D(test1, test2), 1);
    EXPECT_EQ(COM_NN_D(test1, test1), 0);
    EXPECT_EQ(COM_NN_D(test1, test4), 2);
    EXPECT_EQ(COM_NN_D(test1, test3), 0);
}

TEST(NZER_N_B, basic_test) {
    int test1[] = {3, 1, 2, 3},
            test2[] = {0};
    EXPECT_EQ(NZER_N_B(test1), 0);
    EXPECT_EQ(NZER_N_B(test2), 0);
}

TEST(ADD_1N_N, basic_test) {
    int test1[] = {0},
            test2[] = {1, 1},
            test3[] = {3, 9, 9, 9},
            test4[] = {3, 1, 2, 4};
    EXPECT_STREQ(str_repr(ADD_1N_N(test1)), "11");
    EXPECT_STREQ(str_repr(ADD_1N_N(test2)), "12");
    EXPECT_STREQ(str_repr(ADD_1N_N(test3)), "41000");
    EXPECT_STREQ(str_repr(ADD_1N_N(test4)), "3125");
}

TEST(ADD_NN_N, basic_test) {
    int test1[] = {0},
            test2[] = {1, 1},
            test3[] = {3, 9, 9, 9},
            test4[] = {3, 1, 2, 4};
    EXPECT_STREQ(str_repr(ADD_NN_N(test1, test2)), "11");
    EXPECT_STREQ(str_repr(ADD_NN_N(test3, test4)), "41123");
}

TEST(SUB_NN_N, basic_test) {
    int test1[] = {0},
            test2[] = {1, 1},
            test3[] = {3, 9, 9, 9},
            test4[] = {3, 1, 2, 4};
    EXPECT_STREQ(str_repr(SUB_NN_N(test2, test1)), "11");
    EXPECT_STREQ(str_repr(SUB_NN_N(test3, test4)), "3875");
}

TEST(MUL_ND_N, basic_test) {
    int test1[] = {0},
            test2[] = {1, 2},
            test3[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    EXPECT_STREQ(str_repr(MUL_ND_N(test1, 9)), "0");
    EXPECT_STREQ(str_repr(MUL_ND_N(test2, 9)), "218");
    EXPECT_STREQ(str_repr(MUL_ND_N(test3, 9)), "1111111111010");
}

#endif //DM_COLLOC_NATURAL_TESTS_H
