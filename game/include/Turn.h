#pragma once

#include <cstdint>

#include "Config.h"
#include "Hand.h"

namespace Game {
	class TurnEngine {
	public:
		TurnEngine(const Config& config);
		TurnEngine(unsigned int seed);
		void startNewGame(uint64_t maxTurns);
		uint64_t getCurrentTurn() const { return turn_; };
		bool finished() const;
		void playTurn(const Hand& playerHand, const Hand& cpuHand);
		void displayResults() const;
		uint64_t playerScore() const { return playerScore_; };
		uint64_t cpuScore() const { return cpuScore_; };
		uint64_t ties() const { return ties_; };
		Hand getRandomCpuHand();
	private:
		bool isThereAWinner() const;
		std::mt19937 randEngine_;
		std::uniform_int_distribution<int> randDistribution_;
		uint64_t turn_;
		uint64_t maxTurns_;
		uint64_t playerScore_;
		uint64_t cpuScore_;
		uint64_t ties_;
	};
}