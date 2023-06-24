#pragma once
#include <cstddef>
#include <cstdint>

namespace Game {
	class Config {
	public:
		Config() : seed_{ 0 }, defaultTurns_{ 10 } {};
		auto defaultTurns() const { return defaultTurns_; };
		auto seed() const { return seed_; };
	private:
		unsigned int seed_;
		uint64_t defaultTurns_;
	};
}