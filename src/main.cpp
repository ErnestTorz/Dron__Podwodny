#include <iostream>
#include <iomanip>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include<string>
#include<cassert>
#include <unistd.h>
#include "Wektor.hh"
#include"math.h"
#include "MacierzObrotu.hh"
#include "Wektor3D.hh"
#include "Bryla.hh"
#include "Zakresy.h"
#include "Scena.hh"
using namespace std;


void WyswietlMenu(){

  cout<<endl;
  cout<<"MENU: "<<endl;
  cout<<"z - zmien sterowanie dronem"<<endl;
  cout<<"r - zadaj ruch na wpros"<<endl;
  cout<<"o - zadaj zmiane orientacji"<<endl;
  cout<<"d - dodaj przeszkode"<<endl;
  cout<<"u - usun obiekt"<<endl;
  cout<<"m - wyswietl menu"<<endl<<endl;
  cout<<"k - koniec dziaLania programu"<<endl;
}


int main()
{
{ char indeksdrona='Y';
  char wczyt ='c';
  double szerokosc =0;
  double wysokosc =0;
  double dlugosc =0;
  double tranx=0;
  double trany=0;
  double tranz=0;
  char pozycja= 'Y';
  char c='v';
  double k =0 ,d =0;
  Scena Scena;
  
  WyswietlMenu();
  cout<<endl<<"Aktualna ilosc obiektow Wektor3D: "<<Wektor3D::WezAktualnaIlosc();
  cout<<endl<<"Laczna ilosc obiektow Wektor3D:   "<<Wektor3D::WezLacznaIlosc()<<endl;
  while (c!='k')
  {
    
    cout<<endl<<"Twój wybor, m - menu : ";
    cin>>c;
  
    switch (c)
   {
       case 'r':
         cout<<endl<<"Podaj wartosc kata (wznoszenia/opadania) w stopniach."<<endl;
         cout<<"Wartosc kata: ";
         cin>>k;
         assert(!cin.fail());
         cout<<endl;
         cout<<"Podaj wartosc odleglosci, na ktora ma sie przemiescic dron."<<endl;
         cout<<"Wartosc odleglosci: ";
         cin>>d;
         assert(!cin.fail());
         Scena.Pojedzdoprzodudronem(d,k);
         cout<<endl<<"Aktualna ilosc obiektow Wektor3D: "<<Wektor3D::WezAktualnaIlosc();
         cout<<endl<<"Laczna ilosc obiektow Wektor3D:   "<<Wektor3D::WezLacznaIlosc()<<endl;
       break;
      
       case 'z':
         Scena.wyswietldrony();
         cout<<endl<<"Podaj indeks drona ktorym chcesz sterowac: ";
         cin>>indeksdrona;
         assert(!cin.fail());
         Scena.ZmienSterowanie(indeksdrona-'a');
         cout<<endl<<"Aktualna ilosc obiektow Wektor3D: "<<Wektor3D::WezAktualnaIlosc();
         cout<<endl<<"Laczna ilosc obiektow Wektor3D:   "<<Wektor3D::WezLacznaIlosc()<<endl;
      break;

      case 'u':
         Scena.wyswietlprzeszkody();
          cout<<endl<<"Podaj indeks przeszkody: ";
          cin>>pozycja;
          assert(!cin.fail());
          Scena.UsunPrzeszkode(pozycja-'a');
          Scena.chwilaobecna();
          cout<<endl<<"Aktualna ilosc obiektow Wektor3D: "<<Wektor3D::WezAktualnaIlosc();
          cout<<endl<<"Laczna ilosc obiektow Wektor3D:   "<<Wektor3D::WezLacznaIlosc()<<endl;
      break;

      case 'd':
         cout<<endl<<"Wybierz przeszkode z listy: "<<endl<<endl;
         cout<< "a - Prostopadloscian"<<endl <<"b - Prosta"<<endl <<"c - Powierzchnia"<< endl<<endl<< "Twoj wybor: ";
         cin >>wczyt;
         switch (wczyt)
         {
           case 'a':
             cout << "Podaj szerokosc, wysokosc, dlugosc: ";
             cin >>szerokosc;
             assert(!cin.fail());
             cin >>wysokosc;
             assert(!cin.fail());
             cin >>dlugosc;
             assert(!cin.fail());
             cout<<"Podaj miejsce polozenia srodka, wspolrzedne x,y,z : ";
             cin >>tranx;
             assert(!cin.fail());
             cin >>trany;
             assert(!cin.fail());
             cin >>tranz;
             assert(!cin.fail());
             cout<<endl;
             Scena.DodajProstopadloscian(szerokosc,wysokosc,dlugosc,tranx,trany,tranz);
             Scena.chwilaobecna();
           break;

           case 'b':
             cout << "Podaj szerokosc: ";
             cin >>szerokosc;
             assert(!cin.fail());
             cout<<"Podaj miejsce polozenia srodka, wspolrzedne x,y,z : ";
             cin >>tranx;
             assert(!cin.fail());
             cin >>trany;
             assert(!cin.fail());
             cin >>tranz;
             assert(!cin.fail());
             cout<<endl;
             Scena.DodajPret(szerokosc,tranx,trany,tranz);
             Scena.chwilaobecna();
           break;

           case 'c':
             cout << "Podaj szerokosc, wysokosc: ";
             cin >>szerokosc;
             assert(!cin.fail());
             cin >>wysokosc;
             assert(!cin.fail());
             cout<<"Podaj miejsce polozenia srodka, wspolrzedne x,y,z : ";
             cin >>tranx;
             assert(!cin.fail());
             cin >>trany;
             assert(!cin.fail());
             cin >>tranz;
             assert(!cin.fail());
             cout<<endl;
             Scena.DodajPowierzchnia(szerokosc,wysokosc,tranx,trany,tranz);
             Scena.chwilaobecna();
            break;
       
            default:
             cout<<endl<<"Niepoprawna opcja"<<endl<<endl;
            break;
          }
         cout<<endl<<"Aktualna ilosc obiektow Wektor3D: "<<Wektor3D::WezAktualnaIlosc();
         cout<<endl<<"Laczna ilosc obiektow Wektor3D:   "<<Wektor3D::WezLacznaIlosc()<<endl;
       break;
  
      case 'k':
         
      break;
  
      case 'm':
         WyswietlMenu();
         cout<<endl<<"Aktualna ilosc obiektow Wektor3D: "<<Wektor3D::WezAktualnaIlosc();
         cout<<endl<<"Laczna ilosc obiektow Wektor3D:   "<<Wektor3D::WezLacznaIlosc()<<endl;
      break;
  
      case 'o':
         cout<<endl<<"Podaj wartosc kata obrotu w stopniach"<<endl;
         cout<<"Wartosc kata: ";
         cin>>k;
         assert(!cin.fail());
         Scena.RotujDrona(k);
         cout<<endl<<"Aktualna ilosc obiektow Wektor3D: "<<Wektor3D::WezAktualnaIlosc();
         cout<<endl<<"Laczna ilosc obiektow Wektor3D:   "<<Wektor3D::WezLacznaIlosc()<<endl;
      break;

      default:
         cout<<endl<<"Bledna opcja"<<endl;
         cout<<endl<<"Aktualna ilosc obiektow Wektor3D: "<<Wektor3D::WezAktualnaIlosc();
         cout<<endl<<"Laczna ilosc obiektow Wektor3D:   "<<Wektor3D::WezLacznaIlosc()<<endl;
      break;
     
    }
    
  }

  Scena.UsunPrzeszkody();
}
    cout<<endl<<"Koniec programu"<<endl; 
  cout<<endl<<"Aktualna ilosc obiektow Wektor3D: "<<Wektor3D::WezAktualnaIlosc();
    cout<<endl<<"Laczna ilosc obiektow Wektor3D:   "<<Wektor3D::WezLacznaIlosc()<<endl;
     
}
