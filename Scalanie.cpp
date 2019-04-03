#include <iostream>
#include <stdio.h>
#include<cstdlib>
#include "Scalanie.h"
#include "tab.h"
using namespace std;


void scalanie(unsigned long tab[],long left,long S, long right,unsigned long *pom)
{
    long i = left, j = S + 1;



    for(long i = left;i<=right; i++)
        pom[i] = tab[i];


    for(long w=left;w<=right;w++)
        if(i<=S)
            if(j <= right)
                if(pom[j]<pom[i])
                    tab[w] = pom[j++];
                else
                    tab[w] = pom[i++];
            else
                tab[w] = pom[i++];
        else
            tab[w] = pom[j++];


}

void SPS(unsigned long *tab, long left, long right, unsigned long  *pom)
{

    if(right<=left) return;


    long S = (right+left)/2;


    SPS(tab, left, S, pom);
    SPS(tab, S + 1, right, pom);


    scalanie(tab, left, S, right, pom);
}
