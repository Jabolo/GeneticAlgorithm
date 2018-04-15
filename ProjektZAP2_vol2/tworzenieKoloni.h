#ifndef TWORZENIEKOLONI_H
#define TWORZENIEKOLONI_H
#include<iostream>
#include"algorytm.h"
using namespace std;


struct Osobnik{
    int numerOsobnika;
    string gatunek;
    Osobnik *nastepny;
};

Osobnik *tworzenieKoloni (int, int);
string nadajGenotyp(int);
#endif // TWORZENIEKOLONI_H
