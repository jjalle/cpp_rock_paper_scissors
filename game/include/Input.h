#pragma once

#include <cstdint>

#include "Hand.h"
#include "Config.h"

namespace Game {
	class Input {
	public:
		Input(const Config& config) : Input(config.defaultTurns()) { };
		Input(uint64_t defaultTurns) : defaultTurns_(defaultTurns), quit_(false) {};
		bool quit() const { return quit_; };
		uint64_t getNumberOfTurns() const;
		Hand getPlayerHand() const;
		bool playAgain() const;
	private:
		uint64_t defaultTurns_;
		bool quit_;
	};
}