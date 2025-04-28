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

  