#ifndef GENERATE_LOREM_HPP
#define GENERATE_LOREM_HPP

#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>  
#include <ctime>    

void generateLoremFile(const std::string& filename, int wordCount) {
    std::vector<std::string> loremWords = {
        "Lorem", "ipsum", "dolor", "sit", "amet", "consectetur", "adipiscing", "elit",
        "sed", "do", "eiusmod", "tempor", "incididunt", "ut", "labore", "et", "dolore",
        "magna", "aliqua", "ut", "enim", "ad", "minim", "veniam", "quis", "nostrud",
        "exercitation", "ullamco", "laboris", "nisi", "aliquip", "ex", "ea", "commodo", 
        "consequat", "duis", "aute", "irure", "dolor", "in", "reprehenderit", "voluptate",
        "velit", "esse", "cillum", "dolore", "eu", "fugiat", "nulla", "pariatur"
    };

    // Inicjalizacja generatora losowości
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Nie udało się otworzyć pliku do zapisu.");
    }

    // Generujemy losowe słowa
    for (int i = 0; i < wordCount; ++i) {
        int randomIndex = std::rand() % loremWords.size();  // Losowy indeks z zakresu słów
        outputFile << loremWords[randomIndex] << " ";  // Dodaj losowe słowo do pliku

        if ((i + 1) % 10 == 0) {
            outputFile << "\n";  // Nowa linia po co 10 słowach dla czytelności
        }
    }

    outputFile.close(); 
}

#endif 
