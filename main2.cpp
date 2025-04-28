#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <limits>
#include <stdexcept>

using namespace std;

void unosBrojeva(vector<int>& brojevi) {
    int N;
    cout << "Unesite broj elemenata: ";
    cin >> N;

    if (cin.fail() || N < 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Neispravan unos broja elemenata.");
    }

    brojevi.clear();
    for (int i = 0; i < N; i++) {
        int broj;
        cout << "Unesite broj " << i + 1 << ": ";
        cin >> broj;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Neispravan unos broja.");
        }

        brojevi.push_back(broj);
    }
}

void ispisObrnuto(const vector<int>& brojevi) {
    cout << "Brojevi unazad: ";
    for (auto it = brojevi.rbegin(); it != brojevi.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void ispisRazlika(const vector<int>& brojevi) {
    cout << "Razlike: ";
    for (size_t i = 1; i < brojevi.size(); i++) {
        cout << brojevi[i] - brojevi[i - 1] << " ";
    }
    cout << endl;
}

void pronadiMinMax(const vector<int>& brojevi) {
    if (brojevi.empty()) throw runtime_error("Nema unesenih brojeva.");

    int minIndex = 0, maxIndex = 0;
    for (size_t i = 1; i < brojevi.size(); i++) {
        if (brojevi[i] < brojevi[minIndex]) minIndex = i;
        if (brojevi[i] > brojevi[maxIndex]) maxIndex = i;
    }

    cout << "Najmanji broj: " << brojevi[minIndex] << " na indeksu " << minIndex << endl;
    cout << "Najveci broj: " << brojevi[maxIndex] << " na indeksu " << maxIndex << endl;
}

void snimiUDatoteku(const vector<int>& brojevi) {
    string nazivDatoteke;
    cout << "Unesite naziv datoteke: ";
    cin >> nazivDatoteke;

    ofstream datoteka(nazivDatoteke);
    if (!datoteka.is_open()) {
        throw runtime_error("Greška kod otvaranja datoteke za pisanje.");
    }

    datoteka << brojevi.size() << endl;
    for (int broj : brojevi) {
        datoteka << broj << endl;
    }

    cout << "Podaci su uspješno spremljeni." << endl;
}

void ucitajIzDatoteke(vector<int>& brojevi) {
    string nazivDatoteke;
    cout << "Unesite naziv datoteke: ";
    cin >> nazivDatoteke;

    ifstream datoteka(nazivDatoteke);
    if (!datoteka.is_open()) {
        throw runtime_error("Greška kod otvaranja datoteke za čitanje.");
    }

    int N;
    datoteka >> N;
    if (datoteka.fail() || N < 0) {
        throw runtime_error("Neispravan format datoteke (broj elemenata).");
    }

    brojevi.clear();
    int broj;
    while (datoteka >> broj) {
        brojevi.push_back(broj);
    }

    cout << "Podaci su uspješno učitani." << endl;
}

void ispisSortiranog(const vector<int>& brojevi) {
    vector<int> sortirani = brojevi;
    sort(sortirani.begin(), sortirani.end());
    cout << "Sortirani brojevi: ";
    for (int broj : sortirani) {
        cout << broj << " ";
    }
    cout << endl;
}

int main() {
    vector<int> brojevi;
    int izbor;

    do {
        cout << "\nIzbornik:" << endl;
        cout << "1. Unos brojeva" << endl;
        cout << "2. Ispis brojeva unazad" << endl;
        cout << "3. Ispis razlika izmedju brojeva" << endl;
        cout << "4. Najmanji i najveci broj" << endl;
        cout << "5. Snimanje u datoteku" << endl;
        cout << "6. Učitavanje iz datoteke" << endl;
        cout << "7. Ispis sortiranog popisa" << endl;
        cout << "8. Izlaz" << endl;
        cout << "Odabir: ";
        cin >> izbor;

        try {
            switch (izbor) {
                case 1:
                    unosBrojeva(brojevi);
                    break;
                case 2:
                    ispisObrnuto(brojevi);
                    break;
                case 3:
                    ispisRazlika(brojevi);
                    break;
                case 4:
                    pronadiMinMax(brojevi);
                    break;
                case 5:
                    snimiUDatoteku(brojevi);
                    break;
                case 6:
                    ucitajIzDatoteke(brojevi);
                    break;
                case 7:
                    ispisSortiranog(brojevi);
                    break;
                case 8:
                    cout << "Izlaz iz programa." << endl;
                    break;
                default:
                    cout << "Neispravan unos!" << endl;
            }
        } catch (const exception& e) {
            cout << "Greška: " << e.what() << endl;
        }

    } while (izbor != 8);

    return 0;
}