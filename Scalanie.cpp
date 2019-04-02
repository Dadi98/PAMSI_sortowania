#include <iostream>
#include <stdio.h>
#include<cstdlib>
#include "Scalanie.h"
#include "tab.h"
using namespace std;


void scalanie(unsigned long tab[],long L,long S, long P,unsigned long *pom)
{
    long i = L, j = S + 1;



    for(long i = L;i<=P; i++)
        pom[i] = tab[i];


    for(long w=L;w<=P;w++)
        if(i<=S)
            if(j <= P)
                if(pom[j]<pom[i])
                    tab[w] = pom[j++];
                else
                    tab[w] = pom[i++];
            else
                tab[w] = pom[i++];
        else
            tab[w] = pom[j++];


}

void SPS(unsigned long *tab, long L, long P, unsigned long  *pom)
{

    if(P<=L) return;


    long S = (P+L)/2;


    SPS(tab, L, S, pom);
    SPS(tab, S + 1, P, pom);


    scalanie(tab, L, S, P, pom);
}
