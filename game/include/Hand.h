#pragma once

#include <random>

namespace Game {
    enum HandType {
        ROCK,
        PAPER,
        SCISSORS
    };
    class Hand {
    public:
        Hand(HandType type): type_(type) {};
        bool operator==(const Hand& other) const {
            return type_ == other.type_;
        }
        bool operator<(const Hand& other) const {
            if (type_ == HandType::ROCK) {
                return (other.type_ == HandType::PAPER);
            } else if (type_ == HandType::PAPER) {
                return (other.type_ == HandType::SCISSORS);
            } else {
                // SCISSORS
                return (other.type_ == HandType::ROCK);
            }
        }
        bool operator>(const Hand& other) const {
            if (*this == other) {
                return false;
            } else {
                return !(*this<other);
            }
        }
        bool operator>=(const Hand& other) const {
            return !(*this<other);
        }
        bool operator!=(const Hand& other) const {
            return !(*this==other);
        }
        bool operator<=(const Hand& other) const {
            return !(*this>other);
        }
        friend std::ostream& operator<< (std::ostream& stream, const Hand& hand) {
            if (hand.type_ == HandType::PAPER) {
                stream << "PAPER";
            } else if (hand.type_ == HandType::ROCK) {
                stream << "ROCK";
            } else {
                stream << "SCISSORS";
            }
            return stream;
        }
    private:
        HandType type_{};
    };
    class ScissorsHand: public Hand {
    public:
        ScissorsHand(): Hand(HandType::SCISSORS) {};
    };
    class RockHand: public Hand {
    public:
        RockHand(): Hand(HandType::ROCK) {};
    };
    class PaperHand: public Hand {
    public:
        PaperHand(): Hand(HandType::PAPER) {};
    };
} // namespace Game