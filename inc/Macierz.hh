#ifndef MACIERZ_HH
#define MACIERZ_HH


#include <iostream>
#include<assert.h>
#include<math.h>
#include "Wektor.hh"


using namespace std;
/* !Modeluje klasę Macierz oraz operacje na niej*/
template<typename STyp, int SWymiar>
class Macierz{
 
 
 Wektor<STyp, SWymiar> Kol[SWymiar];
    
    
 
 /*!
  *  Słuzy do sprowadzanie mecierzy do macierzy trojkatnej,
  *  podczac działania zostaje wywołana metoda WyzerujwierszOdKol(i,Parzystosc);  
  * 
  *
  *  Opis poszczegolnych parametrow wywolania funkcji,
  *   int &Parzystosc  - referencja do Parzystości potrzebna do obliczenia prawidłowego wyniku koncowego
  */
 void SprowadzDoMacTroj(double &parzystosc){
    for (int i = 0; i < SWymiar; ++i)
    {
      WyzerujwierszOdKol(i,parzystosc);
    }
  }



/*!
  *  Słuzy do wymnozenia wartości na diagonali 
  *  podczas dzialania zostaje wywołana funkcja SprowadzDoMacTroj(Parzystosc); 
  *
  *  Opis poszczegolnych parametrow wywolania funkcji,
  *   int &Parzystosc  - referencja do Parzystości potrzebna do obliczenia prawidłowego wyniku koncowego
  * 
  * zwraca wynik mnozenia diagonali
  */
 STyp WymnozNaDiagonali(double &parzystosc) {
    SprowadzDoMacTroj(parzystosc);
    STyp Wynik = this->Kol[0][0];
    for (int i = 1; i < SWymiar; ++i)
    {
      Wynik= Wynik * this->Kol[i][i];
    }
    return Wynik;
  }


/*!
  *  Zeruje podany wiersz macierzy, oraz jeśli wystapi konieczność zamiany miejcami dwoch danych modyfikuje przystość
  *  podczas dzialania zostaje wywołana funkcja ZamienKolumny(Idx, kolumna)
  * 
  *  Opis poszczegolnych parametrow wywolania funkcji,
  *   uigned int Idx - indeks zerownego wiersza
  *   int &Parzystosc  - referencja do Parzystości potrzebna do obliczenia prawidłowego wyniku koncowego
  *  
  *
  *  Warunki koncowe:
  *   Jeśli program nie będzie wstanie wyzerować wiersza tzn. 
  *   podczas szukania nie zerowej danej wyjdzie poza rozmiar wiersza zasygnalizuje to poprzez funkcje assert
  * 
  */
  
 void WyzerujwierszOdKol(unsigned int Idx, double &parzystosc){
    unsigned int kolumna= Idx;
    
    while (kolumna < SWymiar && this->Kol[kolumna][Idx]==0)
    {
      kolumna++;
    }

    assert("Brak rozwiazania" && kolumna<SWymiar);
    
    if (!(this->Kol[kolumna][Idx]==0))
    {
      if (kolumna!=Idx)
      {
        ZamienKolumny(Idx, kolumna);
        parzystosc=parzystosc* -1; 
      }

  
      for (int i = Idx + 1; i < SWymiar; i++)
      {
        assert(!(this->Kol[Idx][Idx]==0));
        this->Kol[i]= this->Kol[i]-(this->Kol[Idx]/this->Kol[Idx][Idx])*this->Kol[i][Idx]; //Wzor z algorytmu na wyzerowanie danego elementu w wierszu
      }
    }
  }
  

   /*!
  *  Zamienia dwie wskazanie komurki w macierzy
  *
  *  Opis poszczegolnych parametrow wywolania funkcji,
  *   unsigned int Kol1 - pierwsza kolumna, ktora ma zostać zamieniona  
  *   unsigned int Kol2 - druga kolumna, ktora ma zostać zamieniona 
  *
  */

 void ZamienKolumny (unsigned int Kol1, unsigned int Kol2){
    Wektor<STyp, SWymiar> Kol_tmp = this->Kol[Kol1] ;
    this->Kol[Kol1]=this->Kol[Kol2];
    this->Kol[Kol2]=Kol_tmp;
   }

 public:

   /*!
  *  Metoda zwraca poszczegolna kolumnę z macierzy, ktora jest wektorem poprzez przeciazenie []
  *
  *  Opis poszczegolnych parametrow wywolania funkcji,
  *  unsigned int Kolum - Koluman macierzy 
  *
  *  Warunki wstepne:
  *   Koluma nie moze przekroczyć wymiarow macierzy
  *
  *  Funkcja zwraca poszczegołna kolumnę maciezy w postaci wektora
  */
  Wektor <STyp, SWymiar> operator [] (int Kolum)const{ return Kol [Kolum];}
  
   /*!
  *  Metoda zwraca refernecje na poszczegolna kolumnę z macierzy, ktora jest wektorem poprzez przeciazenie []
  *
  *  Opis poszczegolnych parametrow wywolania funkcji,
  *  unsigned int Kolum - Koluman macierzy 
  *
  *  Warunki wstepne:
  *   Koluma nie moze przekroczyć wymiarow macierzy
  *
  *  Funkcja zwraca referencje na poszczegołna kolumnę maciezy w postaci wektora, w celu jej modyfikacji
  */

  Wektor <STyp, SWymiar> & operator [] (int Kolum){return Kol [Kolum];}
   
   /*!
  * Przeciazanie operatora * w celu mnozenia macierzy przez wektor
  *
  *  Opis poszczegolnych parametrow wywolania funkcji,
  *  Wektor < STyp, SWymiar>Wek - dane wetkora, przez ktory będziemy mnozyć
  *
  *
  *  Funkcja zwraca wektor ktory jest wynikiem dzielenia
  */

  Wektor <STyp, SWymiar> operator * (Wektor<STyp, SWymiar> Wek)  
    { STyp pom;
    pom = 0.0;
      int idx=0;
      Wektor<STyp, SWymiar> wynik;
      for (int j = 0; j < SWymiar; j++)
      {   
         for (int i = 0; i < SWymiar; i++)
         {
          pom=pom+(Kol[i][j]*Wek[i]);
         }
         wynik[idx]=pom;
         idx++;
         pom=0.0;
      }
      return wynik;
    }   


 void WyswietlMac (){
     for (int y = 0; y < SWymiar; y++)
     { 
        for (int x  = 0; x < SWymiar; x++)
        {
          cout<<this->Kol[y][x]<<' ';
        }
       cout<<endl;
      }
    }

 /*!
  *  Metoda słuzy do obliczani wyznacznika.
  *  podczas dzialania zostaje wywołana metoda WymnozNaDiagonali(Parzystosc)
  *
  * 
  * zwraca wartość wyznacznika
  */

 STyp ObliczWyznacznik() {
  double parzystosc = 1;
  STyp wyznacznik = WymnozNaDiagonali(parzystosc) ;
  wyznacznik = wyznacznik* parzystosc;
  return wyznacznik;
 }

 
 Macierz ( ){ //!Uzupełnia macierz zerami przy wywołaniu bez zadnych argumentow
   for (int i = 0; i < SWymiar; i++)
   {
     for (int y = 0; y < SWymiar; y++)
   {
     Kol[i][y]=0;
   }
   }
   

 }
 //!Deklaracja Macierzy, przez bezpośrednie podanie wektorow jako prametry
 Macierz (Wektor<STyp, SWymiar> A,Wektor<STyp, SWymiar> B, Wektor<STyp, SWymiar> C){ //opcja wczytania bezpośrednio wektorow bez potrzeby korzystana z cin>>Macierz
   Kol[0]=A;
   Kol[1]=B;
   Kol[2]=C;
  }

};

/*!
  *  Przeciazenie operatora << w celu wyświetlenia macierzy na terminalu
  *
  *  Opis poszczegolnych parametrow wywolania funkcji, 
  *  istream &StrWyj - przekazanie strumienia wyjściowego
  *  Macierz< STyp, SWymiar> A - przekazanie danych Macierzy ,
  */

template<typename STyp, int SWymiar>
ostream & operator << (ostream & StrWyj, Macierz<STyp, SWymiar> A){ 
  A.WyswietlMac();
  return StrWyj;
}

 /*!
  *  Przeciazenie operatora wczytywania w celu wczytywania Macierzy poprzez oprator >>
  *
  *  Opis poszczegolnych parametrow wywolania funkcji, 
  *  istream &StrWe - przekazanie strumienia wejściowego
  *  Macierz< STyp, SWymiar> &Mac - przekazanie referencji do Zmienianej Macierzy,
  * 
  *  Warunki końcowe:
  *  jeśli wczytywanie się nie powiodła funkcja assert zawiadomi o tym
  */

template<typename STyp, int SWymiar>
istream &operator>>(istream &StrWe, Macierz<STyp, SWymiar> &Mac)
{  for (int idx = 0; idx <SWymiar; idx++)
{
  cin>>Mac[idx];
  if (StrWe.fail())
    {
      assert("Bład podczas wporwadzania danych" && !StrWe.fail());
      return StrWe;
    }
}

  return StrWe;
}

#endif
