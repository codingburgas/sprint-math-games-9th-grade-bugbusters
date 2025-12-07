#include "../header/Scoreboard.h"
#include <iostream>
#include <algorithm>

namespace Hang {


    std::vector<int> Scoreboard::topScores;

    void Scoreboard::addScore(int score) {
        topScores.push_back(score);
        std::sort(topScores.begin(), topScores.end(), std::greater<int>());
        if (topScores.size() > 10) topScores.resize(10);
    }

    void Scoreboard::showHighscores() {
        std::cout << "=== Top Scores ===\n";
        if (topScores.empty()) {
            std::cout << "No scores yet.\n";
            return;
        }
        for (size_t i = 0; i < topScores.size(); ++i) {
            std::cout << i + 1 << ". " << topScores[i] << "\n";
        }
    }

}