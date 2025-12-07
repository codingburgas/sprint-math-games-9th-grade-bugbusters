#pragma once
#include <vector>

namespace Hang {

    class Scoreboard {
    public:
        static std::vector<int> topScores;

        static void addScore(int score);
        static void showHighscores();
    };

}

