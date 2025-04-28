#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include <limits>

using namespace std;

struct Student {
    string ime;
    string prezime;
    int bodovi;
};

void unosStudenata(vector<Student>& studenti) {
    int N;
    cout << "Unesite broj studenata: ";
    cin >> N;

    if (cin.fail() || N < 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Neispravan unos broja studenata.");
    }

    studenti.clear();
    for (int i = 0; i < N; i++) {
        Student s;
        cout << "Unesite ime studenta: ";
        cin >> s.ime;
        cout << "Unesite prezime studenta: ";
        cin >> s.prezime;
        cout << "Unesite bodove studenta: ";
        cin >> s.bodovi;

        if (cin.fail() || s.bodovi < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Neispravan unos bodova.");
        }

        studenti.push_back(s);
    }
}

void ispisStudenata(const vector<Student>& studenti) {
    if (studenti.empty()) throw runtime_error("Nema unesenih studenata.");

    cout << left << setw(20) << "Ime" << setw(20) << "Prezime" << right << setw(7) << "Bodovi" << endl;
    cout << string(47, '-') << endl;
    for (const auto& s : studenti) {
        cout << left << setw(20) << s.ime << setw(20) << s.prezime << right << setw(7) << s.bodovi << endl;
    }
}

void snimiUDatoteku(const vector<Student>& studenti) {
    if (studenti.empty()) throw runtime_error("Nema podataka za snimanje.");

    string nazivDatoteke;
    cout << "Unesite naziv datoteke: ";
    cin >> nazivDatoteke;

    ofstream datoteka(nazivDatoteke);
    if (!datoteka) throw runtime_error("Greška pri otvaranju datoteke!");

    datoteka << studenti.size() << endl;
    for (const auto& s : studenti) {
        datoteka << s.ime << " " << s.prezime << " " << s.bodovi << endl;
    }

    cout << "Podaci su spremljeni u datoteku." << endl;
}

void ucitajIzDatoteke(vector<Student>& studenti) {
    string nazivDatoteke;
    cout << "Unesite naziv datoteke: ";
    cin >> nazivDatoteke;

    ifstream datoteka(nazivDatoteke);
    if (!datoteka) throw runtime_error("Greška pri otvaranju datoteke!");

    