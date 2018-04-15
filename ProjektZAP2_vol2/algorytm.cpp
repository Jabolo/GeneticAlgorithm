#include "algorytm.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int ileOsobnikow=0;
int wielkoscGenotypu=0;
int xmin=0;
int xmax=0;
Osobnik *glowaKoloni;


void rozpocznijProjektX(int FileOsobnikow, int FwielkoscGenotypu, int Fxmin, int Fxmax)
{
//odbieram dane
ileOsobnikow=FileOsobnikow;
wielkoscGenotypu=FwielkoscGenotypu;
xmin=Fxmin;
xmax=Fxmax;
double dotychczasoweMinimum=0, chwiloweMinimum=0, ewolucja=0;
// od tego momentu zaczyna się zabawa

glowaKoloni=tworzenieKoloni(ileOsobnikow, wielkoscGenotypu);
zapisDoPliku(glowaKoloni);
selekcja(glowaKoloni, xmin, xmax, ileOsobnikow, wielkoscGenotypu);
krzyzowanie(glowaKoloni, wielkoscGenotypu);
zapisDoPliku(glowaKoloni);
dotychczasoweMinimum=sprawdzenie(glowaKoloni, wielkoscGenotypu, ileOsobnikow, xmin, xmax);
while(ewolucja<5){
    selekcja(glowaKoloni, xmin, xmax, ileOsobnikow, wielkoscGenotypu);
    krzyzowanie(glowaKoloni, wielkoscGenotypu);
    zapisDoPliku(glowaKoloni);
    chwiloweMinimum=sprawdzenie(glowaKoloni, wielkoscGenotypu, ileOsobnikow, xmin, xmax);
if(dotychczasoweMinimum>=chwiloweMinimum){
    ewolucja++;
    dotychczasoweMinimum=chwiloweMinimum;
}
else {
    ewolucja=0;
}
}

}
void zapisDoPliku(Osobnik *glowa){
    Osobnik *akt;
    akt = glowa;
    ofstream daneGenetyczne;
    daneGenetyczne.open("daneAlgorytmGenetyczny.txt", ios::app);
    while (akt != NULL)
    {
        daneGenetyczne <<akt->numerOsobnika<< '!'<<akt->gatunek<<'\n';
      akt = akt->nastepny;
    }
    daneGenetyczne.close();
}

double sprawdzenie(Osobnik *glowa, int wielkoscGeno, int ileOs, int xmin, int xmax){
    Osobnik *aktualny;
    aktualny=glowa;
    double minimum=1000000;
    double obecnaAgresja=0;
    for(int i=0; i<ileOs; i++){
        double suma1=0;
        int mnoznik=1;
    for(int i=wielkoscGeno-1 ; i >=0 ; i--){
        if(aktualny->gatunek[i]!=' '){
            suma1+=(aktualny->gatunek[i]-48)*mnoznik;
            mnoznik=mnoznik*2;
        }
    }
    suma1=xmin+((xmax-xmin)/(pow(2,wielkoscGeno)-1))*suma1;
    suma1=sin(suma1)*(suma1-1)*(suma1+2)/(2*suma1)*(suma1/3)+40;
    obecnaAgresja=suma1;
    if(obecnaAgresja<=minimum) {
        minimum=obecnaAgresja;
    }
    aktualny=aktualny->nastepny;
    }

    return minimum;
}

