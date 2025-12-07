#pragma once
#include <string>
#include <vector>

namespace Hang {

    class CustomWords {
    public:
        // Static member declaration
        static std::vector<std::string> words;

        // Static functions only
        static void addWord(const std::string& word);
        static void listWords();
        static void removeWord(int index);
    };

}
