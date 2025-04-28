#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
using namespace std;

void ispisiNiz(const vector<int>& niz) {
    for (int broj : niz) {
        cout << broj << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int>& niz, bool uzlazno, int& koraci, int& zamjene) {
    int n = niz.size();
    koraci = 0;
    zamjene = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            koraci++;
            if ((uzlazno && niz[j] > niz[j + 1]) || (!uzlazno && niz[j] < niz[j + 1])) {
                swap(niz[j], niz[j + 1]);
                zamjene++;
            }
        }
    }
}

void selectionSort(vector<int>& niz, bool uzlazno, int& koraci, int& zamjene) {
    int n = niz.size();
    koraci = 0;
    zamjene = 0;
    for (int i = 0; i < n - 1; i++) {
        int minMaxIndex = i;
        for (int j = i + 1; j < n; j++) {
            koraci++;
            if ((uzlazno && niz[j] < niz[minMaxIndex]) || (!uzlazno && niz[j] > niz[minMaxIndex])) {
                minMaxIndex = j;
            }
        }
        if (minMaxIndex != i) {
            swap(niz[i], niz[minMaxIndex]);
            zamjene++;
        }
    }
}

int main() {
    try {
        srand(time(0)); 

        int N;
        cout << "Unesite broj elemenata niza: ";
        cin >> N;

        if (N <= 0) {
            throw invalid_argument("Broj elemenata mora biti pozitivan!");
        }

        vector<int> niz(N);

        for (int& broj : niz) {
            broj = rand() % 1000 + 1; 
        }

        char izborSortiranja;
        cout << "Sortirati uzlazno - u ili silazno - s? ";
        cin >> izborSortiranja;

        bool uzlazno;
        if (izborSortiranja == 'u' || izborSortiranja == 'U') {
            uzlazno = true;
        } else if (izborSortiranja == 's' || izborSortiranja == 'S') {
            uzlazno = false;
        } else {
            throw invalid_argument("Neispravan unos za sortiranje!");
        }

        char izborAlgoritma;
        cout << "Odaberite algoritam: bubble sort (b) ili selection sort (s): ";
        cin >> izborAlgoritma;

        if (N < 50) {
            cout << "Ulazni niz:\n";
            ispisiNiz(niz);
        }

        int koraci = 0, zamjene = 0;

        if (izborAlgoritma == 'b' || izborAlgoritma == 'B') {
            bubbleSort(niz, uzlazno, koraci, zamjene);
        } else if (izborAlgoritma == 's' || izborAlgoritma == 'S') {
            selectionSort(niz, uzlazno, koraci, zamjene);
        } else {
            throw invalid_argument("Neispravan unos algoritma!");
        }

        if (N < 50) {
            cout << "Sortirani niz:\n";
            ispisiNiz(niz);
        }

        cout << "Ukupno koraka: " << koraci << endl;
        cout << "Ukupno zamjena: " << zamjene << endl;
    }
    catch (const exception& e) {
        cerr << "Greska: " << e.what() << endl;
    }

    return 0;
}
