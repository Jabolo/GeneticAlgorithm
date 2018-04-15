#include "algorytm.h"
#include "krzyzowanie.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void krzyzowanie(Osobnik*glowa, int wielkoscGeno){
    Osobnik *aktualny, *nastepny, *ogon;
    aktualny=glowa;
    nastepny=aktualny->nastepny;
    int ktory=0;
    cout<<"\nmoje wejsciowe\n";
    while(aktualny != NULL){ //  COUT!!!!!!!!!!!!!!!!!!!!!!!!!!
        ktory++;
        cout<<aktualny->gatunek;
        ogon=aktualny;
        aktualny=aktualny->nastepny;
    };
    aktualny=glowa;
        int nr=ogon->numerOsobnika;
    if (ktory%2==1){

        ogon->nastepny=new Osobnik;
        ogon=ogon->nastepny;
        ogon->gatunek="                    ";
        ogon->gatunek=aktualny->gatunek;
        ogon->numerOsobnika=nr;
        aktualny=nastepny->nastepny;
        nastepny=aktualny->nastepny;
        nr++;
        ktory--;
    }
    //tu ustalam miejsce podziału rozmnażam
    while(ktory>0){
    int x = rand()%(wielkoscGeno-1);

    ogon->nastepny=new Osobnik;
    ogon=ogon->nastepny;
    ogon->gatunek="                    ";
    for(int i = 0 ; i<x ; i++ )
        ogon->gatunek[i]=aktualny->gatunek[i];
    for(int i = x ; i <wielkoscGeno ; i++)
        ogon->gatunek[i]=nastepny->gatunek[i];
    nr++;
    ogon->numerOsobnika=nr;//mam dodatkowego
    ogon->nastepny=new Osobnik;
    ogon=ogon->nastepny;
    ogon->gatunek="                    ";
    for(int i = 0 ; i<x ; i++ )
        ogon->gatunek[i]=nastepny->gatunek[i];
    for(int i = x ; i <wielkoscGeno ; i++)
        ogon->gatunek[i]=aktualny->gatunek[i];
    nr++;
    ogon->numerOsobnika=nr;//mam dodatkowego kolejnego
    ogon->nastepny=NULL;
    aktualny=nastepny->nastepny;
    nastepny=aktualny->nastepny;
    ktory=ktory-2;
}
    cout<<"\n osobniki po crosie \n";
    aktualny=glowa;
    while(aktualny != NULL){

        cout<<aktualny->gatunek;
        aktualny=aktualny->nastepny;
    };
}
