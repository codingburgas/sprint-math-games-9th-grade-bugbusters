#include "../header/Console.h"
#include <iostream>
#include <limits>

namespace Hang {
    namespace Console {

        const std::string RESET = "\033[0m";
        const std::string BOLD = "\033[1m";
        const std::string RED = "\033[31m";
        const std::string GREEN = "\033[32m";
        const std::string YELLOW = "\033[33m";
        const std::string BLUE = "\033[34m";
        const std::string MAGENTA = "\033[35m";
        const std::string CYAN = "\033[36m";
        const std::string WHITE = "\033[37m";

        void clearScreen() {
            for (int i = 0; i < 50; ++i) std::cout << '\n';
        }

        void printCentered(const std::string& text) {
            const int pad = 6;
            for (int i = 0; i < pad; ++i) std::cout << ' ';
            std::cout << text << "\n";
        }

        void pauseForEnter() {
            std::cout << "\nPress Enter to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    }
}