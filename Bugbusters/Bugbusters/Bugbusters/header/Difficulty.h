#pragma once
#include <string>

namespace Hang {

    enum Difficulty {
        EASY = 0,
        MEDIUM = 1,
        HARD = 2
    };

    // Optional helper to convert Difficulty to string
    inline std::string difficultyToString(Difficulty d) {
        switch (d) {
        case EASY:   return "Easy";
        case MEDIUM: return "Medium";
        case HARD:   return "Hard";
        default:     return "Unknown";
        }
    }

}