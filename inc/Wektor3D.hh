#ifndef Wektor3D_HH
#define Wektor3D_HH
#include <iostream>
#include<cassert>
#include"Wektor.hh"
/*! Klasa modelujaca pojecie Wektora3D
*/
class Wektor3D: public Wektor<double,3>{
  Wektor<double, 3>Wspolrzedne;
  static int _AktualnaIlosc;
  static int _LacznaIlosc;
  public:
  /*!Bezparametryczne wywolanie konstruktora, przypisanie zer wektorowi*/
  Wektor3D(){Wspolrzedne[0]=0; Wspolrzedne[1]=0; Wspolrzedne[2]=0;++_AktualnaIlosc;++_LacznaIlosc;};
  /*! Wywolanie Konstruktora z parametrami przypisujacymi wektorowi kolejno
   * wartosci x=A y=B z=C
  */
  ~Wektor3D(){--_AktualnaIlosc;}
  Wektor3D(double A, double B, double C){Wspolrzedne[0]=A; Wspolrzedne[1]=B; Wspolrzedne[2]=C;++_AktualnaIlosc;++_LacznaIlosc; }
  Wektor3D( const Wektor3D& wek ){++_AktualnaIlosc;++_LacznaIlosc; Wspolrzedne[0]=wek[0]; Wspolrzedne[1]=wek[1]; Wspolrzedne[2]=wek[2]; }
  double operator [] (unsigned int Idx) const {assert(Idx <3); return Wspolrzedne[Idx]; };
  double & operator [] (unsigned int Idx) {assert(Idx <3); return Wspolrzedne[Idx]; };
  /*! Przeciazenie operatora dodawania dwoch wektorow 3D*/
  Wektor3D operator + (Wektor3D Drugi)  
    { 
      Wektor3D pom;
      for (int j = 0; j < 3 ; j++)
      {
        pom[j]=  this->Wspolrzedne[j]+Drugi[j] ;
      }      
     return pom;
    }
    /*!
    * Przeciazenie operatora mnozenia dwoch wektorow
    * 
    */
    Wektor3D operator * (Wektor3D Drugi){
      Wektor<double,3> pomW;
      Wektor3D pom3D;
      pom3D[0]=this->Wspolrzedne[0]*Drugi[0];
      pom3D[1]=this->Wspolrzedne[1]*Drugi[1];
      pom3D[2]=this->Wspolrzedne[2]*Drugi[2];

      return pom3D;
    }
    static int WezAktualnaIlosc(){return _AktualnaIlosc;}
    static int WezLacznaIlosc(){return _LacznaIlosc;}
};
/*! przeciazenie operatora wczytywania w celu wczytania Wektora A*/
ostream & operator << (ostream & StrWyj, Wektor3D A);
/*! przeciazenie operatora wyjscia w celu wyslania Wektora A na wyjscie*/
istream &operator>>(istream &StrWe, Wektor3D &Zm);




#endif