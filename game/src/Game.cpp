#include <functional>
#include <sstream>

#include "Game.h"

namespace Game {

Game::Game(const Config& config, std::istream& input, std::ostream& output) :
    turnEngine_(config, output),
    input_(config, input, output)
{
}

void Game::run() {
    auto turns = input_.getNumberOfTurns();
    turnEngine_.startNewGame(turns);
    while (!turnEngine_.finished()) {
        auto playerHand = input_.getPlayerHand();
        auto cpuHand = turnEngine_.getRandomCpuHand();
        turnEngine_.playTurn(playerHand, cpuHand);
    }
    turnEngine_.displayResults();
}

} // namespace Game
