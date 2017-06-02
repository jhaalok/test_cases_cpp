// Calculation of conductivity coefficient (k) of Fuel and Zircalloy Gap

#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
  double k;
  const double geq=10e-4; //He
  const double C=2.5;
  const double phi12=0.3843;// von Ubisch
  const double phi21=3.4284;// von Ubisch
  const double He=0.90;
  const double Xe=0.10;
  const double kXe=10.4e-5;
  const double kHe=252.4e-5;
  const double km=0.075;
  const double a0=0.5;
  const double r1=2.3e-4;
  const double r2=2.3e-5;
  const double H=6.9e3;
  const double P=100;
  double req,a,b,c,d,e,f,kmix,keqgp,keqs,r,s,t,u,v;

  //Gap Gas Conductance  

  req=r1+r2; // Ross & stoute
  a=C*req;
  b=a+geq;

  //kmix from Saksena & Saxena 

  c=phi12*(He/Xe);
  d=phi21*(Xe/He);
  e=kXe/(1+c);
  f=kHe/(1+d);
  kmix=e+f;
  keqgp=kmix/b;

  /*
  cout<<"a="<<a<<"\n";
  cout<<"b="<<b<<"\n";
  cout<<"c="<<c<<"\n";
  cout<<"d="<<d<<"\n";
  cout<<"e="<<e<<"\n";
  cout<<"f="<<f<<"\n";
  cout<<"kmix="<<kmix<<"\n";
  cout<<"keqgp="<<keqgp<<"\n";
  */
  
  //Gap Solid Conductance

  r=((r1*r1)+(r2*r2));
  s=0.5*r;
  t=sqrt(s);
  u=sqrt(t);
  v=a0*u*H;
  keqs=((km*P)/v);

  /*
  cout<<"r="<<r<<"\n";
  cout<<"s="<<s<<"\n";
  cout<<"t="<<t<<"\n";
  cout<<"u="<<u<<"\n";
  cout<<"v="<<v<<"\n";
  cout<<"keqs="<<keqs<<"\n";
  */

  // Equivqlent Conductance

  k=keqs+keqgp;
  cout<<"Gap Conductivity (W cm-1 deg-Celsius) is="<<k<<"\n";

  // Clad inner Temperature

  const double LHR=502;
  const double pi=3.14159;
  const double w=0.6100;
  float a1,a2,a3,f1;
  a1=2*pi*w*k;
  a2=LHR/a1;
  cout<<"Enter fuel surface Temperature (in deg-Celsius) : ";
  cin>>f1;
  a3=f1-a2;
  cout<<"Clad inner Temperature is= "<<a3<<"\n";

  return 0;
}
