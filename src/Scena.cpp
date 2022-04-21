#include "Scena.hh"



  void KopjujPlikZPlaszczyzna(std::string Wzor, std::string Kopia){
   double ch;
   int licznik =0;
   ifstream fs (Wzor);
   ofstream ft (Kopia);
   while(licznik<=1)
  {
    fs>>ch;
    ft<<ch;
    ft<<' ';
    fs>>ch;
    ft<<ch;
    ft<<' ';
    fs>>ch;
    ft<<ch;
    ft<<"\n";
  
    fs>>ch;
    ft<<ch;
    ft<<' ';
    fs>>ch;
    ft<<ch;
    ft<<' ';
    fs>>ch;
    ft<<ch;
    ft<<"\n";
    ft<<"\n";
    ++licznik;
  }
  fs.close();
  ft.close();
 }
 void KopjujPlikZPret(std::string Wzor, std::string Kopia){
   double ch;
   ifstream fs (Wzor);
   ofstream ft (Kopia);
  
   fs>>ch;
   ft<<ch;
   ft<<' ';
   fs>>ch;
   ft<<ch;
   ft<<' ';
   fs>>ch;
   ft<<ch;
   ft<<"\n";
   
   fs>>ch;
   ft<<ch;
   ft<<' ';
   fs>>ch;
   ft<<ch;
   ft<<' ';
   fs>>ch;
   ft<<ch;
  
   fs.close();
   ft.close();
  }



 void KopjujPlikZProstopadloscian(std::string Wzor, std::string Kopia){
   double ch;
   int licznik =0;
   ifstream fs (Wzor);
   ofstream ft (Kopia);
   while(licznik<5)
   {
    fs>>ch;
    ft<<ch;
    ft<<' ';
    fs>>ch;
    ft<<ch;
    ft<<' ';
    fs>>ch;
    ft<<ch;
    ft<<"\n";
  
    fs>>ch;
    ft<<ch;
    ft<<' ';
    fs>>ch;
    ft<<ch;
    ft<<' ';
    fs>>ch;
    ft<<ch;
    ft<<"\n";
  
    fs>>ch;
    ft<<ch;
    ft<<' ';
    fs>>ch;
    ft<<ch;
    ft<<' ';
    fs>>ch;
    ft<<ch;
    ft<<"\n";
  
    fs>>ch;
    ft<<ch;
    ft<<' ';
    fs>>ch;
    ft<<ch;
    ft<<' ';
    fs>>ch;
    ft<<ch;
    ft<<"\n";
    ft<<"\n";
    ++licznik;
  }
  fs.close();
  ft.close();

 }

 Dron::Dron(char NumerDrona, Wektor3D PozycjaPoczatkowa,PzG::LaczeDoGNUPlota  Lacze){
  string a("bryly/AproksymacjaGlob.dat");
  string b("bryly/PraweGlob.dat");
  string c("bryly/LeweGlob.dat");
  string d("bryly/Korpus.dat");
  string e("bryly/SmigloLewe.dat");
  string f("bryly/SmigloPrawe.dat");

  Aproksymacja= Prostopadloscian(4,5,"bryly/Aproksymacja.dat");
  Aproksymacja.ZmienNazwePliku_WspGlb(a+=NumerDrona);
  Prawe.ZmienNazwePliku_WspGlb(b+=NumerDrona);
  Lewe. ZmienNazwePliku_WspGlb(c+=NumerDrona);
  Korpus.ZmienNazwePliku_WspGlb(d+=NumerDrona);
  PomLewe.ZmienNazwePliku_WspGlb(e);
  PomPrawe.ZmienNazwePliku_WspGlb(f);
  PomPrawe.ZmienPolozenie(Wektor3D(20,-50,0));
  PomLewe.ZmienPolozenie(Wektor3D(-20,-50,0));
  Prawe.ZmienPolozenie(PozycjaPoczatkowa);
  Lewe.ZmienPolozenie(PozycjaPoczatkowa);
  Korpus.ZmienPolozenie(PozycjaPoczatkowa);
  Aproksymacja.ZmienPolozenie(PozycjaPoczatkowa);
  Prawe.ObliczWspGlb();
  Lewe.ObliczWspGlb();
  Korpus.ObliczWspGlb();
  Aproksymacja.ObliczWspGlb();
  Lacze.DodajNazwePliku((d).c_str());
  Lacze.DodajNazwePliku((b).c_str());
  Lacze.DodajNazwePliku((c).c_str());
}
void Dron::ObrocX(double Kat){
   PomPrawe.ObrocY(PomPrawe.WartoscKataY()-45);
   PomLewe.ObrocY(PomLewe.WartoscKataY()-45);
   PomPrawe.ObliczWspGlb();
   PomLewe.ObliczWspGlb();
   Lewe.Zmien_WspLok(4,7,Lewe.ZwrocNazweLok());
   Prawe.Zmien_WspLok(4,7,Prawe.ZwrocNazweLok());
   Prawe.ObrocX(Kat);
   Lewe.ObrocX(Kat);
   Korpus.ObrocX(Kat);
   Aproksymacja.ObrocX(Kat);
 }

 void Dron::ObrocZ(double Kat){  
   PomPrawe.ObrocY(PomPrawe.WartoscKataY()-45);
   PomLewe.ObrocY(PomLewe.WartoscKataY()-45);
   PomPrawe.ObliczWspGlb();
   PomLewe.ObliczWspGlb();
   Lewe.Zmien_WspLok(4,7,Lewe.ZwrocNazweLok());
   Prawe.Zmien_WspLok(4,7,Prawe.ZwrocNazweLok());
   Prawe.ObrocZ(Kat);
   Lewe.ObrocZ(Kat);
   Korpus.ObrocZ(Kat);
   Aproksymacja.ObrocZ(Kat);
 }

  void Dron::ObrocY(double Kat){
   PomPrawe.ObrocY(PomPrawe.WartoscKataY()-45);
   PomLewe.ObrocY(PomLewe.WartoscKataY()-45);
   PomPrawe.ObliczWspGlb();
   PomLewe.ObliczWspGlb();
   Lewe.Zmien_WspLok(4,7,Lewe.ZwrocNazweLok());
   Prawe.Zmien_WspLok(4,7,Prawe.ZwrocNazweLok());
   Prawe.ObrocY(Kat);
   Lewe.ObrocY(Kat);
   Korpus.ObrocY(Kat);
   Aproksymacja.ObrocY(Kat);
 }

  void Dron::ZmienPolozenie(const Wektor3D & Pol){
   PomPrawe.ObrocY(PomPrawe.WartoscKataY()-45);
   PomLewe.ObrocY(PomLewe.WartoscKataY()-45);
   PomPrawe.ObliczWspGlb();
   PomLewe.ObliczWspGlb();
   Lewe.Zmien_WspLok(4,7,Lewe.ZwrocNazweLok());
   Prawe.Zmien_WspLok(4,7,Prawe.ZwrocNazweLok());
   Korpus.ZmienPolozenie(Pol);
   Aproksymacja.ZmienPolozenie(Pol);
   Lewe.ZmienPolozenie(Pol);
   Prawe.ZmienPolozenie(Pol); 
  }

  bool Scena::SprawdzCzyWyplynalUderzlWDno(){
    double glembokosc = DnoScean.Glebokosc();
    double wyskosc = WodaScena.WysokoscWody();
    for(unsigned int Ind_Lamanej =0; Ind_Lamanej< (**Pr).ZwrocGlobalne().size(); ++Ind_Lamanej){
        for (unsigned int Ind_WieLamanej = 0; Ind_WieLamanej < (**Pr).ZwrocGlobalne()[Ind_Lamanej].ZwrocStosW3D().size(); ++Ind_WieLamanej){
            if((((**Pr).ZwrocGlobalne()[Ind_Lamanej].ZwrocStosW3D()[Ind_WieLamanej][2])<=(glembokosc))){return true; }
            if((((**Pr).ZwrocGlobalne()[Ind_Lamanej].ZwrocStosW3D()[Ind_WieLamanej][2])>=(wyskosc))){return true;};
          }
      }
    return false;
  }

  bool Scena::Pojedzdoprzodudronem(double odleglosc, double kat){
    MacierzObortuX MacierzX;
    MacierzObortuZ MacierzZ;
    MacierzObortuY MacierzY;
    double znak;
    if (odleglosc != 0){
      znak = odleglosc/abs(odleglosc);}
    else
    {
      znak = 1;
    }
    double iloscruchow = abs(odleglosc)/10;
    int idx=0;    
    (**Pr).ObliczWspGlb();
    if(SprawdzczyKol()){cout<<"Kurs kolizjny, przerwano ruch"<<endl<<endl; (**Pr).ZmienPolozenie((MacierzZ*MacierzY*MacierzX)*Wektor3D(0,(-10*znak),0));(**Pr).ObliczWspGlb(); return false; }
    if(SprawdzczyKolmiedzyDronami()){cout<<"Kurs kolizjny, przerwano ruch"<<endl<<endl; (**Pr).ZmienPolozenie((MacierzZ*MacierzY*MacierzX)*Wektor3D(0,(-10*znak),0));(**Pr).ObliczWspGlb(); return false; }
    Lacze.Rysuj();
    MacierzX.Oblicz(kat);
    MacierzZ.Oblicz((**Pr).WartoscKataZ());
    MacierzY.Oblicz((**Pr).WartoscKataY());
    
    while (idx<iloscruchow)
    {
      (**Pr).ZmienPolozenie((MacierzZ*MacierzY*MacierzX)*Wektor3D(0,10*znak,0));
      (**Pr).ObliczWspGlb();
      
      if(SprawdzczyKol()){cout<<"Kurs kolizjny, przerwano ruch"<<endl<<endl; (**Pr).ZmienPolozenie((MacierzZ*MacierzY*MacierzX)*Wektor3D(0,(-10*znak),0));(**Pr).ObliczWspGlb(); return false;  }
        if(SprawdzczyKolmiedzyDronami()){cout<<"Kurs kolizjny, przerwano ruch"<<endl<<endl; (**Pr).ZmienPolozenie((MacierzZ*MacierzY*MacierzX)*Wektor3D(0,(-10*znak),0));(**Pr).ObliczWspGlb(); return false; }
         Lacze.Rysuj();
         usleep(100000);
       idx++;
    }
     
    (**Pr).ZmienPolozenie(MacierzZ*MacierzY*MacierzX*Wektor3D(0,(odleglosc-(znak*10*idx)),0));
    (**Pr).ObliczWspGlb();
    
    if(SprawdzczyKol()){cout<<"Kurs kolizjny, przerwano ruch"<<endl<<endl; (**Pr).ZmienPolozenie((MacierzZ*MacierzY*MacierzX)*Wektor3D(0,(-10*znak),0));(**Pr).ObliczWspGlb(); return false; }
    if(SprawdzczyKolmiedzyDronami()){cout<<"Kurs kolizjny, przerwano ruch"<<endl<<endl; (**Pr).ZmienPolozenie((MacierzZ*MacierzY*MacierzX)*Wektor3D(0,(-10*znak),0));(**Pr).ObliczWspGlb(); return false; }
    Lacze.Rysuj();
    usleep(100000);
    if(SprawdzCzyWyplynalUderzlWDno()){
       (**Pr).ObrocX(kat+180);
       cout<<"Dron wyjechł poza wyznaczony obszar, został cofnięty"<<endl<<endl;
       MacierzX.Oblicz((**Pr).WartoscKataX()); 
       (**Pr).ZmienPolozenie(MacierzZ*MacierzY*MacierzX*Wektor3D(0,odleglosc,0));
       (**Pr).ObliczWspGlb();
       (**Pr).ObrocX(0);
       (**Pr).ObliczWspGlb();
       Lacze.Rysuj();
     } 
     return true;
  }

  bool Scena::RotujDrona (double kat){
   
    MacierzObortuZ MacierzZ;
    int iloscobortow=abs((kat-(**Pr).WartoscKataZ())/5);
    double katpom =0;
    double pom =(**Pr).WartoscKataZ();
    int idx=0;
    while (idx<iloscobortow)
    {
      katpom =(kat-pom)/iloscobortow;
      (**Pr).ObrocZ(katpom*idx+pom);
      (**Pr).ObliczWspGlb();
      if(SprawdzczyKol()){cout<<"Kurs kolizjny, przerwano ruch"<<endl<<endl; (**Pr).ObrocZ(katpom*(idx-1)+pom);(**Pr).ObliczWspGlb(); return false; }
      if(SprawdzczyKolmiedzyDronami()){cout<<"Kurs kolizjny, przerwano ruch"<<endl<<endl; (**Pr).ObrocZ(katpom*(idx-1)+pom);(**Pr).ObliczWspGlb(); return false; }
      Lacze.Rysuj();
      usleep(100000);
      ++idx;
     }
     (**Pr).ObrocZ(kat);
     (**Pr).ObliczWspGlb();
     if(SprawdzczyKol()){cout<<"Kurs kolizjny, przerwano ruch"<<endl<<endl; (**Pr).ObrocZ(katpom*idx+pom);(**Pr).ObliczWspGlb(); return false; }
     if(SprawdzczyKolmiedzyDronami()){cout<<"Kurs kolizjny, przerwano ruch"<<endl<<endl; (**Pr).ObrocZ(katpom*(idx-1)+pom);(**Pr).ObliczWspGlb(); return false; }
     Lacze.Rysuj();
     usleep(100000);

     return true;
    }

    Scena::Scena (){
    
      Lacze.ZmienTrybRys(PzG::TR_3D);
      Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
      Lacze.UstawZakresX(Zakres0X, Zakres1X);
      Lacze.UstawZakresY(Zakres0Y, Zakres1Y);
      Lacze.UstawZakresZ(Zakres0Z, Zakres1Z);
      Lacze.UstawRotacjeXZ(84,60); // Tutaj ustawiany jest widok
      Lacze.DodajNazwePliku("bryly/DnoGenerowane");
      
      Lacze.DodajNazwePliku("bryly/WodaGenerowane");
      Drony.push_back(make_shared<Dron>( Dron('1',Wektor3D(0,0,0),Lacze)));
      Drony.push_back(make_shared<Dron>( Dron('2',Wektor3D(100,0,-100),Lacze)));
      Drony.push_back(make_shared<Dron>( Dron('3',Wektor3D(-100,0,-100),Lacze)));
      
      KopjujPlikZProstopadloscian("bryly/Slup1POM.dat","bryly/Slup1.dat");
      Lst.push_back(make_shared<Prostopadloscian>( Prostopadloscian(4,5,"bryly/Slup1.dat")));
      Lacze.DodajNazwePliku("bryly/Slup1.dat");

      KopjujPlikZProstopadloscian("bryly/Slup2POM.dat","bryly/Slup2.dat");
      Lst.push_back(make_shared<Prostopadloscian>( Prostopadloscian(4,5,"bryly/Slup2.dat")));
      Lacze.DodajNazwePliku("bryly/Slup2.dat");
      
      KopjujPlikZPret("bryly/pret1POM.dat","bryly/pret1.dat");
      Lst.push_back(make_shared<Prosta>( Prosta(2,1,"bryly/pret1.dat")));
      Lacze.DodajNazwePliku("bryly/pret1.dat");

      KopjujPlikZPret("bryly/pret2POM.dat","bryly/pret2.dat");
      Lst.push_back(make_shared<Prosta>( Prosta(2,1,"bryly/pret2.dat")));
      Lacze.DodajNazwePliku("bryly/pret2.dat");
     
      KopjujPlikZPlaszczyzna("bryly/plaszczyzna2POM.dat","bryly/plaszczyzna2.dat");
      Lst.push_back(make_shared<Plaszczyzna> ( Plaszczyzna(2,2,"bryly/plaszczyzna2.dat")));
      Lacze.DodajNazwePliku("bryly/plaszczyzna2.dat");
      
      GenerujDno(40, 40);
      Dno Dnopom (((Zakres1Y-Zakres0Y)/40)+2,((Zakres1X-Zakres0X)/40)+2,"bryly/DnoGenerowane");
      DnoScean=Dnopom;
      
      GenerujWode(40,40,20);
      Woda WodaScenapom((((Zakres1Y-Zakres0Y)/40)+2.0),(((Zakres1X-Zakres0X)/40)+2),"bryly/WodaGenerowane");
      WodaScena = WodaScenapom;
      iloscprzeszkod=5;
      Pr=Drony.begin();
    }

    void Scena::DodajPret (double dlugosc, double srodekx, double srodeky, double srodekz ){
     char Nazwapliku[]="bryly/DodanyPretx";
     Nazwapliku[16]= 'a'+iloscprzeszkod;
     ++iloscprzeszkod;
     ofstream StrmWyj(Nazwapliku);
     Wektor<double,3> Koniec1(dlugosc/2,0,0);
     Wektor<double,3> Koniec2(-1*dlugosc/2,0,0);
     Wektor<double,3> Trans(srodekx,srodeky,srodekz);
     StrmWyj<< Koniec1 + Trans <<endl;
     StrmWyj<< Koniec2 +Trans <<endl;
     Lacze.DodajNazwePliku(Nazwapliku);
     Lst.push_back(make_shared<Prosta>( Prosta(2,1,Nazwapliku)));
    } 
 
   void Scena::DodajPowierzchnia (double szerokosc, double wysokosc, double srodekx, double srodeky, double srodekz ){
     char Nazwapliku[]="bryly/DodanaPowierzchniax";
     Nazwapliku[24]= 'a'+iloscprzeszkod;
     ++iloscprzeszkod;
     ofstream StrmWyj(Nazwapliku);
     Wektor<double,3> Koniec1(szerokosc/2,0,wysokosc/2);
     Wektor<double,3> Koniec2(-1*szerokosc/2,0,wysokosc/2);
     Wektor<double,3> Koniec3(szerokosc/2,0,-wysokosc/2);
     Wektor<double,3> Koniec4(-1*szerokosc/2,0,-wysokosc/2);
     Wektor<double,3> Trans(srodekx,srodeky,srodekz);
     StrmWyj<< Koniec1 + Trans <<endl;
     StrmWyj<< Koniec2 +Trans <<endl<<endl;
     StrmWyj<< Koniec3 + Trans <<endl;
     StrmWyj<< Koniec4 +Trans <<endl;
     Lacze.DodajNazwePliku(Nazwapliku);
     Lst.push_back(make_shared<Plaszczyzna>( Plaszczyzna(2,2,Nazwapliku)));
   }  

   void Scena::DodajProstopadloscian (double szerokosc, double wysokosc, double dlugosc, double srodekx, double srodeky, double srodekz ){
      char Nazwapliku[]="bryly/DodanaProstopadloscianx";
      Nazwapliku[28]= 'a'+iloscprzeszkod;
      ++iloscprzeszkod;
      ofstream StrmWyj(Nazwapliku);
      Wektor<double,3> Koniec1(szerokosc/2,0,0);
      Wektor<double,3> Koniec2(szerokosc/2,dlugosc/2,wysokosc/2);
      Wektor<double,3> Koniec3(-1*szerokosc/2,dlugosc/2,wysokosc/2);
      Wektor<double,3> Koniec4(-1*szerokosc/2,0,0);
      Wektor<double,3> Trans(srodekx,srodeky,srodekz);
      Wektor<double,3 > Koniec5(szerokosc/2,dlugosc/2,-1*wysokosc/2);
      Wektor<double,3 > Koniec6(-szerokosc/2,dlugosc/2,-1*wysokosc/2);
      Wektor<double,3 > Koniec7(szerokosc/2,-1*dlugosc/2,-1*wysokosc/2);
      Wektor<double,3 > Koniec8(-szerokosc/2,-1*dlugosc/2,-1*wysokosc/2);
      Wektor<double,3 > Koniec9(szerokosc/2,-1*dlugosc/2, 1*wysokosc/2);
      Wektor<double,3 > Koniec10(-szerokosc/2,-1*dlugosc/2,1*wysokosc/2);
      StrmWyj<< Koniec1 + Trans <<endl;
      StrmWyj<< Koniec2 +Trans <<endl;
      StrmWyj<< Koniec3 + Trans <<endl;
      StrmWyj<< Koniec4 +Trans <<endl<<endl;

      StrmWyj<< Koniec1 + Trans <<endl;
      StrmWyj<< Koniec5 + Trans <<endl;
      StrmWyj<< Koniec6 +Trans <<endl;
      StrmWyj<< Koniec4 +Trans <<endl<<endl;
   
      StrmWyj<< Koniec1 + Trans <<endl;
      StrmWyj<< Koniec7 + Trans <<endl;
      StrmWyj<< Koniec8 +Trans <<endl;
      StrmWyj<< Koniec4 +Trans <<endl<<endl;

      StrmWyj<< Koniec1 + Trans <<endl;
      StrmWyj<< Koniec9 + Trans <<endl;
      StrmWyj<< Koniec10 +Trans <<endl;
      StrmWyj<< Koniec4 +Trans <<endl<<endl;

      StrmWyj<< Koniec1 + Trans <<endl;
      StrmWyj<< Koniec2 +Trans <<endl;
      StrmWyj<< Koniec3 + Trans <<endl;
      StrmWyj<< Koniec4 +Trans <<endl<<endl;
      Lacze.DodajNazwePliku(Nazwapliku);
      Lst.push_back(make_shared<Prostopadloscian> (Prostopadloscian(4,5,Nazwapliku)));
   }
