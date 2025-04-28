#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Upotreba: " << argv[0] << " ulazna_datoteka izlazna_datoteka" << std::endl;
        return 1;
    }

    std::ifstream ulaznaDatoteka(argv[1]);
    if (!ulaznaDatoteka) {
        std::cerr << "Nemoguće otvoriti ulaznu datoteku: " << argv[1] << std::endl;
        return 1;
    }

    std::ofstream izlaznaDatoteka(argv[2]);
    if (!izlaznaDatoteka) {
        std::cerr << "Nemoguće otvoriti izlaznu datoteku: " << argv[2] << std::endl;
        return 1;
    }

    std::string redak;
    int brojRedaka = 0;
    while (std::getline(ulaznaDatoteka, redak) && brojRedaka < 20) {
        izlaznaDatoteka << redak << std::endl;
        izlaznaDatoteka << redak << std::endl;
        ++brojRedaka;
    }

    std::cout << "Obrađeno redaka: " << brojRedaka << std::endl;

    return 0;
}
