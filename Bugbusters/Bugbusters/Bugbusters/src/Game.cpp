#include "../header/Game.h"
#include "../header/CustomWords.h"
#include <iostream>
#include <algorithm>
#include <cctype>

namespace Hang {

    // List of default words if no custom words exist
    static std::vector<std::string> defaultWords = { "apple", "banana", "cherry", "hangman" };

    void Game::startGame() {
        // Choose a word from custom words if any, otherwise default
        std::string word;
        if (!CustomWords::words.empty()) {
            word = CustomWords::words[0]; // simple, pick first word
        }
        else {
            word = defaultWords[0];
        }

        std::vector<char> guessed(word.size(), '_');
        int wrongGuesses = 0;
        const int maxAttempts = 6;

        while (wrongGuesses < maxAttempts && !isWordGuessed(word, guessed)) {
            displayWord(word, guessed);

            std::cout << "Guess a letter: ";
            char guess;
            std::cin >> guess;
            guess = static_cast<char>(std::tolower(guess));

            bool correct = false;
            for (size_t i = 0; i < word.size(); ++i) {
                if (word[i] == guess && guessed[i] == '_') {
                    guessed[i] = guess;
                    correct = true;
                }
            }

            if (correct) {
                std::cout << "Correct!\n";
            }
            else {
                std::cout << "Wrong guess, try again!\n";
                ++wrongGuesses;
            }
        }

        if (isWordGuessed(word, guessed)) {
            std::cout << "\nCongratulations! You won!\n";
        }
        else {
            std::cout << "\nYou lost! The word was: " << word << "\n";
        }

        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

    void Game::displayWord(const std::string& word, const std::vector<char>& guessed) {
        for (char c : guessed) std::cout << c << ' ';
        std::cout << "\n";
    }

    bool Game::isWordGuessed(const std::string& word, const std::vector<char>& guessed) {
        return std::all_of(guessed.begin(), guessed.end(), [](char c) { return c != '_'; });
    }

}
