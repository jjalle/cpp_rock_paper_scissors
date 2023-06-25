#include <cassert>
#include <cstdlib>
#include <iostream>
#include <random>

#include "Turn.h"

namespace Game {

TurnEngine::TurnEngine(const Config& config, std::ostream& output) : TurnEngine(config.seed(), output) {
}

TurnEngine::TurnEngine(unsigned int seed, std::ostream& output) : 
    randEngine_(seed), 
    randDistribution_(0,2),
    turn_(0),
    maxTurns_(0),
    playerScore_(0),
    cpuScore_(0),
    ties_(0),
    output_(output)
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
    output_ << "New game started for " << maxTurns_ << " turns (or until winner is found)" << std::endl;
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
    output_ << "Turn " << turn_ << ": Player=" << playerHand << ", CPU=" << cpuHand << ". Result: ";
    if (cpuHand == playerHand) {
        ties_++;
        output_ << "Tie." << std::endl;
    } else if (cpuHand < playerHand) {
        playerScore_++;
        output_ << "Win." << std::endl;
    } else {
        cpuScore_++;
        output_ << "Lose." << std::endl;
    }
    output_ << std::endl;
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
    output_ << std::endl;
    output_ << "Game finished: ";
    if (playerScore_ < cpuScore_) {
        output_ << "You lose with " << playerScore_ << " vs " << cpuScore_ << " and " << ties_ << " ties" << std::endl;
    } else if (playerScore_ > cpuScore_) {
        output_ << "You win with " << playerScore_ << " vs " << cpuScore_ << " and " << ties_ << " ties" << std::endl;
    } else {
        output_ << "Draw with " << playerScore_ << " and " << ties_ << " ties" << std::endl;
    }
}

} // namespace Game