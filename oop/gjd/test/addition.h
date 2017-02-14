//
// Created by liu on 17-2-14.
//

#pragma once

#include "gtest/gtest.h"

TEST(Addition, Simple)
{
    BigNumber num_1 = BigNumber("0") + BigNumber("0");
    BigNumber num_2 = BigNumber("0") + BigNumber("1");
    BigNumber num_3 = BigNumber("-1") + BigNumber("1");
    BigNumber num_4 = BigNumber("-1") + BigNumber("0");
    EXPECT_EQ("0", num_1.toString());
    EXPECT_EQ("1", num_2.toString());
    EXPECT_EQ("0", num_3.toString());
    EXPECT_EQ("-1", num_4.toString());
}

TEST(Addition, PlusPlus)
{
    BigNumber num_1("1234");
    EXPECT_EQ("1234", num_1++.toString());
    EXPECT_EQ("1235", num_1.toString());
    EXPECT_EQ("1235", num_1++.toString());
    EXPECT_EQ("1237", (++num_1).toString());
    EXPECT_EQ("1238", (++num_1).toString());
    EXPECT_EQ("1238", num_1.toString());
}