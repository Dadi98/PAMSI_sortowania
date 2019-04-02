#include "introsort.h"
#include <iostream>
#include <stdio.h>
#include "QS.h"
#include "kopiec.h"

using namespace std;

unsigned long szukaj_mediany(unsigned long *tab, long rozmiar, long i) {
    long najwiekszy;
    long L = 2 * i, P = (2 * i) + 1;
    if (L <= rozmiar && tab[L] > tab[i])
        najwiekszy = L;
    else najwiekszy = i;
    if (P <= rozmiar && tab[P] > tab[najwiekszy])
        najwiekszy = P;
    if (najwiekszy != i) {
        swap(tab[i], tab[najwiekszy]);
    }
    return tab[najwiekszy];
}

void IS(unsigned long tab[], long left, long right) {
    long i = left;
    long j = right;
    unsigned long x = szukaj_mediany(tab, right - left, (right - left) / 2);
    do {
        while (tab[i] < x)
            i++;

        while (tab[j] > x)
            j--;

        if (i <= j) {
            swap(tab[i], tab[j]);

            i++;
            j--;
        }
    } while (i <= j);

    if (left < j) IS(tab, left, j);

    if (right > i) IS(tab, i, right);
}