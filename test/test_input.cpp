#define GTEST_LANG_CXX11 1
#include <gtest/gtest.h>

#include <sstream>
#include "Input.h"
using namespace Game;

static const auto DEFAULT_TURNS = uint64_t{42};

TEST(InputTurnTest, DefaultTurns) {
    auto input = std::string{"\n"};
    auto istream = std::istringstream{input};
    auto output = std::string{""};
    auto ostream = std::ostringstream{output};
    auto inputManager = Input(DEFAULT_TURNS, istream, ostream);
    auto turns = inputManager.getNumberOfTurns();
    ASSERT_EQ(turns, DEFAULT_TURNS);
}

TEST(InputTurnTest, InvalidEntryInline) {
    auto input = std::string{"invalid 18"};
    auto istream = std::istringstream{input};
    auto output = std::string{""};
    auto ostream = std::ostringstream{output};
    auto inputManager = Input(DEFAULT_TURNS, istream, ostream);
    auto turns = inputManager.getNumberOfTurns();
    ASSERT_EQ(turns, DEFAULT_TURNS);
}

TEST(InputTurnTest, InvalidEntryMultiline) {
    auto input = std::string{"invalid\n18"};
    auto istream = std::istringstream{input};
    auto output = std::string{""};
    auto ostream = std::ostringstream{output};
    auto inputManager = Input(DEFAULT_TURNS, istream, ostream);
    auto turns = inputManager.getNumberOfTurns();
    ASSERT_EQ(turns, DEFAULT_TURNS);
}

TEST(InputTurnTest, ValidEntryPositive) {
    auto input = std::string{"18"};
    auto istream = std::istringstream{input};
    auto output = std::string{""};
    auto ostream = std::ostringstream{output};
    auto inputManager = Input(DEFAULT_TURNS, istream, ostream);
    auto turns = inputManager.getNumberOfTurns();
    ASSERT_EQ(turns, 18);
}

TEST(InputTurnTest, ValidEntry0) {
    auto input = std::string{"0"};
    auto istream = std::istringstream{input};
    auto output = std::string{""};
    auto ostream = std::ostringstream{output};
    auto inputManager = Input(DEFAULT_TURNS, istream, ostream);
    auto turns = inputManager.getNumberOfTurns();
    ASSERT_EQ(turns, DEFAULT_TURNS);
}

TEST(InputTurnTest, InvalidEntryNegative) {
    auto input = std::string{"-20"};
    auto istream = std::istringstream{input};
    auto output = std::string{""};
    auto ostream = std::ostringstream{output};
    auto inputManager = Input(DEFAULT_TURNS, istream, ostream);
    auto turns = inputManager.getNumberOfTurns();
    ASSERT_EQ(turns, DEFAULT_TURNS);
}

TEST(InputTurnTest, ValidEntryFloat) {
    auto input = std::string{"18.0"};
    auto istream = std::istringstream{input};
    auto output = std::string{""};
    auto ostream = std::ostringstream{output};
    auto inputManager = Input(DEFAULT_TURNS, istream, ostream);
    auto turns = inputManager.getNumberOfTurns();
    ASSERT_EQ(turns, 18);
}

TEST(InputTurnTest, ValidEntryFloatTruncated) {
    auto input = std::string{"18.2"};
    auto istream = std::istringstream{input};
    auto output = std::string{""};
    auto ostream = std::ostringstream{output};
    auto inputManager = Input(DEFAULT_TURNS, istream, ostream);
    auto turns = inputManager.getNumberOfTurns();
    ASSERT_EQ(turns, 18);
}

TEST(InputTurnTest, ValidEntryFloatTruncated2) {
    auto input = std::string{"18.6"};
    auto istream = std::istringstream{input};
    auto output = std::string{""};
    auto ostream = std::ostringstream{output};
    auto inputManager = Input(DEFAULT_TURNS, istream, ostream);
    auto turns = inputManager.getNumberOfTurns();
    ASSERT_EQ(turns, 18);
}

TEST(InputHandTest, ValidHandRock) {
    auto input = std::string{"rR"};
    auto istream = std::istringstream{input};
    auto output = std::string{""};
    auto ostream = std::ostringstream{output};
    auto inputManager = Input(DEFAULT_TURNS, istream, ostream);
    {
        auto hand = inputManager.getPlayerHand();
        ASSERT_EQ(hand, RockHand());
    }
    {
        auto hand = inputManager.getPlayerHand();
        ASSERT_EQ(hand, RockHand());
    }
}

TEST(InputHandTest, ValidHandPaper) {
    auto input = std::string{"pP"};
    auto istream = std::istringstream{input};
    auto output = std::string{""};
    auto ostream = std::ostringstream{output};
    auto inputManager = Input(DEFAULT_TURNS, istream, ostream);
    {
        auto hand = inputManager.getPlayerHand();
        ASSERT_EQ(hand, PaperHand());
    }
    {
        auto hand = inputManager.getPlayerHand();
        ASSERT_EQ(hand, PaperHand());
    }
}

TEST(InputHandTest, ValidHandScissors) {
    auto input = std::string{"sS"};
    auto istream = std::istringstream{input};
    auto output = std::string{""};
    auto ostream = std::ostringstream{output};
    auto inputManager = Input(DEFAULT_TURNS, istream, ostream);
    {
        auto hand = inputManager.getPlayerHand();
        ASSERT_EQ(hand, ScissorsHand());
    }
    {
        auto hand = inputManager.getPlayerHand();
        ASSERT_EQ(hand, ScissorsHand());
    }
}

TEST(InputHandTest, InvalidInputAndValid) {
    auto input = std::string{"Xomething invalid\nS"};
    auto istream = std::istringstream{input};
    auto output = std::string{""};
    auto ostream = std::ostringstream{output};
    auto inputManager = Input(DEFAULT_TURNS, istream, ostream);
    {
        auto hand = inputManager.getPlayerHand();
        ASSERT_EQ(hand, ScissorsHand());
    }
}
