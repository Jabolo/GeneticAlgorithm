#include <iostream>
#include "interfejs.h"
#include "algorytm.h"
using namespace std;

//w interfejsie następuje TYLKO interakcja z użytkownikiem



void start ()
{
    int opcja=0;
    int ileOsobnikow=0;
    int wielkoscGenotypu=0;
    int xmin=0;
    int xmax=0;

    cout<<"Algorytm genetyczny\n\n";

    do
    {
        cout<<"Wybierz opcje\n\n";
        cout<<"1. Tworzenie nowej kolonii\n";
        cout<<"666. Koniec programu\n";

        cin>>opcja;

        if (opcja==1)
        {

            do{
                cout<<"podaj parzysta liczbe osobnikow tej koloni\n";
                cin>>ileOsobnikow;
            } while (ileOsobnikow%2==1);
                do{
                    cout<<endl<<"jak duzy ma byc genotyp osobnikow??? Podaj wartosc od 1 do 20\n";
                    cin>>wielkoscGenotypu;
                } while (wielkoscGenotypu>20 || wielkoscGenotypu<1);
                cout<<endl<<"podaj dziedzine funkcji dla ktorej bede wyszukiwal najbardziej optymalnych gatunkow.\nx(min)= ";
                cin>>xmin;
                do{
                    cout<<endl<<"podaj x(max) wieksze od x(min)\nx(max)=  ";
                    cin>>xmax;
                    cout<<'\n';
                } while (xmax < xmin);
                rozpocznijProjektX(ileOsobnikow, wielkoscGenotypu, xmin, xmax);
                cout<<"\nKoniec tej Koloni\n\n";
            }

            if (opcja==666)
            {
                break;
            }
        }while(1);

        system("cls");
        for(int i=0; i<100; i++)
            cout<<"Koniec programu!\t";
    }
