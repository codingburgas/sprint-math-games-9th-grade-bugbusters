#pragma once
#include <string>
#include <vector>
#include "Difficulty.h"
#include "CustomWords.h"
#include "Scoreboard.h"

namespace Hang {

    class Game {
    public:
        void startGame();

    private:
        std::string chooseWord();
        void displayWord(const std::string& word, const std::vector<char>& guessed);
        void displayHangman(int wrongGuesses);
        bool isWordGuessed(const std::string& word, const std::vector<char>& guessed);
    };

}
