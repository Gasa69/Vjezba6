#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <limits>

using namespace std;

void unosImena(vector<string>& imena) {
    cout << "Unesite broj imena (1–19): ";
    int N;
    cin >> N;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Neispravan unos broja imena.");
    }
    if (N < 1 || N >= 20) {
        throw out_of_range("Broj imena mora biti između 1 i 19.");
    }

    imena.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
    for (int i = 0; i < N; ++i) {
        cout << "Unesite ime " << (i+1) << ": ";
        string ime;
        getline(cin, ime);
        if (ime.empty()) {
            throw invalid_argument("Ime ne smije biti prazno.");
        }
        imena.push_back(ime);
    }
}

void pregledImena(const vector<string>& imena) {
    if (imena.empty()) {
        throw runtime_error("Nema unesenih imena za prikaz.");
    }
    cout << "\nTrenutna imena:\n";
    for (size_t i = 0; i < imena.size(); ++i) {
        cout << (i+1) << ". " << imena[i] << "\n";
    }
}

 