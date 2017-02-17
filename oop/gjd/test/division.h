//
// Created by liu on 17-2-17.
//

#pragma once

#include "gtest/gtest.h"

TEST(Division, Zero)
{
    BigNumber num_1 = BigNumber("0") / BigNumber("1");
    BigNumber num_2 = BigNumber("0") / BigNumber("-1");
    BigNumber num_3 = BigNumber("0") % BigNumber("1");
    BigNumber num_4 = BigNumber("0") % BigNumber("-1");
    EXPECT_EQ("0", num_1.toString());
    EXPECT_EQ("0", num_2.toString());
    EXPECT_EQ("0", num_3.toString());
    EXPECT_EQ("0", num_4.toString());
}

TEST(Division, Simple)
{
    BigNumber num_1 = BigNumber("1") / BigNumber("1");
    BigNumber num_2 = BigNumber("1") / BigNumber("-1");
    BigNumber num_3 = BigNumber("-1") / BigNumber("1");
    BigNumber num_4 = BigNumber("-1") / BigNumber("-1");
    BigNumber num_5 = BigNumber("1") % BigNumber("1");
    BigNumber num_6 = BigNumber("1") % BigNumber("-1");
    BigNumber num_7 = BigNumber("-1") % BigNumber("1");
    BigNumber num_8 = BigNumber("-1") % BigNumber("-1");
    EXPECT_EQ("1", num_1.toString());
    EXPECT_EQ("-1", num_2.toString());
    EXPECT_EQ("-1", num_3.toString());
    EXPECT_EQ("1", num_4.toString());
    EXPECT_EQ("0", num_5.toString());
    EXPECT_EQ("0", num_6.toString());
    EXPECT_EQ("0", num_7.toString());
    EXPECT_EQ("0", num_8.toString());
}