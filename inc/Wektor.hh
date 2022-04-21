#ifndef WEKTOR_HH
#define WEKTOR_HH
#include<assert.h>
#include <math.h>

#include <iostream>

using namespace std;
/*!Modeluje klase Wektor oraz operacje na niej*/
template<typename STyp, int SWymiar>
class Wektor
{
  /*! Wektor wpelniony danymi Styp o  Wymiarze SWymiar*/
 STyp Wsp[SWymiar]; 
 
 public:
  
  
  /*!
  *  Funkcja zwraca poszczegolna dana z wektora poprzez przeciazenie []
  *
  *  Opis poszczegolnych parametrow wywolania funkcji,
  *  unsigned int Idx - Indeks danej wektora
  *
  *  Warunki wstepne:
  *   Indeks nie moze przekroczyc wymiarow wektora
  *
  *  Funkcja zwraca poszczegolna dana wektora
  */
   STyp operator [] (unsigned int Idx) const {assert(Idx <SWymiar); return Wsp[Idx]; }


    /*!
  *  Funkcja zwraca poszczegolna dana z wektora poprzez przeciazenie [] w celu jej modyfikacji
  *
  *  Opis poszczegolnych parametrow wywolania funkcji,
  *  unsigned int Idx - Indeks danej wektora
  *
  *  Warunki wstepne:
  *   Indeks nie moze przekroczyc wymiarow wektora
  *
  *  Funkcja zwraca referencje na poszczegolna dana wektora, w celu jej modyfikacji
  */
   STyp & operator [] (unsigned int Idx) {assert(Idx <SWymiar); return Wsp[Idx]; }
  
    /*!
  *  Bezparametryczna deklaracja wektora
  *  Wektor zostanie wypelniony zerami
  */
   Wektor(){for (int i = 0; i < SWymiar ; i++){ this->Wsp[i]=0;}}
   Wektor(double A, double B, double C){ Wsp[0]=A;Wsp[1]=B;Wsp[2]=C;}
   
   

   
    

  /*!
  * Przeciazanie operatora - w celu odejmowania dwoch wektorow
  *
  *  Opis poszczegolnych parametrow wywolania funkcji,
  *  Wektor< STyp, SWymiar> Drugi - dane drugiego wektora, ktory bedzie odejmowany od pierwszego
  *
  *
  *  Funkcja zwraca wektor ktory jest wynikiem odejmowania
  */
    Wektor<STyp, SWymiar>  operator - (Wektor<STyp, SWymiar> Drugi)  
    { 
      Wektor <STyp, SWymiar> pom;
      for (int j = 0; j < SWymiar ; j++)
      {
        pom.Wsp[j]=  this->Wsp[j]-Drugi.Wsp[j] ;
      }      
     return pom;
    }
  /*!
  * Przeciazanie operatora + w celu dodawania dwoch wektorow
  *
  *  Opis poszczegolnych parametrow wywolania funkcji,
  *  Wektor< STyp, SWymiar> Drugi - dane drugiego wektora, ktory bedzie dodawany od pierwszego
  *
  *
  *  Funkcja zwraca wektor ktory jest wynikiem dodawania
  */
    Wektor <STyp, SWymiar> operator + (Wektor<STyp, SWymiar> Drugi)  
    { 
      Wektor<STyp, SWymiar> pom;
      for (int j = 0; j < SWymiar ; j++)
      {
        pom.Wsp[j]=  this->Wsp[j]+Drugi.Wsp[j] ;
      }      
     return pom;
    }
     /*!
  * Przeciazanie operatora / w celu dzielenia dwoch wektorow
  *
  *  Opis poszczegolnych parametrow wywolania funkcji,
  *  Styp A - dane drugiego Stypu ktory bedzie dzielnikiem
  *
  *
  *  Funkcja zwraca wektor ktory jest wynikiem dzielenia
  */

   Wektor<STyp, SWymiar>  operator / (STyp A)   
   {
     Wektor<STyp, SWymiar> pom;
     for (int j = 0; j < SWymiar ; j++)
     {
       pom.Wsp[j]= this->Wsp[j]/A ;  
     }      
     return pom;
    }
    

   /*!
  * Przeciazanie operatora * w celu mnozenia dwoch wektorow
  *
  *  Opis poszczegolnych parametrow wywolania funkcji,
  *  Wektor < STyp, SWymiar> jest mnozony przez Styp A
  *
  *
  *  Funkcja zwraca Wektor<typename STyp, int SWymiar> ktory jest wynikiem mnozenia
  */
    Wektor<STyp, SWymiar>  operator * (STyp A)  
    { Wektor <STyp, SWymiar> pom;
      for (int j = 0; j < SWymiar ; j++)
      {
       pom.Wsp[j]= this->Wsp[j]*A ; 
      }      
      return pom;
    }   


};
 /*!
  *  Przeciazenie operatora << w celu wyświetlenia wektora na terminalu
  *
  *  Opis poszczegolnych parametrow wywolania funkcji, 
  *  istream &StrWyj - przekazanie strumienia wyjściowego
  *  Wektor<typename STyp, int SWymiar> A - przekazanie danych wektora ,
  */
template<typename STyp, int SWymiar>
ostream & operator << (ostream & StrWyj, Wektor <STyp, SWymiar> A){ 
  for (int i = 0; i < SWymiar ; i++) {    StrWyj <<A[i]<<' '; } 
  return StrWyj;
}

/*!
  *  Przeciazenie operatora wczytywania w celu wczytywania Wektora poprzez oprator >>
  *
  *  Opis poszczegolnych parametrow wywolania funkcji, 
  *  istream &StrWe - przekazanie strumienia wejściowego
  *  Wektor<typename STyp, int SWymiar> &Zm - przekazanie referencji do Zmienianego Wektora,
  * 
  *  Warunki końcowe:
  *  jeśli wczytywanie sie nie powiodla funkcja assert zawiadomi o tym
  */
template<typename STyp, int SWymiar>
istream &operator>>(istream &StrWe, Wektor <STyp, SWymiar> &Zm){

for (int i = 0; i <SWymiar; i++)
{
  StrWe>>Zm[i];
  if (StrWe.fail())
    {
      assert("Blad podczas wporwadzania danych" && !StrWe.fail());
      return StrWe;
    }
}

  return StrWe;
}



#endif
