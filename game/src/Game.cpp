#include <sstream>
#include <functional>

#include "Game.h"

namespace Game {

Game::Game(const Config& config) : 
	turnEngine_(config), 
	running_(true), 
	input_(config)
{
}

void Game::menu() {
 	auto turns = input_.getNumberOfTurns();
	if (input_.quit())
	{
		quit();
	} else {
		turnEngine_.startNewGame(turns);
	}
}

void Game::playGame() {
	while (!turnEngine_.finished()) {
		auto playerHand = input_.getPlayerHand();
		if (input_.quit()) {
			quit();
		} else {
			auto cpuHand = turnEngine_.getRandomCpuHand();
			turnEngine_.playTurn(playerHand, cpuHand);
		}
	}
	turnEngine_.displayResults();
}

int Game::run() {
	running_ = true;
	while (running_) {
		menu();
		playGame();
	}
	return 0;
}

} // namespace Game
