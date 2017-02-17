//
// Created by liu on 17-2-17.
//

#pragma once

#include "gtest/gtest.h"

TEST(Multiple, Zero)
{
    BigNumber num_1 = BigNumber("0") * BigNumber("0");
    BigNumber num_2 = BigNumber("0") * BigNumber("1");
    BigNumber num_3 = BigNumber("-1") * BigNumber("0");
    EXPECT_EQ("0", num_1.toString());
    EXPECT_EQ("0", num_2.toString());
    EXPECT_EQ("0", num_3.toString());
}

TEST(Multiple, Simple)
{
    BigNumber num_1 = BigNumber("1") * BigNumber("1");
    BigNumber num_2 = BigNumber("1") * BigNumber("-1");
    BigNumber num_3 = BigNumber("-1") * BigNumber("1");
    BigNumber num_4 = BigNumber("-1") * BigNumber("-1");
    EXPECT_EQ("1", num_1.toString());
    EXPECT_EQ("-1", num_2.toString());
    EXPECT_EQ("-1", num_3.toString());
    EXPECT_EQ("1", num_4.toString());
}