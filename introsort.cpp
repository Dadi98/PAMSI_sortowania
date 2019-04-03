#include "introsort.h"
#include <iostream>
#include <stdio.h>
#include "QS.h"
#include <cmath>
using namespace std;
int Partition (unsigned long tab[], long left, long right)
{
    int pivot = tab[right];
    int i = left;

    for (int j = left; j < right; ++j)
    {
        if (tab[j] <= pivot)
        {swap(tab[j],tab[i]);
            i++;
        }
    }

    tab[right] = tab[i];
    tab[i] = pivot;

    return i;
}

void QuicksortRekursywny(unsigned long tab[], long left, long right) {
    if (left < right)
    {
        int q = Partition(tab, left, right);
        QuicksortRekursywny(tab, left, q - 1);
        QuicksortRekursywny(tab, q + 1, right);
    }
}

void MaxKopiec(unsigned long tab[], long KopiecSize, long index) {
    long left = (index + 1) * 2 - 1;
    long right = (index + 1) * 2;
    long largest = 0;

    if (left < KopiecSize && tab[left] > tab[index])
        largest = left;
    else
        largest = index;

    if (right < KopiecSize && tab[right] > tab[largest])
        largest = right;

    if (largest != index)
    { swap(tab[index],tab[largest]);

        MaxKopiec(tab, KopiecSize, largest);
    }
}

void Kopcowanie(unsigned long tab[], long c) {
    int KopiecSize = c;

    for (int p = (KopiecSize - 1) / 2; p >= 0; --p)
        MaxKopiec(tab, KopiecSize, p);

    for (int i = c - 1; i > 0; --i)
    {swap(tab[i],tab[0]);

        --KopiecSize;
        MaxKopiec(tab, KopiecSize, 0);
    }
}

void Wstawianie(unsigned long tab[], long c) {
    for (long i = 1; i < c; ++i)
    {
        long j = i;

        while ((j > 0))
        {
            if (tab[j - 1] > tab[j])
            {
                tab[j - 1] ^= tab[j];
                tab[j] ^= tab[j - 1];
                tab[j - 1] ^= tab[j];

                --j;
            }
            else
            {
                break;
            }
        }
    }
}

void Introspektywne(unsigned long tab[], long c) {
    int PartitionSize = Partition (tab, 0, c - 1);

    if (PartitionSize < 16)
    {
        Wstawianie(tab, c);
    }
    else if (PartitionSize >(2 * log(c)))
    {
        Kopcowanie(tab, c);
    }
    else
    {
        QuicksortRekursywny(tab, 0, c - 1);
    }
}
