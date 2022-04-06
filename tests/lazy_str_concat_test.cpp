#include "gtest/gtest.h"

#include <lazy_str_concat_helper.h>
TEST(lazy_str_concat, test_concat_strings_lazy)
{
    auto cat = lazy_str_concat_helper<>();
    std::string result = cat + "Eren" +", "+"Jaeger";
    EXPECT_EQ(result, "Eren, Jaeger");

}
