#define GTEST_LANG_CXX11 1
#include <gtest/gtest.h>

#include <sstream>
#include "Game.h"

TEST(GameTest, Finished) {
    auto input = std::string{"1\nr"};
    auto istream = std::istringstream{input};
    auto output = std::string{""};
    auto ostream = std::ostringstream{output};
    auto game = Game::Game(istream, ostream);
    game.run();
}