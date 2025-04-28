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

void snimiUDatoteku(const vector<string>& imena) {
    if (imena.empty()) {
        throw runtime_error("Nema podataka za spremanje.");
    }
    cout << "Unesite naziv izlazne datoteke: ";
    string fname;
    cin >> fname;
    ofstream out(fname);
    if (!out.is_open()) {
        throw runtime_error("Ne mogu otvoriti datoteku za pisanje.");
    }

    out << imena.size() << "\n";

    for (auto const& ime : imena) {
        out << ime << "\n";
    }
    out.close();
    cout << "Podaci su uspješno spremljeni u '" << fname << "'\n";
}

void ucitajIzDatoteke(vector<string>& imena) {
    cout << "Unesite naziv ulazne datoteke: ";
    string fname;
    cin >> fname;
    ifstream in(fname);
    if (!in.is_open()) {
        throw runtime_error("Ne mogu otvoriti datoteku za čitanje.");
    }

    int N;
    in >> N;
    if (in.fail() || N < 1 || N >= 20) {
        throw runtime_error("Neispravan broj imena u datoteci.");
    }
    in.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> temp;
    temp.reserve(N);
    for (int i = 0; i < N; ++i) {
        string ime;
        if (!getline(in, ime)) {
            throw runtime_error("Datoteka se neočekivano prekinula pri učenju imena.");
        }
        temp.push_back(ime);
    }
    imena = move(temp);
    in.close();
    cout << "Podaci su uspješno učitani iz '" << fname << "'\n";
}

int main() {
    vector<string> imena;
    int izbor = 0;

    do {
        cout << "\n=== IZBORNIK ===\n"
             << "1) Unos imena\n"
             << "2) Pregled imena\n"
             << "3) Snimanje u datoteku\n"
             << "4) Učitavanje iz datoteke\n"
             << "5) Izlaz\n"
             << "Odabir: ";
        cin >> izbor;

        try {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Neispravan unos opcije.");
            }

            switch (izbor) {
                case 1:
                    unosImena(imena);
                    break;
                case 2:
                    pregledImena(imena);
                    break;
                case 3:
                    snimiUDatoteku(imena);
                    break;
                case 4:
                    ucitajIzDatoteke(imena);
                    break;
                case 5:
                    cout << "Izlaz iz programa.\n";
                    break;
                default:
                    cout << "Nepoznata opcija, pokušajte ponovno.\n";
            }
        }
        catch (const exception& e) {
            cout << "Greška: " << e.what() << "\n";
        }

    } while (izbor != 5);

    return 0;
}