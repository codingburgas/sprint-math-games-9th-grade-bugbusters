#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Game {
public:
    void startGame(); // Start the game

private:
    string chooseWord(int category);
    void displayWord(const string& word, const vector<char>& guessed);
    void displayHangman(int wrongGuesses);
    bool isWordGuessed(const string& word, const vector<char>& guessed);
    void showHint(const string& word, vector<char>& guessed);
    void printCentered(const string& text, int color = 15);

    int maxAttempts;
    int score;
};
