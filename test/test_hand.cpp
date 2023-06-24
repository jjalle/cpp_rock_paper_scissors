#define GTEST_LANG_CXX11 1
#include <gtest/gtest.h>

#include "Hand.h"

using namespace Game;

TEST(HandTest, PaperHand) {
    auto hand = PaperHand();
    ASSERT_EQ(hand, PaperHand());
    ASSERT_GT(hand, RockHand());
    ASSERT_LT(hand, ScissorsHand());
}

TEST(HandTest, RockHand) {
    auto hand = RockHand();
    ASSERT_LT(hand, PaperHand());
    ASSERT_EQ(hand, RockHand());
    ASSERT_GT(hand, ScissorsHand());
}

TEST(HandTest, ScissorsHand) {
    auto hand = ScissorsHand();
    ASSERT_GT(hand, PaperHand());
    ASSERT_LT(hand, RockHand());
    ASSERT_EQ(hand, ScissorsHand());
}
