#include <random>

#include "Config.h"
#include "Game.h"

int main() {
    std::random_device rd;
    auto seed = rd();
    auto config = Game::Config(seed);
    auto game = Game::Game{config};
    game.run();
    return 0;
}
