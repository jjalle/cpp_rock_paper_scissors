#pragma once

#include <cstdint>
#include <iostream>

#include "Config.h"
#include "Hand.h"

namespace Game {
    class Input {
    public:
        Input(const Config& config, std::istream& input = std::cin, std::ostream& output = std::cout) : Input(config.defaultTurns(), input, output) { };
        Input(uint64_t defaultTurns, std::istream& input = std::cin, std::ostream& output = std::cout) : defaultTurns_(defaultTurns), quit_(false), input_(input), output_(output) {};
        uint64_t getNumberOfTurns() const;
        Hand getPlayerHand() const;
    private:
        uint64_t defaultTurns_;
        bool quit_;
        std::istream& input_;
        std::ostream& output_;
    };
}