#define GTEST_LANG_CXX11 1
#include <gtest/gtest.h>

#include <sstream>
#include "Turn.h"
#include "Hand.h"

using namespace Game;


const static auto MAX_TURNS = uint64_t{2};
const static auto WINNING_HAND = RockHand();
const static auto LOSING_HAND = ScissorsHand();
const static auto TIE_HAND = RockHand();

static void winTurn(TurnEngine& engine) {
    engine.playTurn(WINNING_HAND, LOSING_HAND);
}

static void loseTurn(TurnEngine& engine) {
    engine.playTurn(LOSING_HAND, WINNING_HAND);
}

static void tieTurn(TurnEngine& engine) {
    engine.playTurn(TIE_HAND, TIE_HAND);
}

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
    winTurn(engine);
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
    loseTurn(engine);
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
    tieTurn(engine);
    ASSERT_EQ(engine.playerScore(), 0);
    ASSERT_EQ(engine.cpuScore(), 0);
    ASSERT_EQ(engine.ties(), 1);
}

TEST(TurnEngineTest, EarlyFinishEven) {
    const auto EVEN_TURNS = uint64_t{4};
    auto engine = TurnEngine(0);
    engine.startNewGame(EVEN_TURNS);
    ASSERT_FALSE(engine.finished());
    winTurn(engine);
    ASSERT_FALSE(engine.finished());
    winTurn(engine);
    ASSERT_FALSE(engine.finished());
    winTurn(engine);
    ASSERT_TRUE(engine.finished());
    ASSERT_LT(engine.getCurrentTurn(), EVEN_TURNS);
}

TEST(TurnEngineTest, EarlyFinishOdd) {
    const auto ODD_TURNS = uint64_t{ 5 };
    auto engine = TurnEngine(0);
    engine.startNewGame(ODD_TURNS);
    ASSERT_FALSE(engine.finished());
    winTurn(engine);
    ASSERT_FALSE(engine.finished());
    winTurn(engine);
    ASSERT_FALSE(engine.finished());
    winTurn(engine);
    ASSERT_TRUE(engine.finished());
    ASSERT_LT(engine.getCurrentTurn(), ODD_TURNS);
}

TEST(TurnEngineTest, DisplayWin) {
    auto output = std::string{""};
    auto ostream = std::ostringstream{output};
    auto engine = TurnEngine(0, ostream);
    engine.startNewGame(1);
    winTurn(engine);
    engine.displayResults();
    auto out = ostream.str();
    ASSERT_NE(out.find("You win", 0), std::string::npos);
}

TEST(TurnEngineTest, DisplayLose) {
    auto output = std::string{""};
    auto ostream = std::ostringstream{output};
    auto engine = TurnEngine(0, ostream);
    engine.startNewGame(1);
    loseTurn(engine);
    engine.displayResults();
    auto out = ostream.str();
    ASSERT_NE(out.find("You lose", 0), std::string::npos);
}

TEST(TurnEngineTest, DisplayDraw) {
    auto output = std::string{""};
    auto ostream = std::ostringstream{output};
    auto engine = TurnEngine(0, ostream);
    engine.startNewGame(1);
    tieTurn(engine);
    engine.displayResults();
    auto out = ostream.str();
    ASSERT_NE(out.find("Draw", 0), std::string::npos);
}