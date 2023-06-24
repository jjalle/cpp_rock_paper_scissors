#define GTEST_LANG_CXX11 1
#include <gtest/gtest.h>

#include "Input.h"
using namespace Game;

static const auto DEFAULT_TURNS = uint64_t{42};

TEST(InputTest, Turns) {
    auto input = Input(DEFAULT_TURNS);
    //ASSERT_EQ(input.getNumberOfTurns(), DEFAULT_TURNS);
}
