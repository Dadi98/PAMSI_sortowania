#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include "QS.h"
#include "Scalanie.h"
#include "tab.h"
#include "kopiec.h"
#include "introsort.h"

using namespace std;


int main() {

    unsigned long n = 10000;
    float proc[] = {0.5,0.75,0.95,0.99,0.997};
    unsigned long *tab, *tab2, *pom;
    unsigned long czas1 = 0, czas2 = 0, czas3 = 0, czas4 = 0;
    unsigned long s;

    int bla=0,t;
    tab = new unsigned long[n];
    tab2 = new unsigned long[n];
    pom = new unsigned long[n];
//for( t=0;t<5;t++) {
    for (s = 0; s < 100; s++) {
        DWORD start1 = GetTickCount();
        //--------------------------//

        wypelnij_tab(tab, n); bla =1;
        //wypelnij_tab_w_proc(tab, n, proc[t]);bla = 2; //jesli nie uzywasz zakomentuj petle
        //tab_wyp_posort_od_tyl(tab,n);      bla=3;

        przepisz_tab(tab, tab2, n);
        //wypisz_tab(tab,n);

        //-------------------------//
        DWORD end1 = GetTickCount();
        czas1 = czas1 + (end1 - start1);


        DWORD start2 = GetTickCount();
        QS(tab, 0, n - 1);
        DWORD end2 = GetTickCount();
        czas2 = czas2 + (end2 - start2);
        przepisz_tab(tab2, tab, n);

        DWORD start3 = GetTickCount();
        SPS(tab2, 0, n - 1, pom);
        DWORD end3 = GetTickCount();
        czas3 = czas3 + (end3 - start3);


        DWORD start4 = GetTickCount();
        SK(tab, n - 1);
        DWORD end4 = GetTickCount();
        czas4 = czas4 + (end4 - start4);

    }
    if(bla==2){cout << endl << "posortowane w  " <<proc[t]*100<<"%"<<endl;}
    cout << endl << "ilosc elementow: " << n <<endl;
    cout << endl << "Quicksort:" << czas2 << "ms" << endl;
    cout << endl << "Sortowanie przez Scalanie:" << czas3 << "ms" << endl;
    cout << endl << "Sortowanie przez kopcowanie:" << czas4 << "ms" << endl;
    cout << endl;
    czas1=0;czas2=0;czas3=0;czas4=0;
//}
    if(bla==1) {cout << endl << "losowe" <<endl;}

    if(bla==3){cout << endl << "od max do min" <<endl;}

////////////////////////////////////////////////////////


    system("pause");
    return 0;


}