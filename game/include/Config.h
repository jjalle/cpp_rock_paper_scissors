#pragma once

#include <cstddef>
#include <cstdint>

namespace Game {
    class Config {
    public:
        Config() : Config(0, 10) {};
        Config(unsigned int seed, uint64_t defaultTurns) : seed_{ seed }, defaultTurns_{ defaultTurns } {};
        auto defaultTurns() const noexcept { return defaultTurns_; };
        auto seed() const noexcept { return seed_; };
    private:
        unsigned int seed_;
        uint64_t defaultTurns_;
    };
}