#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include "QS.h"
#include "Scalanie.h"
#include "tab.h"
#include "kopiec.h"
//#include "introsort.h"

using namespace std;


int main() {

    unsigned long n = 10000000;
    float proc = 0.1;
    unsigned long *tab, *tab2, *pom;
    unsigned long czas1 = 0, czas2 = 0, czas3 = 0, czas4 = 0;
    unsigned long s;


    tab = new unsigned long[n];
    tab2 = new unsigned long[n];
    // tab3 = new int[n];
    pom = new unsigned long[n];
    DWORD start1 = GetTickCount();
    for (s = 0; s < 1; s++) {

        wypelnij_tab_w_proc(tab,n,proc);

//        wypelnij_tab(tab, n);

//         tab_wyp_posort_od_tyl(tab,n);

        przepisz_tab(tab, tab2, n);
        //przepisz_tab(tab,tab3,n);
        //wypisz_tab(tab,n);
        DWORD end1 = GetTickCount();
        czas1 = czas1 + (end1 - start1);


        DWORD start2 = GetTickCount();
        QS(tab, 0, n - 1);
        DWORD end2 = GetTickCount();
        czas2 = czas2 + (end2 - start2);
        //wypisz_tab(tab,n);
        przepisz_tab(tab2, tab, n);

        DWORD start3 = GetTickCount();
        SPS(tab2, 0, n-1, pom);
        DWORD end3 = GetTickCount();
        czas3 = czas3 + (end3 - start3);


        // wypisz_tab(tab2,n);

        DWORD start4 = GetTickCount();
//        IS(tab,0, n-1);
        sortkopiec(tab, n-1);
        DWORD end4 = GetTickCount();
        czas4 = czas4 + (end4 - start4);
        //wypisz_tab(tab3,n);
    }


    cout << endl << "CZas wypełniania tablic:" << czas1 << "ms" << endl;
    cout << endl << "Quicksort-czas:" << czas2 << "ms" << endl;
    cout << endl << "Sortowanie przez Scalanie-czas:" << czas3 << "ms" << endl;
    cout << endl << "Sortowanie przez kopcowanie:" << czas4 << "ms" << endl;
    cout << endl;
////////////////////////////////////////////////////////


    system("pause");
    return 0;


}