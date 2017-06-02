// Calculation of conductivity coefficient (k) of Zircalloy

#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
  double e,f,g,j,k,t,l;
  const double a=7.51;
  const double b=0.029;
  const double c=1.45e-5;
  const double d=7.67e-9;

  // Zircalloy Conductivity

  cout<<"Enter Zircalloy Temperature (in Deg-Celsius):";
  cin>>l;
  t=l+273.15;
  e=b*t;
  f=c*(t*t);
  g=d*(t*t*t);
  k=a+e-f+g;
  
  /*
  cout<<"a="<<a<<"\n";
  cout<<"e="<<e<<"\n";
  cout<<"f="<<f<<"\n";
  cout<<"g="<<g<<"\n";
  */

  cout<<"zircally_conductivity is="<<k<<"\n";

  // Fuel Pencil Surface Temperature

  double a1,a2,a3,a4;
  const double LHR=502;
  const double cladt=0.0415;
  const double cladr=0.6515;
  const double pi=3.14159;
  
  a1=LHR*cladt;
  a2=2*pi*cladr*(k/100);
  a3=a1/a2;
  a4=l-a3;
  cout<<"Fuel Pencil Surface Temperature is="<<a4<<"\n";
 
  return 0;
}
