#pragma once
#include <string>

namespace Hang {
    namespace Console {

        extern const std::string RESET;
        extern const std::string BOLD;
        extern const std::string RED;
        extern const std::string GREEN;
        extern const std::string YELLOW;
        extern const std::string BLUE;
        extern const std::string MAGENTA;
        extern const std::string CYAN;
        extern const std::string WHITE;

        void clearScreen();
        void printCentered(const std::string& text);
        void pauseForEnter();
    }
}