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
    double M,p,e,r,dM,dp,de,dr;
    double eos(double);
    
    //Variableninitialisierung
    M=0;
    r=pow(10,-14);
    //p=10*pow(0.0005,5.0/3);
    p = 17.25*exp(5/3);
    dr=0.000001;
    
    //do-while Schleife (Numerische L�sung der TOV-Gleichung) 
    do
      {
        e=eos(p);                                      //Wert der Energiedichte bei momentanen Druck
        dM=4*M_PI*e*r*r*dr;                            //Massenzunahme bei momentanem r und Schrittweite dr
        dp=-(p+e)*(M+4*M_PI*r*r*r*p)/(r*(r-2*M))*dr;   //Druckzunahme bei momentanem r und Schrittweite dr (TOV-Gleichung)
        r=r+dr;                                        //momentaner Radius des Neutronensterns
        M=M+dM;                                        //momentane Masse des Neutronensterns innerhalb des Radius r
        p=p+dp;                                        //momentaner Druck des Neutronensterns innerhalb des Radius r
      }
      while(p>0);

    //Ausgabe der Masse und des Radius auf dem Bildschirm
    cout<<"Neutronensternradius [km]          = "<<r<<"\n";
    cout<<"Neutronensternmasse [Sonnenmassen] = "<<M/1.4766<<"\n";

    return 0;                                          //main beenden (Programmende)
  }
