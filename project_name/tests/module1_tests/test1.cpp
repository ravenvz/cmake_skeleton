#include "module1/Dummy.h"
#include "gtest/gtest.h"

TEST(basic_check, test_eq)
{
    Dummy dummy{5};
    EXPECT_EQ(5, dummy.getValue());
}


