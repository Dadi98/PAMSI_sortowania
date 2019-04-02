#include <algorithm>
#include "kopiec.h"

void szukaj_wiekszego_i_zamien (unsigned long *tab, long rozmiar, long i)
{
    long najwiekszy;
    long L=2*i, P=(2*i)+1;
    if (L<=rozmiar && tab[L]>tab[i])
        najwiekszy=L;
    else najwiekszy=i;
    if (P<=rozmiar && tab[P]>tab[najwiekszy])
        najwiekszy=P;
    if (najwiekszy!=i)
    {
        std::swap(tab[najwiekszy], tab[i]);
        szukaj_wiekszego_i_zamien(tab,rozmiar,najwiekszy);
    }
}
void budKopiec(unsigned long *tab, long rozmiar)
{
    for (long i=rozmiar/2;i>0;i--)
        szukaj_wiekszego_i_zamien(tab,rozmiar, i);
}

void sortkopiec(unsigned long *tab, long rozmiar)
{
    unsigned long temp;
    budKopiec(tab, rozmiar);
    for (long i=rozmiar;i>1;i--)
    {
        temp=tab[i];
        tab[i]=tab[1];
        tab[1]=temp;
        rozmiar--;
        szukaj_wiekszego_i_zamien(tab,rozmiar,1);
    }
}
