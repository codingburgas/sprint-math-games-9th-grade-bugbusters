#pragma once

namespace Hang {

    class Menu {
    public:
        Menu();
        void show();

    private:
        void printTitle();
        void printOptions();
        int getChoice();
    };

}
