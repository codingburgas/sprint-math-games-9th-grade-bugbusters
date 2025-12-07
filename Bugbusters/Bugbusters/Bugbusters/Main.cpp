#include "../Bugbusters/header/Menu.h"
#include <iostream>
#include <limits>
#include <chrono>
#include <thread>

using namespace Game;

// Color constants (needed for show())
static const std::string RESET = "\033[0m";
static const std::string BOLD = "\033[1m";
static const std::string RED = "\033[31m";
static const std::string GREEN = "\033[32m";
static const std::string YELLOW = "\033[33m";
static const std::string BLUE = "\033[34m";
static const std::string MAGENTA = "\033[35m";
static const std::string CYAN = "\033[36m";
static const std::string WHITE = "\033[37m";

// ONLY Menu::show() goes here
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
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

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

// Standard main
int main() {
    Menu::show();
    return 0;
}
