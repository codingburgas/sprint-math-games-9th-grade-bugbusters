    #include <iostream>
    #include <limits>
    #include "../Bugbusters/header/Console.h"
    #include "../Bugbusters/header/CustomWords.h"
    #include "../Bugbusters/header/Difficulty.h"
    #include "../Bugbusters/header/Game.h"
    #include "../Bugbusters/header/Menu.h"
    #include "../Bugbusters/header/Scoreboard.h"

    using namespace Hang;



    // ------------------------
    // Menu Implementation
    // ------------------------
    Menu::Menu() {}

    void Menu::show() {
        int choice = 0;
        do {
            Console::clearScreen();
            printTitle();
            printOptions();
            choice = getChoice();

            switch (choice) {
            case 1: {
                Console::clearScreen();
                Game game;
                game.startGame();
                Console::pauseForEnter();
                break;
            }
            case 2: {
                Console::clearScreen();
                std::cout << "=== HELP ===\n";
                std::cout << "- Guess letters to reveal the hidden word.\n";
                std::cout << "- You have 6 wrong attempts per word.\n";
                std::cout << "- Custom Words can be added in menu option 4.\n";
                Console::pauseForEnter();
                break;
            }
            case 3: {
                Console::clearScreen();
                std::cout << "=== DIFFICULTY ===\n";
                std::cout << "1. Easy\n2. Medium\n3. Hard\n";
                std::cout << "(Currently stub, can implement later)\n";
                Console::pauseForEnter();
                break;
            }
            case 4: {
                Console::clearScreen();
                CustomWords::listWords();
                std::cout << "\nDo you want to add a word? (y/n): ";
                char ans;
                std::cin >> ans;
                if (ans == 'y' || ans == 'Y') {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Enter word: ";
                    std::string w;
                    std::getline(std::cin, w);
                    CustomWords::addWord(w);
                }
                Console::pauseForEnter();
                break;
            }
            case 5: {
                Console::clearScreen();
                Scoreboard::showHighscores();
                Console::pauseForEnter();
                break;
            }
            case 0: {
                Console::clearScreen();
                std::cout << "Exiting game. Goodbye!\n";
                break;
            }
            default:
                std::cout << "Invalid choice.\n";
                Console::pauseForEnter();
            }

        } while (choice != 0);
    }

    void Menu::printTitle() {
        Console::printCentered(Console::BOLD + "=== HANGMAN ===" + Console::RESET);
        std::cout << "\n";
    }

    void Menu::printOptions() {
        std::cout << "1. Start Game\n";
        std::cout << "2. Help\n";
        std::cout << "3. Difficulty\n";
        std::cout << "4. Custom Words\n";
        std::cout << "5. Highscores\n";
        std::cout << "0. Exit\n";
    }

    int Menu::getChoice() {
        int choice;
        std::cout << "\nEnter your choice: ";
        while (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Try again: ";
        }
        std::cin.ignore(10000, '\n'); // clear newline
        return choice;
    }

    // ------------------------
    // Main Function
    // ------------------------
    int main() {
        Menu menu;
        menu.show();
        return 0;
    }
