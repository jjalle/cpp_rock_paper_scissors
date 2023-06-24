#include "Turn.h"
#include <random>
#include <cassert>
#include <cstdlib>
#include <iostream>

namespace Game {

TurnEngine::TurnEngine(const Config& config) : TurnEngine(config.seed()) {
}

TurnEngine::TurnEngine(unsigned int seed) : 
	randEngine_(seed), 
	randDistribution_(0,2),
	turn_(0),
	maxTurns_(0),
	playerScore_(0),
	cpuScore_(0),
	ties_(0)
{
}

void TurnEngine::startNewGame(uint64_t maxTurns) {
	assert(maxTurns > 0);
	maxTurns_ = maxTurns;
	turn_ = 0;
	// Reset scores
	playerScore_ = 0;
	cpuScore_ = 0;
	ties_ = 0;
}

bool TurnEngine::finished() const {
	return (turn_ >= maxTurns_) || isThereAWinner();
}

bool TurnEngine::isThereAWinner()const {
	auto remainingTurns = maxTurns_ - turn_;
	auto differenceInScore = std::max(playerScore_, cpuScore_) - std::min(playerScore_, cpuScore_);
	return differenceInScore > remainingTurns;
}

void TurnEngine::playTurn(const Hand& playerHand, const Hand& cpuHand) {
	assert(maxTurns_ > 0);
	assert(turn_ < maxTurns_);
	if (cpuHand == playerHand) {
		ties_++;
	} else if (cpuHand < playerHand) {
		playerScore_++;
	} else {
		cpuScore_++;
	}
	turn_++;
}

Hand TurnEngine::getRandomCpuHand() {
    auto value = randDistribution_(randEngine_);
	if (value == 0) {
		return RockHand();
	} else if (value == 1) {
		return PaperHand();
	} else {
		return ScissorsHand();
	}
}

void TurnEngine::displayResults() const {
	assert(finished());
	std::cout << std::endl;
	std::cout << "Game finished: ";
	if (playerScore_ < cpuScore_) {
		std::cout << "You lose with " << playerScore_ << " vs " << cpuScore_ << " and " << ties_ << " ties" << std::endl;
	} else if (playerScore_ > cpuScore_) {
		std::cout << "You win with " << playerScore_ << " vs " << cpuScore_ << " and " << ties_ << " ties" << std::endl;
	} else {
		std::cout << "Draw with " << playerScore_ << " and " << ties_ << " ties" << std::endl;
	}
}

} // namespace Game