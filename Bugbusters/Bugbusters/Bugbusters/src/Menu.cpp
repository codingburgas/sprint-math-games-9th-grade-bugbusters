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

    void Menu::show() {
        while (true) {
            clearScreen();
            printHeader();

            std::cout << BOLD << "  Main Menu" << RESET << "\n\n";

            std::cout << "  " << BOLD << GREEN << "1" << RESET << ") " << "Start Game\n";
            std::cout << "  " << BOLD << YELLOW << "2" << RESET << ") " << "Options\n";
            std::cout << "  " << BOLD << MAGENTA << "3" << RESET << ") " << "Help\n";
            std::cout << "  " << BOLD << BLUE << "4" << RESET << ") " << "Highscores\n";
            std::cout << "  " << BOLD << CYAN << "5" << RESET << ") " << "Custom Words Setting\n";
            std::cout << "  " << BOLD << YELLOW << "6" << RESET << ") " << "Difficulty\n";
            std::cout << "  " << BOLD << RED << "7" << RESET << ") " << "Final Result (demo)\n";
            std::cout << "\n  " << BOLD << WHITE << "0" << RESET << ") Exit\n\n";

            drawSeparator();
            std::cout << "Choose an option: ";

            int choice = -1;
            if (!(std::cin >> choice)) {
                // invalid input - clear and continue
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            // consume newline to keep input clean
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (choice) {
            case 1: startGame(); break;
            case 2: options(); break;
            case 3: help(); break;
            case 4: highscores(); break;
            case 5: customWordsSetting(); break;
            case 6: difficulty(); break;
            case 7: finalResult(); break;
            case 0:
                clearScreen();
                std::cout << BOLD << GREEN << "Goodbye! Thanks for playing." << RESET << "\n";
                // small, simple goodbye animation
                for (int i = 0; i < 3; ++i) {
                    std::cout << "." << std::flush;
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                }
                std::cout << "\n";
                return;
            default:
                std::cout << RED << "Invalid option." << RESET << " Try again.\n";
                waitForEnter();
            }
        }
    }

}
