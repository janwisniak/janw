#include <iostream>
#include <cmath>

using namespace std;

// Wyszukiwanie liniowe
int wyszukiwanieLiniowe(int *tab, int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (tab[i] == key) {
            return i; // Znaleziono klucz, zwracamy indeks
        }
    }
    return -1; // Klucz nie został znaleziony
}

// Wyszukiwanie liniowe z wartownikiem
int wyszukiwanieLinioweWartownik(int *tab, int size, int key) {
    tab[size] = key; // Ustawiamy wartownika na końcu tablicy
    int i = 0;
    while (tab[i] != key) {
        ++i;
    }
    if (i < size) {
        return i; // Znaleziono klucz, zwracamy indeks
    }
    return -1; // Klucz nie został znaleziony
}

// Wyszukiwanie skokowe
int wyszukiwanieSkokowe(int *tab, int size, int key) {
    int step = sqrt(size);
    int prev = 0;

    while (tab[min(step, size) - 1] < key) {
        prev = step;
        step += sqrt(size);
        if (prev >= size) {
            return -1; // Klucz nie został znaleziony
        }
    }

    while (tab[prev] < key) {
        ++prev;
        if (prev == min(step, size)) {
            return -1; // Klucz nie został znaleziony
        }
    }

    if (tab[prev] == key) {
        return prev; // Znaleziono klucz, zwracamy indeks
    }

    return -1; // Klucz nie został znaleziony
}

// Wyszukiwanie binarne
int wyszukiwanieBinarne(int *tab, int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (tab[mid] == key) {
            return mid; // Znaleziono klucz, zwracamy indeks
        } else if (tab[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Klucz nie został znaleziony
}

// Wyszukiwanie interpolacyjne
int wyszukiwanieInterpolacyjne(int *tab, int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high && key >= tab[low] && key <= tab[high]) {
        if (low == high) {
            if (tab[low] == key) {
                return low; // Znaleziono klucz, zwracamy indeks
            }
            return -1; // Klucz nie został znaleziony
        }

        int pos = low + ((double)(high - low) / (tab[high] - tab[low])) * (key - tab[low]);

        if (tab[pos] == key) {
            return pos; // Znaleziono klucz, zwracamy indeks
        }

        if (tab[pos] < key) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1; // Klucz nie został znaleziony
}

int main() {
    int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(tab) / sizeof(tab[0]);

    int key = 5;

    cout << "Wyszukiwanie liniowe: " << wyszukiwanieLiniowe(tab, size, key) << endl;
    cout << "Wyszukiwanie liniowe z wartownikiem: " << wyszukiwanieLinioweWartownik(tab, size, key) << endl;
    cout << "Wyszukiwanie skokowe: " << wyszukiwanieSkokowe(tab, size, key) << endl;
    cout << "Wyszukiwanie binarne: " << wyszukiwanieBinarne(tab, size, key) << endl;
    cout << "Wyszukiwanie interpolacyjne: " << wyszukiwanieInterpolacyjne(tab, size, key) << endl;

    return 0;
}