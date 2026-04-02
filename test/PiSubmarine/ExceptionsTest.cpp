#include <gtest/gtest.h>
#include "PiSubmarine/Exceptions.h"

namespace PiSubmarine::Exceptions
{
    TEST(ExceptionsTest, ThrowTest)
    {
        EXPECT_THROW(Throw(std::overflow_error("Hello World!")), std::overflow_error);
    }
}