#include "algorytm.h"
#include "selekcjaOsobnikow.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;



void selekcja(Osobnik*&glowa, int xmin, int xmax, int ileOs, int wielkoscGeno){
    Osobnik *aktualny, *nastepny, *poprzedni;
    aktualny=glowa;
    poprzedni=glowa;
    nastepny=aktualny->nastepny;
    for(int i=0; i<ileOs; i+=2){
        double suma1=0, suma2=0;
        int mnoznik=1;
        for(int i=wielkoscGeno-1 ; i >=0 ; i--){
            if(aktualny->gatunek[i]!=' '){
                suma1+=(aktualny->gatunek[i]-48)*mnoznik;
                suma2+=(nastepny->gatunek[i]-48)*mnoznik;
                mnoznik=mnoznik*2;
            }
        }
        suma1=xmin+((xmax-xmin)/(pow(2,wielkoscGeno)-1))*suma1;
        suma2=xmin+((xmax-xmin)/(pow(2,wielkoscGeno)-1))*suma2;
        suma1=przeliczNaPoziomAgresji(suma1);
        suma2=przeliczNaPoziomAgresji(suma2);
        cout<<aktualny->gatunek<<nastepny->gatunek; // COUT !!!!!!!!!!!!!!!!!!!!!!!!!!
        if(suma2>suma1){

            Osobnik *tmp;
            tmp=nastepny;
            if(tmp->nastepny!= NULL){
                aktualny->nastepny=tmp->nastepny;
poprzedni=aktualny;
                aktualny=tmp->nastepny;
                nastepny=aktualny->nastepny;
            }
             delete tmp;

        }
        else{
            Osobnik *tmp;
            tmp=glowa;

            if(aktualny==glowa){
                glowa=glowa->nastepny;
                poprzedni=glowa;
                aktualny=glowa->nastepny;

                nastepny=aktualny->nastepny;
                delete tmp;


            }
            else{
                tmp=aktualny;
                poprzedni->nastepny=aktualny->nastepny;
                aktualny=aktualny->nastepny;
                delete tmp;

                if(aktualny->nastepny!= NULL){
                    poprzedni=aktualny;
                    aktualny=aktualny->nastepny;
                    nastepny=aktualny->nastepny;
                }
            }
        }
    }

}

double przeliczNaPoziomAgresji(double suma){
    // TUTAJ RÓWNANIE WYLICZAJACE Y
    return sin(suma)*(suma-1)*(suma+2)/(2*suma)*(suma/3)+40;
}
