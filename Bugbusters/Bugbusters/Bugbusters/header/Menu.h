
#ifndef MENU_H
#define MENU_H

#include <string>

namespace Game {


    class Menu {
    public:

        static void show();

    private:

        static void clearScreen();
        static void printHeader();
        static void drawSeparator();
        static void waitForEnter();


        static void startGame();
        static void options();              // Options module
        static void help();                 // Help module
        static void highscores();           // Highscore module
        static void customWordsSetting();   // CustomWordsSetting module
        static void difficulty();           // Difficulty module
        static void finalResult();          // FinalResult module
    };

}

#endif // MENU_H
