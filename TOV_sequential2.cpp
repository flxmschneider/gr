#include <iostream>                 //Ein-/Ausgabe (Include-Dateien)
#include <math.h>                   //Mathematisches
using namespace std;                //Fuer cout

//Definition der Zustandsgleichung
double eos(double p)
  {
    double e;
    e=pow(p/10,3.0/5);
    return e;
  }  

main(void)  //Hauptprogramm
  {
    //Variablendeklarationen
    int i;
    double M,p,e,r,nu,dM,dp,de,dr,dnu,dec;
    double eos(double);
    
    //Variableninitialisierung
    dr=0.000001;
    dec=0.0001;
    
    //for Schleife zur Berechnung mehrerer Sterne
    for (i=0;i<40;i++)
    {
      M=0;
      r=pow(10,-14);
      p=10*pow(0.0005+i*dec,5.0/3);
      nu=0;
      //do-while Schleife (Numerische Lösung der TOV-Gleichung) 
      do
        {
          e=eos(p);                                      //Wert der Energiedichte bei momentanen Druck
          dM=4*M_PI*e*r*r*dr;                            //Massenzunahme bei momentanem r und Schrittweite dr
          dp=-(p+e)*(M+4*M_PI*r*r*r*p)/(r*(r-2*M))*dr;   //Druckzunahme bei momentanem r und Schrittweite dr (TOV-Gleichung)
          dnu=(M + 4*M_PI*r*r*r*p)/(r*(r-2*M))*dr;       //Metrikzunahme bei momentanem r und Schrittweite dr
          r=r+dr;                                        //momentaner Radius des Neutronensterns
          M=M+dM;                                        //momentane Masse des Neutronensterns innerhalb des Radius r
          p=p+dp;                                        //momentaner Druck des Neutronensterns innerhalb des Radius r
          nu=nu+dnu;                                     //momentane Metrik des Neutronensterns innerhalb des Radius r
        }
        while(p>0);
      
      nu=log(1-2*M/r)/2-nu;
      //Ausgabe der Masse und des Radius auf dem Bildschirm
      cout<<i<<"\n";
      cout<<"Neutronensternradius [km]           = "<<r<<"\n";
      cout<<"Neutronensternmasse [Sonnenmassen]  = "<<M/1.4766<<"\n";
      cout<<"00-Metrikkomponente im Sternzentrum = "<<exp(2*nu)<<"\n";
      
    }
    
    return 0;                                          //main beenden (Programmende)
  }
