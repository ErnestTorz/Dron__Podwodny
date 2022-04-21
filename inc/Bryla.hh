#ifndef Bryla_HH
#define Bryla_HH

#include <iostream>
#include <iomanip>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include<string>
#include <unistd.h>
#include "Wektor.hh"
#include"math.h"
#include "MacierzObrotu.hh"
#include "Wektor3D.hh"

using namespace std;

/*! 
*Klasa opisujaca lamana skladajaca sie z Wektorow3D
*
*/
class Lamana {
  std::vector<Wektor3D> _StosW3D;
  public:
  /*! 
  * Matoda umozliwia dostep do stosu skladejacego sie z Wektorow 3D
  * Zwraca _StosW3D
  */
  std::vector<Wektor3D> & ZwrocStosW3D (){return _StosW3D;}
  /*!  Definiuje dodawanie wektora do lamanej*/
  Lamana operator + (Wektor3D wek){
    Lamana pom;
    for (unsigned int idx = 0; idx < this->_StosW3D.size(); idx++)
    {
      pom._StosW3D[idx]= _StosW3D[idx]+wek;
    }
    return pom;
  }
  
};

/*!  Klasa definiujaca Powierzchnie geometryczna, przdatna przy dziedziczeniu do figur np. prostopadloscia*/
class PowierzniaGeom { 
    std::vector<Lamana> _TabLamanchy_Lok;
    std::vector<Lamana> _TabLamanchy_Glb;
    std::string _NazwaPlik_WspLok;
    std::string _NazwaPlik_WspGlb;
    double _KatObrZ=0;
    double _KatObrY=0;
    double _KatObrX=0;
    Wektor3D _Trans;
     public:
     PowierzniaGeom(){};
     /*! 
     *Konsturktor wczytujacy dane z pliku do _TabLamanych_Lok i _TabLamanych_Glb oraz przypisuje nazwe pliku do _NazwaPlik_WspLok(NazwaPlik_WspLok)
     *
     */
    
     PowierzniaGeom(unsigned int Ilosc_WieLamanej, unsigned int Ilosc_Lamanych, const std::string & NazwaPlik_WspLok);
     /*!  Metoda pozwlajaca zmienic i wczytac Wsp loklne
     * Przdatna zwlaszcza przy deklaracji klasy i wywolaniu jej bezparametrycznie
     * \param[in] Ilosc_WieLamanej
     * \param[in] Ilosc_Lamanych
     * \param[in] NazwaPlik_WspLok
     */
     void Zmien_WspLok (unsigned int Ilosc_WieLamanej, unsigned int Ilosc_Lamanych, const std::string & NazwaPlik_WspLok);

    /*!  Zmienia _NazwaPlik_WspGlb
    * parametry wejsciowe:
    * \param[in] NazwaPlik_WspGlb
    */
     void ZmienNazwePliku_WspGlb(const std::string & NazwaPlik_WspGlb){_NazwaPlik_WspGlb= NazwaPlik_WspGlb;}
     /*!  Zmienia polozenie obiektu o Wekro3D Pol
      * \param[in] NazwaPlik_WspGlb
      */
     void ZmienPolozenie(const Wektor3D Pol){_Trans =_Trans+Pol;}
     
     /*!  Zmienia polozenie wzgledem osi Z o kat wyrazony w stopniach
     * \param[in] Pol
     */
     void ObrocZ(double Kat){_KatObrZ=Kat;}
      /*! 
      Zwraca Kat wyorazony w stopniach o jaki jest obrocony obiekt wzgledem osi Z
      \param[in] Kat - wyrazony w stopniach
     */  
     double WartoscKataZ(){return _KatObrZ; }   
     
     /*!  Zmienia polozenie o wartosc kata wyrazonego w stopniach wzgledem osi X o kat wyrazony w stopniach
     * \param[in] Kat - wyrazony w stopniach
     */  
     void ObrocX(double Kat){_KatObrX=Kat;}

     /*! Zwraca wartosc obecnego kat wyrazony w stopniachwyrazonego w stopniach o jak obiekt zostal obrocony wzgledem osi Y*/
     double WartoscKataX(){return _KatObrX; }

     /*! Zmienia polozenie o kat wyrazony w stopniachyrazony w stopniach wzgledem osi Y o kat wyrazony w stopniach
     \param[in] Kat - wyrazony w stopniach
     */  
     void ObrocY(double Kat){_KatObrY=Kat;}

     /*! Zwraca wartosc obecnego kat wyrazony w stopniachwyrazonego w stopniach o jak obiekt zostal obrocony wzgledem osi Y*/
     double WartoscKataY(){return _KatObrY; }
     /*! Oblicza polozenie wspolrzednych globalnych przez odpowiednia translacje o proty wokol osi jesli takowe zostaly wykonane*/
     bool ObliczWspGlb();

     Wektor3D ZwrocWektor3D ()const {return _Trans;}

     std::vector<Lamana> ZwrocGlobalne() const {return _TabLamanchy_Glb;}

     const char * ZwrocNazweLok( )const {  const char * a = _NazwaPlik_WspLok.c_str();
       return a;}

    /*!  Znajduje najmniejsza wspolrzedna X*/ 
    virtual double XMIN () const {return 0;}
    /*!  Znajduje najmiejsza wpolrzedna Y*/
    virtual double YMIN () const {return 0;}
    /*!  Znajduje najmniejsza wspolrzedna Z*/
    virtual double ZMIN () const {return 0;}
   /*!  Znajduje najwieksza wspolrzedna X*/
    virtual double XMAX () const {return 0;}
    /*!  Znajduje najwieksza wspolrzedna Y */
    virtual double YMAX () const {return 0;}
    /*!  Znajduje najwieksza wspolrzedna Z*/
    virtual double ZMAX () const {return 0;}
    /*!  Zwraca nazwe obiektu*/
    virtual const char* NazwaTypu() const {return "Powierzchnia Geometryczna";}
   /*!  Zwraca infomacje o srodku bryly*/
   virtual void Srodek () const { }

};

/*! Klasa modelujaca pojecie Wody,
dziedziczy czesc publiczna PowierzchniGoom
*/
class Woda: public PowierzniaGeom{

public:
 Woda():PowierzniaGeom(){}
 /*! 
  Konstruktor ktory wczytuje plaszczyzne wody
  Parametry wejsciowe double X, double Y,const std::string & NazwaPlik_WspLok

  */
 Woda(double X, double Y,const std::string & NazwaPlik_WspLok): PowierzniaGeom(X,Y,NazwaPlik_WspLok){}
 /*!  Konstruktor generujacy plaszczyzne wody na o plytkach o wymiarach wymiarx, wymiar y, o wysoskosci fali wysokoscfali
 * na szerokosci Zakers0X, double Zakres1X, double Zakers0Y, double Zakres1Y, double Zakres1Z
 * gdzie 0 to poczatek zaczepiania 1 to koniec zaczepienia plaszyzny wody
 * 
 * * \param[in] Y -wymiar y
* \param[in] X - wymiar x
 * \param[in] NazwaPlik_WspLok
 */


  

  /*! Metoda Znajduje i zwraca najmniejsza Z-owa tafli wody*/
  double WysokoscWody (){
   double pom=ZwrocGlobalne()[0].ZwrocStosW3D()[0][2];
   for (unsigned int Idx1 = 0; Idx1 <ZwrocGlobalne().size(); ++Idx1)
   {
     for (unsigned int Idx2 = 0; Idx2 < ZwrocGlobalne()[0].ZwrocStosW3D().size(); ++Idx2)
     {
        if (pom > ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][2])
        {
          pom = ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][2];
        }      
      }
    }
    return pom; 
  }
    
 /*!  Zwraca nazwe obiektu*/
 virtual const char* NazwaTypu() const override {return "Woda";}
};

/*!  Klada modelujaca pojecie Powierzchni dna*/
class Dno: public PowierzniaGeom{

public:
 Dno():PowierzniaGeom(){}
 /*!  Konstruktor wczytujacy Dno
 * \param[in] Y
* \param[in] X
* \param[in] NazwaPlik_WspLok
 */
 Dno(double X, double Y, const std::string & NazwaPlik_WspLok): PowierzniaGeom(X,Y,NazwaPlik_WspLok){}

 /*!  Konstruktor generujacy plaszczyzne dna na o plytkach o wymiarach wymiarx, wymiar y, 
 * na szerokosci Zakers0X, double Zakres1X, double Zakers0Y, double Zakres1Y, double Zakres1Z
 * gdzie 0 to poczatek zaczepiania 1 to koniec zaczepienia plaszyzny wody
 * * \param[in] Y -wymiar y
* \param[in] X - wymiar x
 * \param[in] NazwaPlik_WspLok
 */

  
/*! Metoda znajduje najmniejsza zetowa dna i ja zwraca*/
 double Glebokosc (){
   double pom=ZwrocGlobalne()[0].ZwrocStosW3D()[0][2];
    for (unsigned int Idx1 = 0; Idx1 <ZwrocGlobalne().size(); ++Idx1)
    {
      for (unsigned int Idx2 = 0; Idx2 < ZwrocGlobalne()[0].ZwrocStosW3D().size(); ++Idx2)
      {
        if (pom > ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][2])
        {
          pom = ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][2];
        }
      }
    }
   return pom; 
 /*!  Zwraca nazwe obiektu*/ }
 virtual const char* NazwaTypu() const override {return "Dno";}
};

/*! Klasa modelujaca pojecie Prostopadloscianu*/
 class Prostopadloscian: public PowierzniaGeom{
 public:
 /*! Wczytuje prostopadloscian*/
 Prostopadloscian(): PowierzniaGeom(4,5,"bryly/prostopadloscian1.dat"){}
 Prostopadloscian(double X, double Y,const std::string & NazwaPlik_WspLok): PowierzniaGeom(X,Y,NazwaPlik_WspLok){}
  
  /*!  Znajduje najmniejsza wspolrzedna Z*/
  virtual double ZMIN () const override {
   double pom=ZwrocGlobalne()[0].ZwrocStosW3D()[0][2];
    for (unsigned int Idx1 = 0; Idx1 <ZwrocGlobalne().size(); ++Idx1)
    {
      for (unsigned int Idx2 = 0; Idx2 < ZwrocGlobalne()[0].ZwrocStosW3D().size(); ++Idx2)
      {
        if (pom > ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][2])
        {
          pom = ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][2];
        }
      }
    }
   return pom; 
  /*!  Zwraca nazwe obiektu*/}
  virtual const char* NazwaTypu() const override {return "Prostopadloscian";}

/*!  Znajduje najmniejsza wspolrzedna X*/
  virtual double XMIN () const override {
   double pom=ZwrocGlobalne()[0].ZwrocStosW3D()[0][0];
    for (unsigned int Idx1 = 0; Idx1 <ZwrocGlobalne().size(); ++Idx1)
    {
      for (unsigned int Idx2 = 0; Idx2 < ZwrocGlobalne()[0].ZwrocStosW3D().size(); ++Idx2)
      {
        if (pom > ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][0])
        {
          pom = ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][0];
        }
      }
    }
   return pom; 
  }

  /*!  Znajduje najmiejsza wpolrzedna Y*/
  virtual double YMIN () const override {
   double pom=ZwrocGlobalne()[0].ZwrocStosW3D()[0][1];
    for (unsigned int Idx1 = 0; Idx1 <ZwrocGlobalne().size(); ++Idx1)
    {
      for (unsigned int Idx2 = 0; Idx2 < ZwrocGlobalne()[0].ZwrocStosW3D().size(); ++Idx2)
      {
        if (pom > ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][1])
        {
          pom = ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][1];
        }
      }
    }
   return pom; 
  }

 /*!  Znajduje najwieksza wspolrzedna X*/
  virtual double XMAX () const override {
   double pom=ZwrocGlobalne()[0].ZwrocStosW3D()[0][0];
    for (unsigned int Idx1 = 0; Idx1 <ZwrocGlobalne().size(); ++Idx1)
    {
      for (unsigned int Idx2 = 0; Idx2 < ZwrocGlobalne()[0].ZwrocStosW3D().size(); ++Idx2)
      {
        if (pom < ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][0])
        {
          pom = ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][0];
        }
      }
    }
   return pom; 
  }

  /*!  Znajduje najwieksza wspolrzedna Y */
  virtual double YMAX () const override {
   double pom=ZwrocGlobalne()[0].ZwrocStosW3D()[0][1];
    for (unsigned int Idx1 = 0; Idx1 <ZwrocGlobalne().size(); ++Idx1)
    {
      for (unsigned int Idx2 = 0; Idx2 < ZwrocGlobalne()[0].ZwrocStosW3D().size(); ++Idx2)
      {
        if (pom < ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][1])
        {
          pom = ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][1];
        }
      }
    }
   return pom; 
  }

  /*!  Znajduje najwieksza wspolrzedna Z*/
  virtual double ZMAX () const override {
   double pom=ZwrocGlobalne()[0].ZwrocStosW3D()[0][2];
    for (unsigned int Idx1 = 0; Idx1 <ZwrocGlobalne().size(); ++Idx1)
    {
      for (unsigned int Idx2 = 0; Idx2 < ZwrocGlobalne()[0].ZwrocStosW3D().size(); ++Idx2)
      {
        if (pom < ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][2])
        {
          pom = ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][2];
        }
      }
    }
   return pom; 
  }
  virtual void Srodek () const override {cout<<(XMIN()+XMAX())/2<<' '<<(YMIN()+YMAX())/2<<' '<<(ZMIN()+ZMAX())/2; }

 };


 class Plaszczyzna: public PowierzniaGeom {
   
   public:
 /*! Wczytuje plaszczyzne*/
 Plaszczyzna(): PowierzniaGeom(2,2,"bryly/powierzchnia.dat"){}
 Plaszczyzna (double X, double Y,const std::string & NazwaPlik_WspLok): PowierzniaGeom(X,Y,NazwaPlik_WspLok){}
  /*!  Znajduje najmniejsza wspolrzedna Z*/
  virtual double ZMIN () const override {
   double pom=ZwrocGlobalne()[0].ZwrocStosW3D()[0][2];
    for (unsigned int Idx1 = 0; Idx1 <ZwrocGlobalne().size(); ++Idx1)
    {
      for (unsigned int Idx2 = 0; Idx2 < ZwrocGlobalne()[0].ZwrocStosW3D().size(); ++Idx2)
      {
        if (pom > ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][2])
        {
          pom = ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][2];
        }
      }
    }
   return pom; 
  }
   /*!  Zwraca nazwe obiektu*/
   virtual const char* NazwaTypu() const override {return "Plaszczyzna";}

/*!  Znajduje najmniejsza wspolrzedna X*/
  virtual double XMIN () const override {
   double pom=ZwrocGlobalne()[0].ZwrocStosW3D()[0][0];
    for (unsigned int Idx1 = 0; Idx1 <ZwrocGlobalne().size(); ++Idx1)
    {
      for (unsigned int Idx2 = 0; Idx2 < ZwrocGlobalne()[0].ZwrocStosW3D().size(); ++Idx2)
      {
        if (pom > ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][0])
        {
          pom = ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][0];
        }
      }
    }
   return pom; 
  }

  /*!  Znajduje najmiejsza wpolrzedna Y*/
  virtual double YMIN () const override {
   double pom=ZwrocGlobalne()[0].ZwrocStosW3D()[0][1];
    for (unsigned int Idx1 = 0; Idx1 <ZwrocGlobalne().size(); ++Idx1)
    {
      for (unsigned int Idx2 = 0; Idx2 < ZwrocGlobalne()[0].ZwrocStosW3D().size(); ++Idx2)
      {
        if (pom > ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][1])
        {
          pom = ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][1];
        }
      }
    }
   return pom; 
  }

 /*!  Znajduje najwieksza wspolrzedna X*/
  virtual double XMAX () const override {
   double pom=ZwrocGlobalne()[0].ZwrocStosW3D()[0][0];
    for (unsigned int Idx1 = 0; Idx1 <ZwrocGlobalne().size(); ++Idx1)
    {
      for (unsigned int Idx2 = 0; Idx2 < ZwrocGlobalne()[0].ZwrocStosW3D().size(); ++Idx2)
      {
        if (pom < ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][0])
        {
          pom = ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][0];
        }
      }
    }
   return pom; 
  }

  /*!  Znajduje najwieksza wspolrzedna Y */
  virtual double YMAX () const override {
   double pom=ZwrocGlobalne()[0].ZwrocStosW3D()[0][1];
    for (unsigned int Idx1 = 0; Idx1 <ZwrocGlobalne().size(); ++Idx1)
    {
      for (unsigned int Idx2 = 0; Idx2 < ZwrocGlobalne()[0].ZwrocStosW3D().size(); ++Idx2)
      {
        if (pom < ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][1])
        {
          pom = ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][1];
        }
      }
    }
   return pom; 
  }

  /*!  Znajduje najwieksza wspolrzedna Z*/
  virtual double ZMAX () const override {
   double pom=ZwrocGlobalne()[0].ZwrocStosW3D()[0][2];
    for (unsigned int Idx1 = 0; Idx1 <ZwrocGlobalne().size(); ++Idx1)
    {
      for (unsigned int Idx2 = 0; Idx2 < ZwrocGlobalne()[0].ZwrocStosW3D().size(); ++Idx2)
      {
        if (pom < ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][2])
        {
          pom = ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][2];
        }
      }
    }
   return pom; 
  }

  virtual void Srodek () const override {cout<<(XMIN()+XMAX())/2<<' '<<(YMIN()+YMAX())/2<<' '<<(ZMIN()+ZMAX())/2; }


};



  class Prosta: public PowierzniaGeom {
   
   public:
 /*! Wczytuje prosta*/
 Prosta(): PowierzniaGeom(2,1,"bryly/pret.dat"){}
 Prosta (double X, double Y,const std::string & NazwaPlik_WspLok): PowierzniaGeom(X,Y,NazwaPlik_WspLok){}
  /*!  Znajduje najmniejsza wspolrzedna Z*/
  virtual double ZMIN () const override {
   double pom=ZwrocGlobalne()[0].ZwrocStosW3D()[0][2];
    for (unsigned int Idx1 = 0; Idx1 <ZwrocGlobalne().size(); ++Idx1)
    {
      for (unsigned int Idx2 = 0; Idx2 < ZwrocGlobalne()[0].ZwrocStosW3D().size(); ++Idx2)
      {
        if (pom > ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][2])
        {
          pom = ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][2];
        }
      }
    }
   return pom; 
  }
/*!  Zwraca nazwe obiektu*/
  virtual const char* NazwaTypu() const override {return "Prosta";}

/*!  Znajduje najmniejsza wspolrzedna X*/
  virtual double XMIN () const override {
   double pom=ZwrocGlobalne()[0].ZwrocStosW3D()[0][0];
    for (unsigned int Idx1 = 0; Idx1 <ZwrocGlobalne().size(); ++Idx1)
    {
      for (unsigned int Idx2 = 0; Idx2 < ZwrocGlobalne()[0].ZwrocStosW3D().size(); ++Idx2)
      {
        if (pom > ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][0])
        {
          pom = ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][0];
        }
      }
    }
   return pom; 
  }

  /*!  Znajduje najmiejsza wpolrzedna Y*/
  virtual double YMIN () const override {
   double pom=ZwrocGlobalne()[0].ZwrocStosW3D()[0][1];
    for (unsigned int Idx1 = 0; Idx1 <ZwrocGlobalne().size(); ++Idx1)
    {
      for (unsigned int Idx2 = 0; Idx2 < ZwrocGlobalne()[0].ZwrocStosW3D().size(); ++Idx2)
      {
        if (pom > ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][1])
        {
          pom = ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][1];
        }
      }
    }
   return pom; 
  }

 /*!  Znajduje najwieksza wspolrzedna X*/
  virtual double XMAX () const override {
   double pom=ZwrocGlobalne()[0].ZwrocStosW3D()[0][0];
    for (unsigned int Idx1 = 0; Idx1 <ZwrocGlobalne().size(); ++Idx1)
    {
      for (unsigned int Idx2 = 0; Idx2 < ZwrocGlobalne()[0].ZwrocStosW3D().size(); ++Idx2)
      {
        if (pom < ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][0])
        {
          pom = ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][0];
        }
      }
    }
   return pom; 
  }

  /*!  Znajduje najwieksza wspolrzedna Y */
  virtual double YMAX () const override {
   double pom=ZwrocGlobalne()[0].ZwrocStosW3D()[0][1];
    for (unsigned int Idx1 = 0; Idx1 <ZwrocGlobalne().size(); ++Idx1)
    {
      for (unsigned int Idx2 = 0; Idx2 < ZwrocGlobalne()[0].ZwrocStosW3D().size(); ++Idx2)
      {
        if (pom < ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][1])
        {
          pom = ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][1];
        }
      }
    }
   return pom; 
  }

  /*!  Znajduje najwieksza wspolrzedna Z*/
  virtual double ZMAX () const override {
   double pom=ZwrocGlobalne()[0].ZwrocStosW3D()[0][2];
    for (unsigned int Idx1 = 0; Idx1 <ZwrocGlobalne().size(); ++Idx1)
    {
      for (unsigned int Idx2 = 0; Idx2 < ZwrocGlobalne()[0].ZwrocStosW3D().size(); ++Idx2)
      {
        if (pom < ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][2])
        {
          pom = ZwrocGlobalne()[Idx1].ZwrocStosW3D()[Idx2][2];
        }
      }
    }
   return pom; 
  }
 virtual void Srodek () const override {cout<<(XMIN()+XMAX())/2<<' '<<(YMIN()+YMAX())/2<<' '<<(ZMIN()+ZMAX())/2; }

};

#endif
