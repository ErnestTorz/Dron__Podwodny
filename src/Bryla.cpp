#include"Bryla.hh"
bool PowierzniaGeom::ObliczWspGlb(){
 assert(!_NazwaPlik_WspLok.empty());
 assert(!_NazwaPlik_WspGlb.empty());
 MacierzObortuZ MacZ;
 MacierzObortuY MacY;
 MacierzObortuX MacX;
 ofstream StrmWyj(_NazwaPlik_WspGlb);
 MacZ.Oblicz(_KatObrZ);
 MacY.Oblicz(_KatObrY);
 MacX.Oblicz(_KatObrX);
 
 for(unsigned int Ind_Lamanej =0; Ind_Lamanej< _TabLamanchy_Lok.size(); ++Ind_Lamanej){
   for (unsigned int Ind_WieLamanej = 0; Ind_WieLamanej < _TabLamanchy_Lok[Ind_Lamanej].ZwrocStosW3D().size(); ++Ind_WieLamanej)
   {
       _TabLamanchy_Glb[Ind_Lamanej].ZwrocStosW3D()[Ind_WieLamanej]=(MacZ*MacY*MacX*_TabLamanchy_Lok[Ind_Lamanej].ZwrocStosW3D()[Ind_WieLamanej]+_Trans) ;
     
     StrmWyj<<_TabLamanchy_Glb[Ind_Lamanej].ZwrocStosW3D()[Ind_WieLamanej]<<endl;
     
   }
   StrmWyj<<endl;
 }
 
 return true;
}

PowierzniaGeom::PowierzniaGeom(unsigned int Ilosc_WieLamanej, unsigned int Ilosc_Lamanych, const std::string & NazwaPlik_WspLok): _NazwaPlik_WspLok(NazwaPlik_WspLok){
  ifstream StrmWej(_NazwaPlik_WspLok);
  Wektor3D pomw;
  Lamana poml;
       
  for(unsigned int Ind_Lamanej =0; Ind_Lamanej< Ilosc_Lamanych; ++Ind_Lamanej){
    poml.ZwrocStosW3D().clear();
    for (unsigned int Ind_WieLamanej = 0; Ind_WieLamanej < Ilosc_WieLamanej; ++Ind_WieLamanej)
    { 
      StrmWej>>pomw;
      poml.ZwrocStosW3D().push_back(pomw);
    }
    _TabLamanchy_Lok.push_back(poml);
    
  }
  _TabLamanchy_Glb=_TabLamanchy_Lok;
 }

  void PowierzniaGeom::Zmien_WspLok (unsigned int Ilosc_WieLamanej, unsigned int Ilosc_Lamanych, const std::string & NazwaPlik_WspLok){
   _NazwaPlik_WspLok=NazwaPlik_WspLok;
   _TabLamanchy_Lok.clear();
   ifstream StrmWej(_NazwaPlik_WspLok);
   Wektor3D pomw;
   Lamana poml;
      
   for(unsigned int Ind_Lamanej =0; Ind_Lamanej< Ilosc_Lamanych; ++Ind_Lamanej){
    poml.ZwrocStosW3D().clear();
    for (unsigned int Ind_WieLamanej = 0; Ind_WieLamanej < Ilosc_WieLamanej; ++Ind_WieLamanej)
    { 
       StrmWej>>pomw;
       poml.ZwrocStosW3D().push_back(pomw);
     }
    this->_TabLamanchy_Lok.push_back(poml);
   }
   this-> _TabLamanchy_Glb=_TabLamanchy_Lok;
  }

      