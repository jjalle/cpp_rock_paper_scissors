#pragma once

#include <iostream>
#include <string>

#include "Config.h"
#include "Input.h"
#include "Turn.h"

namespace Game {
	class Game
	{
	public:
		Game(std::istream& input = std::cin, std::ostream& output = std::cout) : Game(Config(), input, output) {};
		Game(const Config& config, std::istream& input = std::cin, std::ostream& output = std::cout);
		void run();
	private:
		TurnEngine turnEngine_;
		Input input_;
	};
}