#include "module1/Dummy.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class GreeterMock : public ExcitingInterface {
public:
	MOCK_CONST_METHOD0(greet, void());
};

TEST(basic_check, test_eq)
{
    Dummy dummy{5};
    EXPECT_EQ(5, dummy.getValue());
}

TEST(basic_check, test_using_mock)
{
	GreeterMock mock;
}

TEST(basic_check, always_pass)
{
	ASSERT_TRUE(1);
}

