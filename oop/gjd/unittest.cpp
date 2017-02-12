//
// Created by liu on 17-2-11.
//

#include "BigNumber.h"
#include "../../lib/googletest/googletest/include/gtest/gtest.h"


TEST(BigNumber, Basic)
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

TEST(BigNumber, BasicLonger)
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

TEST(BigNumber, Addition)
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

TEST(BigNumber, AdditionPlusPlus)
{
    BigNumber num_1("1234");
    EXPECT_EQ("1234", num_1++.toString());
    EXPECT_EQ("1235", num_1.toString());
    EXPECT_EQ("1235", num_1++.toString());
    EXPECT_EQ("1237", (++num_1).toString());
    EXPECT_EQ("1238", (++num_1).toString());
    EXPECT_EQ("1238", num_1.toString());
}

TEST(BigNumber, Substraction)
{
    BigNumber num_1 = BigNumber("0") - BigNumber("0");
    BigNumber num_2 = BigNumber("0") - BigNumber("1");
    BigNumber num_3 = BigNumber("-1") - BigNumber("1");
    BigNumber num_4 = BigNumber("-1") - BigNumber("0");
    EXPECT_EQ("0", num_1.toString());
    EXPECT_EQ("-1", num_2.toString());
    EXPECT_EQ("-2", num_3.toString());
    EXPECT_EQ("-1", num_4.toString());
}

TEST(BigNumber, SubstractionPlusPlus)
{
    BigNumber num_1("1234");
    EXPECT_EQ("1234", num_1--.toString());
    EXPECT_EQ("1233", num_1.toString());
    EXPECT_EQ("1233", num_1--.toString());
    EXPECT_EQ("1231", (--num_1).toString());
    EXPECT_EQ("1230", (--num_1).toString());
    EXPECT_EQ("1230", num_1.toString());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}