#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <errno.h>
#include <iostream>
#include <optional>
#include <sstream>

#include "Input.h"

namespace Game {

static std::optional<Hand> validateHandInput(char input) {
    if (input == 'r' || input == 'R') {
        return RockHand();
    } else if (input == 's' || input == 'S') {
        return ScissorsHand();
    } else if (input == 'p' || input == 'P') {
        return PaperHand();
    } else {
        return std::nullopt;
    }
}

uint64_t Input::getNumberOfTurns() const {
    output_ << "How many turns do you want to play? [any non-integer input or 0 for default: " << defaultTurns_ << " turns]" << std::endl << std::flush;
    auto istr = std::string{};
    std::getline(input_, istr);
    if (istr.empty()) {
        return defaultTurns_;
    }
    // errno can be set to any non-zero value by a library function call
    // regardless of whether there was an error, so it needs to be cleared
    // in order to check the error set by strtol
    errno = 0;
    char* p_end{};
    const auto integerValue = std::strtol(istr.c_str(), &p_end, 10);
    if ((istr.c_str() == p_end) || (errno == ERANGE) || (integerValue <= 0)) {
        return defaultTurns_;
    } else {
        // integerValue is valid and positive
        return static_cast<uint64_t>(integerValue);
    }
}

Hand Input::getPlayerHand() const {
    output_ << "Which hand do you want to use? [use leter + enter]" << std::endl;
    output_ << "\tRock\t\t[R/r]" << std::endl;
    output_ << "\tPaper\t\t[P/p]" << std::endl;
    output_ << "\tScissors\t[S/s]" << std::endl;
    auto selection = char{};
    input_ >> selection;
    auto hand = validateHandInput(selection);
    while (!hand)
    {
        output_ << "Invalid input. Try again." << std::endl;
        input_ >> selection;
        hand = validateHandInput(selection);
    }
    return *hand;
}

} // namespace Game