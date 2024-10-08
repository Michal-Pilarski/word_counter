#ifndef WORD_COUNT_HPP
#define WORD_COUNT_HPP

#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>

int countWordInFile(const std::string& filename, const std::string& word) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Nie udało się otworzyć pliku.");
    }

    std::string line;
    int count = 0;
    // Przechodzimy przez każdy wiersz pliku
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        // Przechodzimy przez każde słowo w wierszu
        while (iss >> token) {
            // Porównanie słów, ignorując wielkość liter
            if (std::equal(word.begin(), word.end(), token.begin(), token.end(), 
                           [](char a, char b) { return std::tolower(a) == std::tolower(b); })) {
                count++;
            }
        }
    }

    file.close();
    return count;
}

#endif 
