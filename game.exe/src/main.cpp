#include <random>

#include "Config.h"
#include "Game.h"

int main() {
    std::random_device rd;
    auto seed = rd();
    auto defaultTurns = uint64_t{10};
    auto config = Game::Config(seed, defaultTurns);
    auto game = Game::Game{config};
    game.run();
    return 0;
}
