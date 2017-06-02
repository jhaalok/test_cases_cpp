// Calculation of Fuel (Uranium Oxide) conductivity coefficient (kf)

#include <iostream>
#include <cmath>
using namespace std;
int main (void)
{
  double t,D;
  const double k1=40.4;
  const double k2=464;
  const double k3=1.216e-4;
  const double k4=1.867e-3;
  const double k5=0.0191;
  const double k6=0.58e-3;
  const double pi=3.1415926;
  float a,b,c,d,e,f,g,h,i,j,k,l,m,B,LHR;
  cout<<"\n Input fuel temperature (in Deg-Celsius):";
  cin>>t;
  cout<<"\n Input fuel density (in percentage fraction):";
  cin>>D;
  cout<<"\n Input Linear Heat Rating of the Fuel (in W cm-1):";
  cin>>LHR;
  B= 2.58-(k6*t);
  a= B*(1-D);
  b= 1-a;
  c= B*(1-0.95);
  d= 1-c;
  e= (b/d);
  f= k1/(k2+t);
  g= exp(k4*t);
  h= k3*g;
    
  //  cout<<"B = "<<B<<"\n";
  //  cout<<"a = "<<a<<"\n";
  //  cout<<"b = "<<b<<"\n";
  //  cout<<"c = "<<c<<"\n";
  //  cout<<"d = "<<d<<"\n";
  //  cout<<"e = "<<e<<"\n";
  //  cout<<"f = "<<f<<"\n";
  //  cout<<"g = "<<g<<"\n";
  //  cout<<"h = "<<h<<"\n";

  if (0<t && 2840>t){
        if(t<1650){
	  i=e*(f+h);
	  k=(8*pi*i);
	  l=(LHR/k);
	  m=(t-l);
	  //	  cout<<"Fuel conductivity (W cm-1 Deg-C-1) is= "<<i<<"\n";
	  //	  cout<<"Temperature at fuel pellet surface is= "<<m<<"\n";
	}
	if(1650<t){ 
	  j=e*(k5+h);
	  k=(8*pi*j);
	  l=(LHR/k);
	  m=(t-l);
	  //	  cout<<"Fuel conductivity (W cm-1 Deg-C-1) is= "<<j<<"\n";
	  //	  cout<<"Temperature at fuel pellet surface is= "<<m<<"\n";
	}
  }
  else{
    cout<<"Fuel temeprature outside calculation range""\n";
  }  

  //  cout<<"Temperature at fuel pellet surface is= "<<m<<"\n";

  //  return 0;
  //}
  
    
// Calculation of conductivity coefficient (k) of Fuel and Zircalloy Gap
/*
#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
*/
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
  double req,a1,b1,c1,d1,e1,f1,kmix,keqgp,keqs,r3,s1,t1,u1,v1,k7;

  //Gap Gas Conductance  

  req=r1+r2; // Ross & stoute
  a1=C*req;
  b1=a1+geq;

  //kmix from Saksena & Saxena 

  c1=phi12*(He/Xe);
  d1=phi21*(Xe/He);
  e1=kXe/(1+c1);
  f1=kHe/(1+d1);
  kmix=e1+f1;
  keqgp=kmix/b1;

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

  r3=((r1*r1)+(r2*r2));
  s1=0.5*r3;
  t1=sqrt(s1);
  u1=sqrt(t1);
  v1=a0*u1*H;
  keqs=((km*P)/v1);

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
  //  cout<<"Gap Conductivity (W cm-1 deg-Celsius) is="<<k<<"\n";

  // Clad inner Temperature

  //  const double LHR=502;
  //  const double pi=3.14159;
  const double w=0.6100;
  float aa1,aa2,aa3,ff1;
  aa1=2*pi*w*k;
  aa2=LHR/aa1;
  //  cout<<"Enter fuel surface Temperature (in deg-Celsius) : ";
  //  cin>>ff1;
  aa3=m-aa2;
  //cout<<"Clad inner Temperature is= "<<aa3<<"\n";

  //  return 0;
  //}


// Calculation of conductivity coefficient (k) of Zircalloy
/*
#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
*/
  double ee2,ff2,gg2,jj2,kk2,tt2,ll2;
  const double aaa=7.51;
  const double bbb=0.029;
  const double ccc=1.45e-5;
  const double ddd=7.67e-9;

  // Zircalloy Conductivity

  //  cout<<"Enter Zircalloy Temperature (in Deg-Celsius):";
  //  cin>>l;
  tt2=aa3+273.15;
  ee2=bbb*tt2;
  ff2=ccc*(tt2*tt2);
  gg2=ddd*(tt2*tt2*tt2);
  k=aaa+ee2-ff2+gg2;
  
  /*
  cout<<"a="<<a<<"\n";
  cout<<"e="<<e<<"\n";
  cout<<"f="<<f<<"\n";
  cout<<"g="<<g<<"\n";
  */

  //  cout<<"zircally_conductivity is="<<k<<"\n";

  // Fuel Pencil Surface Temperature

  double aaaa1,aaaa2,aaaa3,aaaa4;
  //  const double LHR=502;
  const double cladt=0.0415;
  const double cladr=0.6515;
  //  const double pi=3.14159;
  
  aaaa1=LHR*cladt;
  aaaa2=2*pi*cladr*(k/100);
  aaaa3=aaaa1/aaaa2;
  aaaa4=aa3-aaaa3;
  cout<<"Fuel Pencil Surface Temperature is="<<aaaa4<<"\n";
 
  return 0;
}
