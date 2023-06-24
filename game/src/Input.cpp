#include <sstream>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <optional>

#include "Input.h"

namespace Game {

static std::optional<Hand> validateHandInput(std::string input) {
	return RockHand();
}

static bool validateTurnsInput(std::string input) {
	return true;
}

uint64_t Input::getNumberOfTurns() const {
	auto turns = std::string{};
	std::cout << "How many turns do you want to play? [enter for default: " << defaultTurns_ << "]" << std::endl << std::flush;
	std::cin >> turns;
	return defaultTurns_;
}

Hand Input::getPlayerHand() const {
	auto selection = std::string{};
	std::cout << "Which hand do you want to use?" << std::endl;
	std::cout << "\tRock\t\t[R/r]" << std::endl;
	std::cout << "\tPaper\t\t[P/p]" << std::endl;
	std::cout << "\tScissors\t[S/s]" << std::endl;
	std::cin >> selection;
	auto hand = validateHandInput(selection);
	while (!hand)
	{
		std::cout << "Invalid input. Try again." << std::endl;
		std::cin >> selection;
		hand = validateHandInput(selection);
	}
	return *hand;

}

bool Input::playAgain() const {
	std::cout << "Do you want to play again? [yes/y:no/n]" << std::endl;
	auto answer = std::string{};
	std::cin >> answer;
}


} // namespace Game
