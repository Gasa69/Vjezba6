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

