// src/Menu.cpp
#include "../header/Menu.h"
#include <iostream>
#include <limits>
#include <chrono>
#include <thread>

namespace Game {

    static const std::string RESET = "\033[0m";
    static const std::string BOLD = "\033[1m";
    static const std::string RED = "\033[31m";
    static const std::string GREEN = "\033[32m";
    static const std::string YELLOW = "\033[33m";
    static const std::string BLUE = "\033[34m";
    static const std::string MAGENTA = "\033[35m";
    static const std::string CYAN = "\033[36m";
    static const std::string WHITE = "\033[37m";

    void Menu::clearScreen() {
        for (int i = 0; i < 50; ++i) std::cout << '\n';
    }

    void Menu::printHeader() {
        std::cout << BOLD << CYAN;
        std::cout << "  ╔══════════════════════════════════════════════════╗\n";
        std::cout << "  ║" << GREEN << "    ░█─░█ ░█▀▀█ ░█▀▀█ ░█─░█ ░█▀▀█ ░█▀▀▀█    " << CYAN << "║\n";
        std::cout << "  ║" << GREEN << "    ░█░█░ ░█▄▄█ ░█▄▄█ ░█─░█ ░█▄▄█ ░█──░█    " << CYAN << "║\n";
        std::cout << "  ║" << GREEN << "    ░█▄▀▄ ░█─░█ ░█─░█ ─▀▄▄▀ ░█─░█ ░█▄▄▄█    " << CYAN << "║\n";
        std::cout << "  ╚══════════════════════════════════════════════════╝" << RESET << "\n\n";
        std::cout << BOLD << "            " << YELLOW << "H A N G M A N  -  C++ Edition" << RESET << "\n\n";
    }

    void Menu::drawSeparator() {
        std::cout << BOLD << WHITE << "----------------------------------------------------" << RESET << "\n";
    }

    void Menu::waitForEnter() {
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // ----- Stubs (replace with real module calls later) -----
    void Menu::startGame() {
        clearScreen();
        std::cout << BOLD << GREEN << "[ Start Game ]" << RESET << "\n\n";
        std::cout << "Launching game module (StartOfGame / InGame) ...\n";
        std::cout << "(When implemented this will start a hangman round.)\n";
        waitForEnter();
    }

    void Menu::options() {
        clearScreen();
        std::cout << BOLD << YELLOW << "[ Options ]" << RESET << "\n\n";
        std::cout << "1) Difficulty\n2) Custom words\n3) UI Settings (toggle colors)\n";
        std::cout << "(Routes to Options / Difficulty / CustomWordsSetting modules.)\n";
        waitForEnter();
    }

    void Menu::help() {
        clearScreen();
        std::cout << BOLD << MAGENTA << "[ Help ]" << RESET << "\n\n";
        std::cout << "How to play Hangman:\n";
        std::cout << " - Guess letters to reveal the hidden word.\n";
        std::cout << " - You have a limited number of wrong attempts.\n";
        std::cout << " - Use Custom Words to add your own words for fun rounds.\n";
        waitForEnter();
    }

    void Menu::highscores() {
        clearScreen();
        std::cout << BOLD << BLUE << "[ Highscores ]" << RESET << "\n\n";
        std::cout << "Highscores will be loaded from a simple text file and shown here.\n";
        std::cout << "(Implement file I/O in the Highscore module.)\n";
        waitForEnter();
    }

    void Menu::customWordsSetting() {
        clearScreen();
        std::cout << BOLD << CYAN << "[ Custom Words Setting ]" << RESET << "\n\n";
        std::cout << "Add, list and remove custom words for custom games.\n";
        std::cout << "(This module should read/write a small .txt file.)\n";
        waitForEnter();
    }

    void Menu::difficulty() {
        clearScreen();
        std::cout << BOLD << YELLOW << "[ Difficulty ]" << RESET << "\n\n";
        std::cout << "Choose difficulty levels: Easy, Medium, Hard.\n";
        std::cout << "(Difficulty affects word length and allowed attempts.)\n";
        waitForEnter();
    }

    void Menu::finalResult() {
        clearScreen();
        std::cout << BOLD << RED << "[ Final Result ]" << RESET << "\n\n";
        std::cout << "Show final score, stats and optionally save to Highscores.\n";
        waitForEnter();
    }

    // ----------------------------------------------------------
    // NOTE: Menu::show() has been removed and moved to main.cpp

}
