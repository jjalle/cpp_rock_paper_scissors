#pragma once

#include <string>
#include "Input.h"
#include "Turn.h"
#include "Config.h"

namespace Game {
	class Game
	{
	public:
		Game() : Game(Config()) {};
		Game(const Config& config);
		int run();
		bool isRunning() const { return running_; };
		void quit() { running_ = false; };
	private:
		void menu();
		void playGame();
		TurnEngine turnEngine_;
		bool running_;
		Input input_;
	};
}