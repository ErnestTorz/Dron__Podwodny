#ifndef MacierzObrotu_HH
#define MacierzObrotu_HH
#include <iostream>
#include<cassert>
#include"Wektor.hh"
#include"Wektor3D.hh"
#include"Macierz.hh"

/*!Modeluje pojęcie macierzy obrotu X*/
class MacierzObortuX{
  Macierz<double,3> Mac;
  double kat=0;
  
  public:
  
  MacierzObortuX(){Oblicz(kat);}
   Wektor<double,3> operator [] (unsigned int Idx) const {assert(Idx <3); return Mac[Idx]; };
   Wektor<double,3> & operator [] (unsigned int Idx) {assert(Idx <3); return Mac[Idx]; };
   Macierz<double,3> ZwrocMacierz (){return Mac;}
   Macierz<double,3> Oblicz (double Kat){
   Mac[0][0]=1;
   Mac[1][0]=0;
   Mac[2][0]=0;
   Mac[0][1]=0;
   Mac[1][1]=cos(Kat*M_PI/180);
   Mac[2][1]=-sin(Kat*M_PI/180);
   Mac[0][2]=0;
   Mac[1][2]=sin(Kat*M_PI/180);
   Mac[2][2]=cos(Kat*M_PI/180);
   return Mac;
  }
  /*! modeluje pojęcie mnożenia Macierzy obrotu X * Wek3D*/
  Wektor3D operator * (Wektor3D Wek3D){
   Wektor3D pom;
   pom[0]=this->Mac[0][0]*Wek3D[0]+Mac[1][0]*Wek3D[1]+Mac[2][0]*Wek3D[2];
   pom[1]=this->Mac[0][1]*Wek3D[0]+Mac[1][1]*Wek3D[1]+Mac[2][1]*Wek3D[2];
   pom[2]=this->Mac[0][2]*Wek3D[0]+Mac[1][2]*Wek3D[1]+Mac[2][2]*Wek3D[2];
   return pom;
  }
  
  


};


/*! 
*Klasa modelująca pojęcie MacierzObrotuY
*/
class MacierzObortuY{
  Macierz<double,3> Mac;
  double kat=0;
  
  public:
   /*Bezparametryczne wywołanie konstruktora który wpełnia macierz obrotu kątem = 0*/
   MacierzObortuY(){Oblicz(kat);}
   Wektor<double,3> operator [] (unsigned int Idx) const {assert(Idx <3); return Mac[Idx]; };
   Wektor<double,3> & operator [] (unsigned int Idx) {assert(Idx <3); return Mac[Idx]; };
   
   Macierz<double,3> Oblicz (double Kat){
    Mac[0][0]=cos(Kat*M_PI/180);
    Mac[1][0]=0;
    Mac[2][0]=sin(Kat*M_PI/180);
    Mac[0][1]=0;
    Mac[1][1]=1;
    Mac[2][1]=0;
    Mac[0][2]=-sin(Kat*M_PI/180);
    Mac[1][2]=0;
    Mac[2][2]=cos(Kat*M_PI/180);
    return Mac;
  }
  /*! Modeluje pojęcie mnożenia macierzy obortu Y * wektor3D*/
  Wektor3D operator * (Wektor3D Wek3D){
   Wektor3D pom;
   pom[0]=this->Mac[0][0]*Wek3D[0]+Mac[1][0]*Wek3D[1]+Mac[2][0]*Wek3D[2];
   pom[1]=this->Mac[0][1]*Wek3D[0]+Mac[1][1]*Wek3D[1]+Mac[2][1]*Wek3D[2];
   pom[2]=this->Mac[0][2]*Wek3D[0]+Mac[1][2]*Wek3D[1]+Mac[2][2]*Wek3D[2];
   return pom;
  }
    /*!Modeluje pojęcie dodwania macierzy oboru Y * mcierz obrotu X*/
    MacierzObortuY operator * (MacierzObortuX MacX){
     MacierzObortuY pom;
     pom[0][0]= Mac[0][0]*MacX[0][0]+Mac[1][0]*MacX[0][1]+Mac[2][0]*MacX[0][2];
     pom[1][0]= Mac[0][0]*MacX[1][0]+Mac[1][0]*MacX[1][1]+Mac[2][0]*MacX[1][2];
     pom[2][0]= Mac[0][0]*MacX[2][0]+Mac[1][0]*MacX[2][1]+Mac[2][0]*MacX[2][2];
     pom[0][1]= Mac[0][1]*MacX[0][0]+Mac[1][1]*MacX[0][1]+Mac[2][1]*MacX[0][2];
     pom[1][1]= Mac[0][1]*MacX[1][0]+Mac[1][1]*MacX[1][1]+Mac[2][1]*MacX[1][2];
     pom[2][1]= Mac[0][1]*MacX[2][0]+Mac[1][1]*MacX[2][1]+Mac[2][1]*MacX[2][2];
     pom[0][2]= Mac[0][2]*MacX[0][0]+Mac[1][2]*MacX[0][1]+Mac[2][2]*MacX[0][2];
     pom[1][2]= Mac[0][2]*MacX[1][0]+Mac[1][2]*MacX[1][1]+Mac[2][2]*MacX[1][2];
     pom[2][2]= Mac[0][2]*MacX[2][0]+Mac[1][2]*MacX[2][1]+Mac[2][2]*MacX[2][2];

    return pom;
  }
  

};
/*!Modeluje pojęcie Macierzy obrotu Z*/
class MacierzObortuZ{
  Macierz<double,3> Mac;
  double kat=0;
  
  public:
  MacierzObortuZ(){Oblicz(kat);}
  Wektor<double,3> operator [] (unsigned int Idx) const {assert(Idx <3); return Mac[Idx]; };
  Wektor<double,3> & operator [] (unsigned int Idx) {assert(Idx <3); return Mac[Idx]; };
  Macierz<double,3> ZwrocMacierz (){return Mac;}
  Macierz<double,3> Oblicz (double Kat){
   Mac[0][0]=cos(Kat*M_PI/180);
   Mac[1][0]=-sin(Kat*M_PI/180);
   Mac[2][0]=0;
   Mac[0][1]=sin(Kat*M_PI/180);
   Mac[1][1]=cos(Kat*M_PI/180);
   Mac[2][1]=0;
   Mac[0][2]=0;
   Mac[1][2]=0;
   Mac[2][2]=1;
   return Mac;
  }
  /*! Definiuje Macierz obrotu Z I wektor 3D */
  Wektor3D operator * (Wektor3D Wek3D){
   Wektor3D pom;
   pom[0]=this->Mac[0][0]*Wek3D[0]+Mac[1][0]*Wek3D[1]+Mac[2][0]*Wek3D[2];
   pom[1]=this->Mac[0][1]*Wek3D[0]+Mac[1][1]*Wek3D[1]+Mac[2][1]*Wek3D[2];
   pom[2]=this->Mac[0][2]*Wek3D[0]+Mac[1][2]*Wek3D[1]+Mac[2][2]*Wek3D[2];
   return pom;
  }
  /*!Przeciązenie operatora mnożenia Macierz Obrotu Z * macierz obrotu Y*/
  MacierzObortuY operator * (MacierzObortuY MacY){
    MacierzObortuY pom;
    pom[0][0]= Mac[0][0]*MacY[0][0]+Mac[1][0]*MacY[0][1]+Mac[2][0]*MacY[0][2];
    pom[1][0]= Mac[0][0]*MacY[1][0]+Mac[1][0]*MacY[1][1]+Mac[2][0]*MacY[1][2];
    pom[2][0]= Mac[0][0]*MacY[2][0]+Mac[1][0]*MacY[2][1]+Mac[2][0]*MacY[2][2];
    pom[0][1]= Mac[0][1]*MacY[0][0]+Mac[1][1]*MacY[0][1]+Mac[2][1]*MacY[0][2];
    pom[1][1]= Mac[0][1]*MacY[1][0]+Mac[1][1]*MacY[1][1]+Mac[2][1]*MacY[1][2];
    pom[2][1]= Mac[0][1]*MacY[2][0]+Mac[1][1]*MacY[2][1]+Mac[2][1]*MacY[2][2];
    pom[0][2]= Mac[0][2]*MacY[0][0]+Mac[1][2]*MacY[0][1]+Mac[2][2]*MacY[0][2];
    pom[1][2]= Mac[0][2]*MacY[1][0]+Mac[1][2]*MacY[1][1]+Mac[2][2]*MacY[1][2];
    pom[2][2]= Mac[0][2]*MacY[2][0]+Mac[1][2]*MacY[2][1]+Mac[2][2]*MacY[2][2];

    return pom;
  }

};







#endif