#define GTEST_LANG_CXX11 1
#include <gtest/gtest.h>

#include "Turn.h"
#include "Hand.h"

using namespace Game;


const static auto MAX_TURNS = uint64_t{2};
const static auto WINNING_HAND = RockHand();
const static auto LOSING_HAND = ScissorsHand();
const static auto TIE_HAND = RockHand();
    
TEST(TurnEngineTest, MaxTurns) {
    auto engine = TurnEngine(0);
    engine.startNewGame(MAX_TURNS);
    ASSERT_FALSE(engine.finished());
    ASSERT_EQ(engine.getCurrentTurn(), 0);
    engine.playTurn(RockHand(), RockHand());
    ASSERT_FALSE(engine.finished());
    ASSERT_EQ(engine.getCurrentTurn(), 1);
    engine.playTurn(RockHand(), RockHand());
    ASSERT_TRUE(engine.finished());
    ASSERT_EQ(engine.getCurrentTurn(), 2);
}

TEST(TurnEngineTest, PlayerScores) {
    auto engine = TurnEngine(0);
    engine.startNewGame(MAX_TURNS);
    ASSERT_EQ(engine.playerScore(), 0);
    ASSERT_EQ(engine.cpuScore(), 0);
    ASSERT_EQ(engine.ties(), 0);
    engine.playTurn(WINNING_HAND, LOSING_HAND);
    ASSERT_EQ(engine.playerScore(), 1);
    ASSERT_EQ(engine.cpuScore(), 0);
    ASSERT_EQ(engine.ties(), 0);
}

TEST(TurnEngineTest, CpuScores) {
    auto engine = TurnEngine(0);
    engine.startNewGame(MAX_TURNS);
    ASSERT_EQ(engine.playerScore(), 0);
    ASSERT_EQ(engine.cpuScore(), 0);
    ASSERT_EQ(engine.ties(), 0);
    engine.playTurn(LOSING_HAND, WINNING_HAND);
    ASSERT_EQ(engine.playerScore(), 0);
    ASSERT_EQ(engine.cpuScore(), 1);
    ASSERT_EQ(engine.ties(), 0);
}

TEST(TurnEngineTest, Tie) {
    auto engine = TurnEngine(0);
    engine.startNewGame(MAX_TURNS);
    ASSERT_EQ(engine.playerScore(), 0);
    ASSERT_EQ(engine.cpuScore(), 0);
    ASSERT_EQ(engine.ties(), 0);
    engine.playTurn(TIE_HAND, TIE_HAND);
    ASSERT_EQ(engine.playerScore(), 0);
    ASSERT_EQ(engine.cpuScore(), 0);
    ASSERT_EQ(engine.ties(), 1);
}
