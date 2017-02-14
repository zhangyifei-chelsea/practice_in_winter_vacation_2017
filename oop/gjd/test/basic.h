//
// Created by liu on 17-2-14.
//

#pragma once

#include "gtest/gtest.h"

TEST(Basic, Simple)
{
    BigNumber num_1;
    BigNumber num_2("123");
    BigNumber num_3("-456");
    BigNumber num_4("-0789");
    EXPECT_EQ("0", num_1.toString());
    EXPECT_EQ("123", num_2.toString());
    EXPECT_EQ("-456", num_3.toString());
    EXPECT_EQ("-789", num_4.toString());
}

TEST(Basic, Longer)
{
    std::string numStr_1, numStr_2 = "-", numStr_3, numStr_4 = "-";
    for (int i = 1; i <= 65536; i++)
    {
        numStr_1 += (i % 9) + '0';
        numStr_2 += (i % 7) + '0';
        numStr_3 += (i % 5) + '0';
        numStr_4 += (i % 3) + '0';
    }
    BigNumber num_1 = numStr_1;
    BigNumber num_2 = numStr_2;
    BigNumber num_3 = numStr_3;
    BigNumber num_4 = numStr_4;
    EXPECT_EQ(numStr_1, num_1.toString());
    EXPECT_EQ(numStr_2, num_2.toString());
    EXPECT_EQ(numStr_3, num_3.toString());
    EXPECT_EQ(numStr_4, num_4.toString());
}
