#include "algorytm.h"
#include "tworzenieKoloni.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

string nadajGenotyp(int wielkoscGenotypu){
    string genotyp="                    ";
    for(int i=0; i < wielkoscGenotypu; i++){
        genotyp[i]=char(1-rand()%2+48);
    }
    return genotyp;
}

Osobnik *tworzenieKoloni(int ileOsobnikow, int wielkoscGenotypu){
    srand(time(NULL));
    Osobnik *glowa, *aktualny, *poprzedni;
    aktualny=NULL;
    poprzedni=NULL;
    glowa=NULL;
    int ktoryOsobnik=0;

    while(ktoryOsobnik <ileOsobnikow){
        poprzedni=aktualny;
        aktualny = new Osobnik;
        aktualny->numerOsobnika=ktoryOsobnik;
        ktoryOsobnik++;
        aktualny->gatunek="                    ";
        aktualny->gatunek=nadajGenotyp(wielkoscGenotypu);
        aktualny->nastepny=NULL;
        if ( poprzedni != NULL)
            poprzedni->nastepny=aktualny;
        else
            glowa=aktualny;
    };
    return glowa;
}


