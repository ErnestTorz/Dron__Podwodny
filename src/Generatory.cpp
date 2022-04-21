#include "Generatory.hh"

void GenerujWode (double wymiarX,double wymiarY,double wysokoscfali ){
   ofstream StrmWyj("bryly/WodaGenerowane");
   double iloscnaX = ((Zakres1X-Zakres0X)/wymiarX)+2;
   double iloscnaY = ((Zakres1Y-Zakres0Y)/wymiarY)+2;
   Wektor<double,3> pomtransX (wymiarX,0,0);
   Wektor<double,3> transX (0,0,0); 
   Wektor<double, 3> transY(0,wymiarY,0);
   Wektor<double,3> Wek (Zakres0X,(Zakres0Y),Zakres1Z-wysokoscfali);
   Wektor<double,3> zera (0,0,0);
   Wektor<double,3 > wysokosc (0,0,wysokoscfali);
   for (double idx1 = 0; idx1 < iloscnaY; idx1++)
   {
     for (double idx2 = 0; idx2 < iloscnaX; idx2++)
     {
       StrmWyj<< Wek+transX<<endl;  
       transX=transX+pomtransX;
      }
    
     transX=zera;
     StrmWyj<<endl;
     Wek=Wek+transY;
     Wek=Wek+wysokosc;
     wysokosc=wysokosc*-1;
    }

  }
 
 void GenerujDno(double wymiarX,double wymiarY){
   ofstream StrmWyj("bryly/DnoGenerowane");
   double iloscnaX = ((Zakres1X-Zakres0X)/wymiarX)+2;
   double iloscnaY = ((Zakres1Y-Zakres0Y)/wymiarY)+2;
   Wektor<double,3> pomtransX (wymiarX,0,0);
   Wektor<double,3> transX (0,0,0); 
   Wektor<double, 3> transY(0,wymiarY,0);
   Wektor<double,3> A (Zakres0X,(Zakres0Y),Zakres0Z);
   Wektor<double,3> zera (0,0,0);

   for (double idx1 = 0; idx1 < iloscnaY; idx1++)
   {  
     for (double idx2 = 0; idx2 < iloscnaX; idx2++)
     {
       StrmWyj<< A+transX<<endl;
       transX=transX+pomtransX;
      } 
     
      transX=zera;
      StrmWyj<<endl;
      A=A+transY;
    }
  }