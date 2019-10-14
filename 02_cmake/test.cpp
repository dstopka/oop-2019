#include "dummy.h"
#include <gtest/gtest.h>

TEST(Dummy, Add)
{
auto dummy = Dummy{};
EXPECT_EQ(10, dummy.add(7, 3));
}