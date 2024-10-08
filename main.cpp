#include "generate_lorem.hpp"
#include "word_count.hpp"
#include <iostream>

int main() {
    try {
        // Generowanie pliku z losowymi słowami
        const std::string filename = "output.txt";
        generateLoremFile(filename, 100);  // Tworzymy plik z 100 losowymi słowami
        std::cout << "Plik wygenerowany pomyślnie!" << std::endl;

        std::string wordToCount = "ipsum";
        int count = countWordInFile(filename, wordToCount);
        std::cout << "Słowo \"" << wordToCount << "\" wystąpiło " << count << " razy." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
