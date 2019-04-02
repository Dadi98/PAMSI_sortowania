#include <iostream>
#include <stdio.h>
#include "QS.h"

using namespace std;

void QS(unsigned long tab[], long left, long right) {
    long i = left;
    long j = right;
    unsigned long x = tab[(left + right) / 2];
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

    if (left < j) QS(tab, left, j);

    if (right > i) QS(tab, i, right);
}