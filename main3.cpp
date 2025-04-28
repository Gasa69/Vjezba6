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

    int N;
    datoteka >> N;

    if (datoteka.fail() || N < 0) throw runtime_error("Neispravan format datoteke.");

    studenti.clear();
    for (int i = 0; i < N; i++) {
        Student s;
        datoteka >> s.ime >> s.prezime >> s.bodovi;
        if (datoteka.fail()) throw runtime_error("Greška pri čitanju podataka.");
        studenti.push_back(s);
    }

    cout << "Podaci su učitani iz datoteke." << endl;
}

void sortirajStudente(vector<Student>& studenti, bool uzlazno) {
    if (studenti.empty()) throw runtime_error("Nema studenata za sortiranje.");

    sort(studenti.begin(), studenti.end(), [uzlazno](const Student& a, const Student& b) {
        return uzlazno ? a.bodovi < b.bodovi : a.bodovi > b.bodovi;
    });

    cout << "Studenti su sortirani." << endl;
}

int main() {
    vector<Student> studenti;
    int izbor;

    do {
        cout << "\nIzbornik:" << endl;
        cout << "1. Unos studenata" << endl;
        cout << "2. Ispis studenata" << endl;
        cout << "3. Snimanje u datoteku" << endl;
        cout << "4. Učitavanje iz datoteke" << endl;
        cout << "5. Sortiranje (1 - uzlazno, 0 - silazno)" << endl;
        cout << "6. Izlaz" << endl;
        cout << "Odabir: ";
        cin >> izbor;

        try {
            switch (izbor) {
                case 1:
                    unosStudenata(studenti);
                    break;
                case 2:
                    ispisStudenata(studenti);
                    break;
                case 3:
                    snimiUDatoteku(studenti);
                    break;
                case 4:
                    ucitajIzDatoteke(studenti);
                    break;
                case 5: {
                    bool uzlazno;
                    cout << "Unesite 1 za uzlazno ili 0 za silazno sortiranje: ";
                    cin >> uzlazno;
                    if (cin.fail()) throw invalid_argument("Neispravan unos za sortiranje.");
                    sortirajStudente(studenti, uzlazno);
                    break;
                }
                case 6:
                    cout << "Izlaz iz programa." << endl;
                    break;
                default:
                    cout << "Neispravan unos!" << endl;
            }
        } catch (const exception& e) {
            cout << "Greška: " << e.what() << endl;
        }

    } while (izbor != 6);

    return 0;
}