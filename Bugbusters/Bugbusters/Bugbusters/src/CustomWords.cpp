#include "../header/CustomWords.h"
#include <iostream>

namespace Hang {

    // ✅ Define the static member exactly once
    std::vector<std::string> CustomWords::words;

    void CustomWords::addWord(const std::string& word) {
        words.push_back(word);
    }

    void CustomWords::listWords() {
        std::cout << "=== Custom Words ===\n";
        if (words.empty()) {
            std::cout << "No custom words added yet.\n";
            return;
        }
        for (size_t i = 0; i < words.size(); ++i) {
            std::cout << i + 1 << ". " << words[i] << "\n";
        }
    }

    void CustomWords::removeWord(int index) {
        if (index >= 0 && index < static_cast<int>(words.size())) {
            words.erase(words.begin() + index);
        }
    }

}
