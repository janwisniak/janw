#include <iostream>
 
using namespace std;
 
// Sortowanie bąbelkowe
void sortowanieBabelkowe(int tab[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (tab[j] > tab[j + 1]) {
                // Zamiana miejscami
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}
 
// Sortowanie przez wstrząsanie (koktajlowe)
void sortowanieWstrzasanie(int tab[], int n) {
    bool zamieniono = true;
    int start = 0;
    int koniec = n - 1;
 
    while (zamieniono) {
        zamieniono = false;
        for (int i = start; i < koniec; ++i) {
            if (tab[i] > tab[i + 1]) {
                // Zamiana miejscami
                int temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
                zamieniono = true;
            }
        }
        if (!zamieniono) break;
 
        zamieniono = false;
        --koniec;
        for (int i = koniec - 1; i >= start; --i) {
            if (tab[i] > tab[i + 1]) {
                // Zamiana miejscami
                int temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
                zamieniono = true;
            }
        }
        ++start;
    }
}
 
// Funkcja pomocnicza do scalania dwóch posortowanych tablic
void scalanie(int tab[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Tworzenie pomocniczych tablic
    int L[n1], P[n2];
    for (int i = 0; i < n1; i++)
        L[i] = tab[l + i];
    for (int j = 0; j < n2; j++)
        P[j] = tab[m + 1 + j];
 
    // Scalanie tablic pomocniczych w jedną posortowaną
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= P[j]) {
            tab[k] = L[i];
            i++;
        } else {
            tab[k] = P[j];
            j++;
        }
        k++;
    }
 
    // Dopisanie pozostałych elementów z tablicy L
    while (i < n1) {
        tab[k] = L[i];
        i++;
        k++;
    }
 
    // Dopisanie pozostałych elementów z tablicy P
    while (j < n2) {
        tab[k] = P[j];
        j++;
        k++;
    }
}
 
// Sortowanie przez scalanie
void sortowanieScalanie(int tab[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    sortowanieScalanie(tab, l, m);
    sortowanieScalanie(tab, m + 1, r);
    scalanie(tab, l, m, r);
}
 
// Funkcja pomocnicza do szybkiego sortowania
int podzial(int tab[], int niski, int wysoki) {
    int os = tab[wysoki];
    int i = niski - 1;
    for (int j = niski; j <= wysoki - 1; j++) {
        if (tab[j] < os) {
            i++;
            // Zamiana miejscami
            int temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
        }
    }
    // Zamiana miejscami
    int temp = tab[i + 1];
    tab[i + 1] = tab[wysoki];
    tab[wysoki] = temp;
    return (i + 1);
}
 
// Szybkie sortowanie
void sortowanieSzybkie(int tab[], int niski, int wysoki) {
    if (niski < wysoki) {
        int pi = podzial(tab, niski, wysoki);
        sortowanieSzybkie(tab, niski, pi - 1);
        sortowanieSzybkie(tab, pi + 1, wysoki);
    }
}
 
// Sortowanie przez wstawianie
void sortowanieWstawianie(int tab[], int n) {
    for (int i = 1; i < n; ++i) {
        int klucz = tab[i];
        int j = i - 1;
        while (j >= 0 && tab[j] > klucz) {
            tab[j + 1] = tab[j];
            --j;
        }
        tab[j + 1] = klucz;
    }
}
 
int main() {
    {
        int tab_babelkowe[] = {8, 12, 9, 10, 1, 7, 6, 11, 3, 5, 4, 2};
        int n_babelkowe = sizeof(tab_babelkowe) / sizeof(tab_babelkowe[0]);
        sortowanieBabelkowe(tab_babelkowe, n_babelkowe);
        cout << "Sortowanie bąbelkowe: ";
        for (int i = 0; i < n_babelkowe; ++i)
            cout << tab_babelkowe[i] << " ";
        cout << endl;
    }
    {
        int tab_wstrzasanie[] = {64, 91, 83, 18, 54, 1, 90, 7, 22, 60, 33, 45};
        int n_wstrzasanie = sizeof(tab_wstrzasanie) / sizeof(tab_wstrzasanie[0]);
        sortowanieWstrzasanie(tab_wstrzasanie, n_wstrzasanie);
        cout << "Sortowanie przez wstrząsanie: ";
        for (int i = 0; i < n_wstrzasanie; ++i)
            cout << tab_wstrzasanie[i] << " ";
        cout << endl;
    }
    {
        int tab_scalanie[] = {15,23,67,64,83,78,44,21,25,80,56,17};
        int n_scalanie = sizeof(tab_scalanie) / sizeof(tab_scalanie[0]);
        sortowanieScalanie(tab_scalanie, 0, n_scalanie - 1);
        cout << "Sortowanie przez scalanie: ";
        for (int i = 0; i < n_scalanie; ++i)
            cout << tab_scalanie[i] << " ";
        cout << endl;
    }
    {
        int tab_szybkie[] = {65,76,22,53,90,46,87,21,11,26,23,77};
        int n_szybkie = sizeof(tab_szybkie) / sizeof(tab_szybkie[0]);
        sortowanieSzybkie(tab_szybkie, 0, n_szybkie - 1);
        cout << "Szybkie sortowanie: ";
        for (int i = 0; i < n_szybkie; ++i)
            cout << tab_szybkie[i] << " ";
        cout << endl;
    }
    {
        int tab_wstawianie[] = {12,64,62,82,72,51,76,31,16,97,45,1};
        int n_wstawianie = sizeof(tab_wstawianie) / sizeof(tab_wstawianie[0]);
        sortowanieWstawianie(tab_wstawianie, n_wstawianie);
        cout << "Sortowanie przez wstawianie: ";
        for (int i = 0; i < n_wstawianie; ++i)
            cout << tab_wstawianie[i] << " ";
        cout << endl;
    }
    return 0;
}