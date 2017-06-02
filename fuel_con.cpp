// Calculation of Fuel (Uranium Oxide) conductivity coefficient (kf)

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int main (void)
{
 
   ofstream outputFile;
   outputFile.open("Fuel_Con.txt");

  double t,D;
  const double k1=40.4;
  const double k2=464;
  const double k3=1.216e-4;
  const double k4=1.867e-3;
  const double k5=0.0191;
  const double k6=0.58e-3;
  const double pi=3.1415926;
  const double LHR=502;
  float a,b,c,d,e,f,g,h,i,j,k,l,m,B;
  cout<<"\n Input fuel temperature (in Deg-Celsius):";
  cin>>t;
  cout<<"\n Input fuel density (in percentage fraction):";
  cin>>D;
  //  cout<<"\n Input Linear Heat Rating of the Fuel (in W cm-1):";
  //  cin>>LHR;
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

  if (0<t && 2940>t){
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

  	outputFile << m << "\n";
	//cout<<"Temperature at fuel pellet surface is= "<<m<<"\n";

    outputFile.close();
	cout << "Iterations Completed!\n";
	cout<< "Done Writing!\n";
	return 0;
}
  
    
