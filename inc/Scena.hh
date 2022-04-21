#ifndef Scena_HH
#define Scena_HH
#include "MacierzObrotu.hh"
#include "lacze_do_gnuplota.hh"
#include<cassert>
#include "Bryla.hh"
#include"Zakresy.h"
#include <unistd.h>
#include "Generatory.hh"
#include "Wektor.hh"
#include <memory>



/*! Funkcja kopiujaca Plaszczyzne z pliku wzorcowego do Kopii
* \param[in] Wzor
* \param[in] Kopia
*/
 void KopjujPlikZPlaszczyzna(std::string Wzor, std::string Kopia);
 /*! Funkcja kopiujaca Pret z pliku wzorcowego do Kopii
 * \param[in] Wzor
* \param[in] Kopia
 */
 void KopjujPlikZPret(std::string Wzor, std::string Kopia);
 /*Funkcja kopiujaca Prostopadloscian z pliku wzorcowego do Kopii
 * \param[in] Wzor
* \param[in] Kopia
 */
 void KopjujPlikZProstopadloscian(std::string Wzor, std::string Kopia);



/*! Klasa pomocnicza do drona*/
class SmigloPom: public PowierzniaGeom{
 public:
  SmigloPom(): PowierzniaGeom(4,7,"bryly/graniastoslup.dat"){}
};
/*! Klasa modelujaca prawe smiglo do drona*/
class SmigloPrawe: public PowierzniaGeom{
 public:
  SmigloPrawe(): PowierzniaGeom(4,7,"bryly/SmigloPrawe.dat"){}
};
/*! Klasa modelujaca lewe smiglo do drona*/
class SmigloLewe: public PowierzniaGeom{
 public:
  SmigloLewe(): PowierzniaGeom(4,7,"bryly/SmigloLewe.dat"){}
};

/*! Klasa modelujaca pojecie drona
*/
class Dron{
Prostopadloscian Korpus;
SmigloPrawe Prawe;
SmigloLewe Lewe;
SmigloPom PomLewe;
SmigloPom PomPrawe;
Prostopadloscian Aproksymacja;

public:
/*! Bezparametryczne wywyolanie konstruktora do Drona */
Dron(){
   Aproksymacja= Prostopadloscian(4,5,"bryly/Aproksymacja.dat");
   Aproksymacja.ZmienNazwePliku_WspGlb("bryly/AproksymacjaGlob.dat");
   Prawe.ZmienNazwePliku_WspGlb("bryly/PraweGlob.dat");
   Lewe. ZmienNazwePliku_WspGlb("bryly/LeweGlob.dat");
   Korpus.ZmienNazwePliku_WspGlb("bryly/Korpus.dat");
   PomLewe.ZmienNazwePliku_WspGlb("bryly/SmigloLewe.dat");
   PomPrawe.ZmienNazwePliku_WspGlb("bryly/SmigloPrawe.dat");
   PomPrawe.ZmienPolozenie(Wektor3D(20,-50,0));
   PomLewe.ZmienPolozenie(Wektor3D(-20,-50,0));

}
/*! Konstruktor pozwalajacy zmienic pozycje drona oraz dodac ich wieksza ilosc
* \param[in] Numer drona
* \param[in] PozycjaPoczatkowa
* \param[in] Lacze
*/
Dron(char NumerDrona, Wektor3D PozycjaPoczatkowa,PzG::LaczeDoGNUPlota  Lacze);
/*! Metoda Zwraca Aproksymacje */
Prostopadloscian ZwrocAproksymacje () const {
  return Aproksymacja;
}
/*! Metoda zwraca wspolrzedne globalne*/
 std::vector<Lamana> ZwrocGlobalne(){return Korpus.ZwrocGlobalne();}
 void ObliczWspGlb(){
   Prawe.ObliczWspGlb();
   Lewe.ObliczWspGlb();
   Korpus.ObliczWspGlb();
   Aproksymacja.ObliczWspGlb();
 }
 /*! Obraca Drona o kat w stopniach wzgledem osi X
  * \param[in] Kat - wyrazony w stopniach 
 */
 void ObrocX(double Kat);
 /*! Obraca Drona o kat w stopniach wzgledem osi Z
 * \param[in] Kat - wyrazony w stopniach
 */
 void ObrocZ(double Kat);
 /*! Obraca Drona o kat w stopniach wzgledem osi Y
 * \param[in] Kat  - wyrazony w stopniach
 */
 void ObrocY(double Kat);
 /*! Zwraca wartosc kata Y o jaki jest obrucony dron wyrazonego w stopniach */
  double WartoscKataY(){
    return Korpus.WartoscKataY();
  }
  /*! Zwraca wartosc kata X  o jaki jest obrucony dron wyrazonego w stopniach */
    double WartoscKataX(){
    return Korpus.WartoscKataX();
  }
  /*! Zwraca wartosc kata Z o jaki jest obrucony dron wyrazonego w stopniach */
    double WartoscKataZ(){
    return Korpus.WartoscKataZ();
  }
  /*! Zmienia Polozenie
  * \param[in] Wektor3D - Wektora3D o jaki ma byc zmienione polozenie
  */
  void ZmienPolozenie(const Wektor3D &Pol);



};




/*!Klasa modelujaca pojęcie Sceny*/
class Scena {
   PzG::LaczeDoGNUPlota  Lacze;
   Dno DnoScean;
   Woda WodaScena;
   std::list<shared_ptr<PowierzniaGeom >> Lst;
   std::list<shared_ptr<Dron>> Drony;
   std::list<shared_ptr<Dron>>::iterator Pr;
  

   int iloscprzeszkod;
   public:
  
   /*!Konstruktor bezparametryczny inicializuje gnuplota, ustawia zakresy, dolacza dno, drona, przeszkody, powierzchnie wody*/
   Scena ();
    /*!Wyswietla obecne polozenie drona*/
   void chwilaobecna(){(**Pr).ObliczWspGlb();Lacze.Rysuj();usleep(10000);}
   /*!Metoda Sprawdza Czy dron wyplynal lub uderzyl w dno*/
   bool SprawdzCzyWyplynalUderzlWDno();
  
  /*! Sprawdz czy wystapila Kolizja miedzy dronem ktorym sterujemy a innymi przeszkodami*/
  bool SprawdzczyKol(){
    for (const shared_ptr<PowierzniaGeom >Wob : Lst){
      if (((**Pr).ZwrocAproksymacje().XMIN() < Wob->XMAX() && Wob->XMIN() < (**Pr).ZwrocAproksymacje().XMAX())&&((**Pr).ZwrocAproksymacje().YMIN() < Wob->YMAX() && Wob->YMIN() < (**Pr).ZwrocAproksymacje().YMAX())&&((**Pr).ZwrocAproksymacje().ZMIN() < Wob->ZMAX() && Wob->ZMIN() < (**Pr).ZwrocAproksymacje().ZMAX()))
      {
        cout<<"Kolizja z obiektem typu: "<< Wob->NazwaTypu() <<endl;
        return true ;
      }
    }
   return false ;
  }

  /*! Metoda umozliwai poruszanie sie innymi dronami,
  * \param[in] numerdrona - wybor drona ktorym chcemy sterowac
  */
  void ZmienSterowanie(unsigned int numerdrona){   
   
   if(numerdrona<Drony.size()){
      Pr=Drony.begin();
      for (unsigned int pom = 0; pom < numerdrona; pom++)
      {
         ++Pr;
      }
    }
   else{
      cout<<"Nie poprawny indeks drona"<<endl;
    }
  }
  /*! Sprawdza czy wystapila kolizja miedzy dronem ktory byl sterowany a innymi dronami*/
  bool SprawdzczyKolmiedzyDronami(){
    for (const shared_ptr<Dron >Wob : Drony){
      if (Wob!=*Pr)
      {
        if (((**Pr).ZwrocAproksymacje().XMIN() < Wob->ZwrocAproksymacje().XMAX() && Wob->ZwrocAproksymacje().XMIN() < (**Pr).ZwrocAproksymacje().XMAX())&&((**Pr).ZwrocAproksymacje().YMIN() < Wob->ZwrocAproksymacje().YMAX() && Wob->ZwrocAproksymacje().YMIN() < (**Pr).ZwrocAproksymacje().YMAX())&&((**Pr).ZwrocAproksymacje().ZMIN() < Wob->ZwrocAproksymacje().ZMAX() && Wob->ZwrocAproksymacje().ZMIN() < (**Pr).ZwrocAproksymacje().ZMAX()))
        {
          cout<<"Kolizja z Dronem" <<endl;
          return true ;
        }
      }
    }
    return false ;
  }

  /*! Dodaje pret do listy przeszkod
  \param[in] dlugosc
  \param[in] srodekx
  \param[in] srodeky
  \param[in] srodekz
  */
  void DodajPret (double dlugosc, double srodekx, double srodeky, double srodekz );
  /*! 
  Metoda dodaje Powierchnie 
   \param[in] szerokosc
   \param[in] wysokosc
  \param[in] srodekx
  \param[in] srodeky
  \param[in] srodekz
  */
  void DodajPowierzchnia (double szerokosc, double wysokosc, double srodekx, double srodeky, double srodekz ); 
  /*! Metoda usuwa wszystkie przeszkody z listy przeszkod*/
  void UsunPrzeszkody(){
    const int pomiloscalkowita=Lst.size();

    std::list<shared_ptr<PowierzniaGeom >>::iterator i=Lst.begin();
    for (int d = 0; d < pomiloscalkowita; d++) { 
      remove((**i).ZwrocNazweLok());
       ++i;
     }
    
      
       
       
  
   }
    
    /*! Dodaje do listy przeszkod prostopadloscian
     \param[in] dlugosc
     \param[in] szerokosc
     \param[in] wysokosc
  \param[in] srodekx
  \param[in] srodeky
  \param[in] srodekz
  */
  void DodajProstopadloscian (double szerokosc, double wysokosc, double dlugosc, double srodekx, double srodeky, double srodekz );

     /*! Metoda sluzy do wyswietlania przeszkod oraz ich srodkow*/
  void wyswietlprzeszkody(){
    char pom = 'a';
    for (const shared_ptr<PowierzniaGeom >Wob : Lst){
      cout<<pom<<". ";
      cout.setf(ios::left);
      cout.width(17);
      cout<<Wob->NazwaTypu();
      cout<<" Wspolrzedne srodka: "; Wob->Srodek(); cout<<endl;
      ++pom;
     }
  }
 
  /*! Metoda umozliwia wyswietlenie dronow na liscie*/ 
  void wyswietldrony(){
    char pom = 'a';
    for (const shared_ptr<Dron> Wob : Drony){ 
       cout<<pom<<". "<<"Dron"<<"                 Wspolrzedne srodka: "; Wob->ZwrocAproksymacje().Srodek(); cout<<endl;
       ++pom;
     }
     }

     


/*! Metoda sluzy do usuwania obiektu z listy
 \param[in] pozycja
*/
  void UsunPrzeszkode (unsigned int pozycja){
    int flaga=0;
    std::list<shared_ptr<PowierzniaGeom >>::iterator i=Lst.begin();
      if (pozycja >= 0&& pozycja<Lst.size()) {  
          for (unsigned int a = 0; a < pozycja; a++){  ++i; }
          ofstream wyj ((**i).ZwrocNazweLok());
          Lst.erase(i);
          
          wyj <<' ';
          flaga =1;
         }
    if (flaga==0){cout<<"Nie ma takiej pozycji"<<endl<<endl;}
  }
  /*!! Metoda sluzaca do poruszania dronem, przyjmuje odleglosc na jaka ma sie przeniesc dron oraz kat w stopniach o jaki ma sie obrocic 
   \param[in] kat - kat wyrazony w stopniach
  \param[in] odleglosc
  */
  bool Pojedzdoprzodudronem(double odleglosc, double kat);

  /*! Metoda sluzaca do rotacji drona o kat w stopniach
   \param[in] kat - wyrazony w stopniach
  */
  bool RotujDrona (double kat);
};



#endif
