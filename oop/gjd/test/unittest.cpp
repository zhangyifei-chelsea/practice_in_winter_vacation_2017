//
// Created by liu on 17-2-11.
//

#include "unittest.h"
#include "../BigNumber.h"
#include "gtest/gtest.h"

#include "basic.h"

#include "addition.h"
#include "addition_longer.h"

#include "subtraction.h"
#include "subtraction_longer.h"

#include "multiple.h"
#include "multiple_longer.h"

#include "division.h"

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}