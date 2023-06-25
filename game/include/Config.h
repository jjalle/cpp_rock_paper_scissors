#pragma once

#include <cstddef>
#include <cstdint>

namespace Game {
    class Config {
    public:
        Config(unsigned int seed = 0, uint64_t defaultTurns = 10) : seed_{ seed }, defaultTurns_{ defaultTurns } {};
        auto defaultTurns() const noexcept { return defaultTurns_; };
        auto seed() const noexcept { return seed_; };
    private:
        unsigned int seed_;
        uint64_t defaultTurns_;
    };
}