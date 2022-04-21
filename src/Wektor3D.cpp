#include "Wektor3D.hh"
istream &operator>>(istream &StrWe, Wektor3D &Zm){
  for (int i = 0; i <3; i++)
  {
    StrWe>>Zm[i];
    if (StrWe.fail())
    {
      assert("Błąd podczas wporwadzania danych" && !StrWe.fail());
      return StrWe;
     }
   }
  return StrWe;
}

ostream & operator << (ostream & StrWyj, Wektor3D A){ 
  for ( int i = 0; i < 3; i++)
  {
    StrWyj<<A[i]<<' ';
  }
  
  return StrWyj;
}
int Wektor3D::_LacznaIlosc=0;


int Wektor3D::_AktualnaIlosc=0;
