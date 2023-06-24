#define GTEST_LANG_CXX11 1
#include <gtest/gtest.h>

#include "Game.h"

TEST(GameTest, Finished) {
    auto game = Game::Game();
    ASSERT_TRUE(game.isRunning());
    game.quit();
    ASSERT_FALSE(game.isRunning());
}