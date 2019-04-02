#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include "tab.h"

using namespace std;


void wypelnij_tab(unsigned long *tab, unsigned long ilosc) {
    for (long i = 0; i < ilosc; i++) {
        tab[i] = rand() % ilosc;
    }
};

void przepisz_tab(unsigned long *tab, unsigned long *tab2, unsigned long ilosc) {
    for (long i = 0; i < ilosc; i++) {
        tab2[i] = tab[i];
    }
};

void wypelnij_tab_w_proc(unsigned long *tab, unsigned long ilosc, float proc) {

    auto punktPrzegiecia = (unsigned long) std::floor(ilosc * proc);

    unsigned long i, j;
    for (j = 0; j < punktPrzegiecia; j++) {
        tab[j] = j;
    }
    for (i = j; i < ilosc; i++) {
        tab[i] = rand() % ilosc;
    }
};

void tab_wyp_posort_od_tyl(unsigned long *tab, long ilosc) {
    long j = ilosc;
    for (long i = 0; i < ilosc; i++) {
        tab[i] = j;
        j = j - 1;
    }
};

void wypisz_tab(unsigned long *tab, long ilosc) {

    for (long i = 0; i < ilosc; i++) {
        cout << tab[i];

        if (i < ilosc - 1)
            cout << ", ";
    }
    cout << endl;
};