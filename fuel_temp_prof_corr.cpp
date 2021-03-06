#include <iostream>
#include <cmath>
#include <fstream>
#include<cstdlib>
#include<iomanip>
#include<string>

using namespace std;
int main ()
{
cout<<setfill('*')<<setw(80)<<"*"<<endl;	
cout<<"*"<<setfill(' ')<<setw(80)<<"*"<<endl;	
cout<<"*"<<setfill(' ')<<setw(80)<<"*"<<endl;	
cout<<"*"<<setfill(' ')<<setw(80)<<"*"<<endl;	
cout<<"*"<<setfill(' ')<<setw(45)<<"Fuel_Temp ; TAPS-3&4"<<setfill(' ')<<setw(35)<<"*"<<endl;	
cout<<"*"<<setfill(' ')<<setw(50)<<"Alok Jha ; alokjha@npcil.co.in"<<setfill(' ')<<setw(30)<<"*"<<endl;	
cout<<"*"<<setfill(' ')<<setw(52)<<"NUCLEAR POWER CORPORATION OF INDIA"<<setfill(' ')<<setw(28)<<"*"<<endl;	
cout<<"*"<<setfill(' ')<<setw(80)<<"*"<<endl;	
cout<<"*"<<setfill(' ')<<setw(80)<<"*"<<endl;	
cout<<"*"<<setfill(' ')<<setw(80)<<"*"<<endl;	
cout<<setfill('*')<<setw(80)<<"*"<<endl;	

/*
  ofstream outputFile;
  outputFile.open("Fuel_Cent_Temp_corr.txt");
*/  

/// Option to Write user defined Output Filename /////

  ofstream outputFile;
  string filename;
  cout<<"\n Enter a file name : ";
  getline (cin, filename);
  filename += ".txt";
  outputFile.open( filename.c_str() );

outputFile<<setfill('*')<<setw(80)<<"*"<<endl;	
outputFile<<"*"<<setfill(' ')<<setw(80)<<"*"<<endl;	
outputFile<<"*"<<setfill(' ')<<setw(80)<<"*"<<endl;	
outputFile<<"*"<<setfill(' ')<<setw(80)<<"*"<<endl;	
outputFile<<"*"<<setfill(' ')<<setw(45)<<"Fuel_Temp ; TAPS-3&4"<<setfill(' ')<<setw(35)<<"*"<<endl;	
outputFile<<"*"<<setfill(' ')<<setw(50)<<"Alok Jha ; alokjha@npcil.co.in"<<setfill(' ')<<setw(30)<<"*"<<endl;
outputFile<<"*"<<setfill(' ')<<setw(52)<<"NUCLEAR POWER CORPORATION OF INDIA"<<setfill(' ')<<setw(28)<<"*"<<endl;
outputFile<<"*"<<setfill(' ')<<setw(80)<<"*"<<endl;	
outputFile<<"*"<<setfill(' ')<<setw(80)<<"*"<<endl;	
outputFile<<"*"<<setfill(' ')<<setw(80)<<"*"<<endl;	
outputFile<<setfill('*')<<setw(80)<<"*"<<endl;	

/// Declaration of Input //// 

            float D = 0.95,t = 1000, LHR,cool,cool_act,ch_pow,bun_pow;
            string radius, temperature;
            const double rad1 = 0.00,rad2 = 0.6100,pi = 3.1415926;

    cout<<"\n Input Coolant Flow Rate (in Kg/Sec):";
    cin>>cool;
    cout<<"\n Input actual Coolant Temperature (in Deg-Celsius):";
    cin>>cool_act;
    cout<<"\n Input Channel Power (in Kw):";
    cin>>ch_pow;

    
    
//// Linear Heat Rating Calculation
	      
  float  Qw , Nom ;
  const double in_len = 49.53 , conv_eff = 0.95 , num = 37 , N = 12;
  Qw = conv_eff * ch_pow * 1000;
  Nom = in_len * num * N;
  LHR = Qw/Nom;
//cout << LHR << "\n";


int user ;
bool cal = true ;
while (cal != false) {

//string roz = "1. Rozon-correlation" ;
//string ite = "2. Iteration for temperature calculation" ;
cout << "Please select option for Fuel Temperature calculation: " << endl ;
cout << "\n 1. Rozon-correlation" << endl ;
cout << "\n 2. Iteration for temperature calculation" << endl ;
cout << "\n 3. Manual for Instruction" << endl ;
cout << "\n 4. Contact Author of code" << endl ;
cout << "\n 5. Exit" << endl ;

cout << "Make selection and press return: " << endl ;
cin >> user ;

switch (user)
{
  case 1:  
    cout << "\n Calculation of Temperature by Rozon Correlation: " ;
    cout << "#####################################" << endl ;
//// Rozon Correlation
cout << "\n Input Bundle Power in KW: " ;
cin >> bun_pow ;
const double roz1 = 0.476 , roz2 = 2.267e-4 ;
float rozT = cool_act + 273.15 , fu_t ;
fu_t = rozT + (roz1*bun_pow) + (roz2*bun_pow*bun_pow) ;

//// Calculation of conductivity coefficient of Gap ////
    
    const double geq=10e-4; 				///He
    const double Const=5.0;					/// Design_data
    //const double Const=2.5;
    const double phixehe=0.3843;    		/// von Ubisch
    const double phihexe=3.4284;			/// von Ubisch
    const double He=0.90;					/// he-frac
    const double Xe=0.10;					/// xe-frac
    const double LXe=10.4e-5;
    const double LHe=252.4e-5;
    const double km=0.075;					/// Ross_Stoute
    const double a0=0.5;					/// Ross_Stoute
    const double r1=7.31e-4;				/// Design_data
    const double r2=7.31e-4;				/// Design_data
    //const double r1=2.3e-4;					/// Ross_Stoute - zr
    //const double r2=2.3e-5;					/// Ross_Stoute - uo2
    const double H=6.9e3;					/// Ross_Stoute - mohr
    const double P=100;					    /// sphwr - eq -10mpa
   
    double a1roz,c1roz,d1roz,e1roz,f1roz,kmixroz,keqgproz,keqsroz,ktotroz;
    
    a1roz = (Const*(r1+r2))+geq;   // Ross & Stoute
  
//// Saksena & Saxena 

    c1roz = phixehe*(He/Xe);
    d1roz = phihexe*(Xe/He);
    e1roz = LXe/(1.0+c1roz);
    f1roz = LHe/(1.0+d1roz);
    kmixroz = e1roz+f1roz;
    keqgproz = kmixroz/a1roz;

///// Gap Solid Conductance - Ross & Stoute
    
    double t1roz,v1roz,r3roz,r4roz;
    
    r3roz = pow(r1,2)+pow (r2,2);
    r4roz = 0.5*r3roz;
    t1roz = pow (r4roz , 0.25);
    v1roz = a0*t1roz*H;
    keqsroz = ((km*P)/v1roz);
 
    ktotroz = keqsroz+keqgproz;
//cout << ktot << "\n";

///// Temperature drop across Gap

    const double gap_thick = 0.0025;
    double gapdroz,gap_diaroz;
    float aa1roz,aa2roz,aa3roz;
    
    gap_diaroz = rad2+gap_thick;
    for ( gapdroz = rad2 ; gapdroz <= gap_diaroz ; gapdroz = gapdroz+0.0001)
      {
aa1roz = 2*pi*gapdroz*ktotroz;
aa2roz = LHR/aa1roz;
aa3roz = fu_t-aa2roz;
//cout << aa3 << "\n";
//outputFile << gapd << "\t\t";
//outputFile << aa3 << "\n";
      }

/// Calculation of conductivity coefficient of Zircalloy ///

    double ee2roz,ff2roz,gg2roz,tKroz,zirconkroz;
    const double z1 = 7.51 , z2 = 0.029 , z3 = 1.45e-5 , z4 = 7.67e-9;
    
    tKroz  = aa3roz+273.15;
    ee2roz = z2*tKroz;
    ff2roz = z3* pow (tKroz,2);
    gg2roz = z4* pow (tKroz,3);
    zirconkroz = z1+ee2roz-ff2roz+gg2roz;
    
/// Fuel Pencil Surface Temperature

    const double cladt = 0.044;
    double aaaa1roz,aaaa2roz,aaaa3roz,aaaa4roz;
    float sheath_thickroz;
    sheath_thickroz = gap_diaroz+cladt;
    double cladrroz;
    for ( cladrroz = gap_diaroz ; cladrroz <= sheath_thickroz ; cladrroz = cladrroz+0.0001)
      {
aaaa1roz=LHR*cladt;
aaaa2roz=2*pi*cladrroz*(zirconkroz/100);
aaaa3roz=aaaa1roz/aaaa2roz;
aaaa4roz=aa3roz-aaaa3roz;
//cout << aaaa4 << "\n";
//outputFile << cladr << "\t\t";
//outputFile << aaaa4 << "\n";
      }
  
//// Coolant Conductivity calculation////
  
    const double mu=93.6e-6;
    const double cond=0.595;
    const double cp=5.518;
    const double coolant_rad = 6.5; 
    float eqcon0roz, eqcon1roz, eqcon2roz, eqcon3roz, eqcon4roz, eqcon5roz , eqcon6roz, eqcon7roz , temp1roz, temp2roz;
    
    eqcon0roz = (2.0/3.0);
    eqcon1roz = (cond/(cp*mu));
    eqcon2roz = pow (eqcon1roz , eqcon0roz);
    eqcon3roz = 0.023*cp*cool*eqcon2roz;
    eqcon4roz = (coolant_rad*cool)/mu;
    eqcon5roz = -0.2;
    eqcon6roz = pow (eqcon4roz , eqcon5roz);
    eqcon7roz = eqcon3roz*eqcon6roz;
    
 ////Coolant Temperature calculation

for (float Rcoroz = sheath_thickroz ; Rcoroz < coolant_rad ; Rcoroz = Rcoroz+0.01)
{
temp1roz = LHR/(2*pi*Rcoroz*eqcon7roz);
temp2roz = aaaa4roz - temp1roz;
//cout << temp2 << "\n";
//outputFile << Rco << "\t\t";
//outputFile << temp2 << "\n";
}
///////////////////////////////////////////Termination of Rozon - correlation /////////////////////////////////////////////

break ;
case 2 :
    cout << "\n Calculation of Temperature by Iteration: " ;
    cout << "####################################" << endl ;

  
  
  //// Calculation of fuel conductivity ////

   
 ITER :	      
    float a,b,c,d,e,f,g,beta,eta;
    const double B1=40.4 , B2=464 , B3=1.216e-4 , B4=1.867e-3 , B5=0.0191 ;
    if (0<t && 2840>t){
      if(t<1650){
beta = 2.58-(0.58E-3*t);
eta = (1-(beta*(1.0-D)))/(1-(beta*(1.0-0.95)));
a = B1/(B2+t);
b = exp(B4*t);
c = B3*b;
d = eta*(a+c);
e = (8*pi*d);
f = (LHR/e);
g = (t-f);
//cout<< g << "\n";
}
      if(1650<t){ 
beta = 2.58-(0.58E-3*t);
eta = (1-(beta*(1.0-D)))/(1-(beta*(1.0-0.95)));
a = B1/(B2+t);
b = exp(B4*t);
c = B3*b;
d = eta*(B5+c);
e = (8*pi*d);
f = (LHR/e);
g = (t-f);
//cout<< g << "\n";
     }
    }
    else{
      cout<<"Fuel temeprature outside calculation range""\n";
    }
    
//// Calculation of conductivity coefficient of Gap ////
    
    const double geq=10e-4; 				///He
    const double Const=5.0;					/// Design_data
    //const double Const=2.5;
    const double phixehe=0.3843;    		/// von Ubisch
    const double phihexe=3.4284;			/// von Ubisch
    const double He=0.90;					/// he-frac
    const double Xe=0.10;					/// xe-frac
    const double LXe=10.4e-5;
    const double LHe=252.4e-5;
    const double km=0.075;					/// Ross_Stoute
    const double a0=0.5;					/// Ross_Stoute
    const double r1=7.31e-4;				/// Design_data
    const double r2=7.31e-4;				/// Design_data
    //const double r1=2.3e-4;					/// Ross_Stoute - zr
    //const double r2=2.3e-5;					/// Ross_Stoute - uo2
    const double H=6.9e3;					/// Ross_Stoute - mohr
    const double P=100;					    /// sphwr - eq -10mpa
   
  double a1,kmix,keqgp,keqs,ktot;
  double c1,d1,e1,f1;
  
  a1 = (Const*(r1+r2))+geq;   // Ross & Stoute
  
//// Saksena & Saxena 

    c1 = phixehe*(He/Xe);
    d1 = phihexe*(Xe/He);
    e1 = LXe/(1.0+c1);
    f1 = LHe/(1.0+d1);
    kmix = e1+f1;
    keqgp = kmix/a1;

///// Gap Solid Conductance - Ross & Stoute
    
    double t1,v1,r3,r4;
    
    r3 = pow(r1,2)+pow (r2,2);
    r4 = 0.5*r3;
    t1 = pow (r4 , 0.25);
    v1 = a0*t1*H;
    keqs = ((km*P)/v1);
 
    ktot = keqs+keqgp;
//cout << ktot << "\n";

///// Temperature drop across Gap

//    const double gap_thick = 0.0025;
    double gapd,gap_dia;
    float aa1,aa2,aa3;
    
    gap_dia = rad2+gap_thick;
    for ( gapd = rad2 ; gapd <= gap_dia ; gapd = gapd+0.0001)
      {
aa1 = 2*pi*gapd*ktot;
aa2 = LHR/aa1;
aa3 = g-aa2;
//cout << aa3 << "\n";
//outputFile << gapd << "\t\t";
//outputFile << aa3 << "\n";
      }

/// Calculation of conductivity coefficient of Zircalloy ///

    double ee2,ff2,gg2,tK,zirconk;
    const double z1 = 7.51 , z2 = 0.029 , z3 = 1.45e-5 , z4 = 7.67e-9;
    
tK  = aa3+273.15;
    ee2 = z2*tK;
    ff2 = z3* pow (tK,2);
    gg2 = z4* pow (tK,3);
    zirconk = z1+ee2-ff2+gg2;
    
/// Fuel Pencil Surface Temperature

    const double cladt = 0.044;
    double aaaa1,aaaa2,aaaa3,aaaa4;
    float sheath_thick;
    sheath_thick = gap_dia+cladt;
    double cladr;
    for ( cladr = gap_dia ; cladr <= sheath_thick ; cladr = cladr+0.0001)
      {
aaaa1=LHR*cladt;
aaaa2=2*pi*cladr*(zirconk/100);
aaaa3=aaaa1/aaaa2;
aaaa4=aa3-aaaa3;
//cout << aaaa4 << "\n";
//outputFile << cladr << "\t\t";
//outputFile << aaaa4 << "\n";
      }
  
//// Coolant Conductivity calculation////
  
    const double mu=93.6e-6;
    const double cond=0.595;
    const double cp=5.518;
    const double coolant_rad = 6.5; 

    float eqcon0, eqcon1, eqcon2, eqcon3, eqcon4, eqcon5 , eqcon6, eqcon7 , temp1, temp2;
    
    eqcon0 = (2.0/3.0);
    eqcon1 = (cond/(cp*mu));
    eqcon2 = pow (eqcon1 , eqcon0);
    eqcon3 = 0.023*cp*cool*eqcon2;
    eqcon4 = (coolant_rad*cool)/mu;
    eqcon5 = -0.2;
    eqcon6 = pow (eqcon4 , eqcon5);
    eqcon7 = eqcon3*eqcon6;
    
 ////Coolant Temperature calculation

    for (float Rco = sheath_thick ; Rco < coolant_rad ; Rco = Rco+0.01)
    {
temp1 = LHR/(2*pi*Rco*eqcon7);
temp2 = aaaa4 - temp1;
//cout << temp2 << "\n";
//outputFile << Rco << "\t\t";
//outputFile << temp2 << "\n";
}

//// ITER start for Temperature ////
//// ITER start for Temperature ////

if (temp2 > cool_act ) 
{
t = t-1;
goto ITER;
}
else
{
goto ITER2x;
}

//// ITER Stop for Temperature ////
//// ITER Stop for Temperature ////

 ITER2x :	      
    outputFile << "Temp-" << rad1 << "\t\t";
    outputFile << t << "\n";
    float ax,bx,cx,dx,ex,fx,gx,betax,etax;
    //const double B1=40.4 , B2=464 , B3=1.216e-4 , B4=1.867e-3 , B5=0.0191 , pi=3.1415926;
  
    if (0<t && 2840>t){
    if(t<1650){
betax = 2.58-(0.58E-3*t);
etax = (1-(betax*(1.0-D)))/(1-(betax*(1.0-0.95)));
ax = B1/(B2+t);
bx = exp(B4*t);
cx = B3*bx;
dx = etax*(ax+cx);
ex = (8*pi*dx);
fx = (LHR/ex);
gx = (t-fx);
//cout<< g << "\n";
    }
    
if(1650<t){ 
betax = 2.58-(0.58E-3*t);
etax = (1-(beta*(1.0-D)))/(1-(beta*(1.0-0.95)));
ax = B1/(B2+t);
bx = exp(B4*t);
cx = B3*bx;
dx = etax*(B5+cx);
ex = (8*pi*dx);
fx = (LHR/ex);
gx = (t-fx);
//cout<< g << "\n";
      }
    }
    else{
      cout<<"Fuel temeprature outside calculation range""\n";
    }
    
//// Calculation of conductivity coefficient of Gap ////
			    /*
			    const double geq=10e-4; 				///He
			    const double Const=2.5;
			    const double phixehe=0.3843;    		/// von Ubisch
			    const double phihexe=3.4284;			/// von Ubisch
			    const double He=0.90;					/// he-frac
			    const double Xe=0.10;					/// xe-frac
			    const double LXe=10.4e-5;
			    const double LHe=252.4e-5;
			    const double km=0.075;					/// Ross_Stoute
			    const double a0=0.5;					/// Ross_Stoute
			    const double r1=2.3e-4;					/// Ross_Stoute - zr
			    const double r2=2.3e-5;					/// Ross_Stoute - uo2
			    const double H=6.9e3;					/// Ross_Stoute - mohr
			    const double P=100;					    /// sphwr - eq -10mpa
		    	*/
    double a1x,c1x,d1x,e1x,f1x,kmixx,keqgpx,keqsx,ktotx;
    
a1x = (Const*(r1+r2))+geq;   // Ross & Stoute
  
//// Saksena & Saxena 

    c1x = phixehe*(He/Xe);
    d1x = phihexe*(Xe/He);
    e1x = LXe/(1.0+c1x);
    f1x = LHe/(1.0+d1x);
    kmixx = e1x+f1x;
    keqgpx = kmixx/a1x;

///// Gap Solid Conductance - Ross & Stoute
    
    double t1x,v1x,r3x,r4x;
    
    r3x = pow(r1,2)+pow (r2,2);
    r4x = 0.5*r3x;
    t1x = pow (r4x , 0.25);
    v1x = a0*t1x*H;
    keqsx = ((km*P)/v1x);
 
    ktotx = keqsx+keqgpx;
//cout << ktot << "\n";

///// Temperature drop across Gap

    //const double gap_thick = 0.0025;
    double gap_diax;
    float aa1x,aa2x,aa3x;
    gap_diax = rad2+gap_thick;
    
    for ( double gapd = rad2 ; gapd <= gap_diax ; gapd = gapd+0.0001)
      {
aa1x = 2*pi*gapd*ktotx;
aa2x = LHR/aa1x;
aa3x = gx-aa2x;
//cout << aa3 << "\n";
    outputFile << gapd << "\t\t";
    outputFile << aa3x << "\n";
      }

/// Calculation of conductivity coefficient of Zircalloy ///

    double ee2x,ff2x,gg2x,tKx,zirconkx;
    //const double z1 = 7.51 , z2 = 0.029 , z3 = 1.45e-5 , z4 = 7.67e-9;
    
tKx  = aa3x+273.15;
    ee2x = z2*tKx;
    ff2x = z3* pow (tKx,2);
    gg2x = z4* pow (tKx,3);
    zirconkx = z1+ee2x-ff2x+gg2x;
    
/// Fuel Pencil Surface Temperature

//const double cladt = 0.044;
    double aaaa1x,aaaa2x,aaaa3x,aaaa4x;
    float sheath_thickx;
    sheath_thickx = gap_diax+cladt;
    
for ( double cladr = gap_diax ; cladr <= sheath_thickx ; cladr = cladr+0.0001)
      {
aaaa1x = LHR*cladt;
aaaa2x = 2*pi*cladr*(zirconkx/100);
aaaa3x = aaaa1x/aaaa2x;
aaaa4x = aa3x-aaaa3x;
//cout << aaaa4 << "\n";
    outputFile << cladr << "\t\t";
    outputFile << aaaa4x << "\n";
      }
  
//// Coolant Conductivity calculation////
  
    //const double mu=93.6e-6;
    //const double cond=0.595;
    //const double cp=5.518;
    //const double coolant_rad = 6.5; 
    float eqcon0x, eqcon1x, eqcon2x, eqcon3x, eqcon4x, eqcon5x, eqcon6x, eqcon7x, temp1x, temp2x;
    
    eqcon0x = (2.0/3.0);
    eqcon1x = (cond/(cp*mu));
    eqcon2x = pow (eqcon1x , eqcon0x);
    eqcon3x = 0.023*cp*cool*eqcon2x;
    eqcon4x = (coolant_rad*cool)/mu;
    eqcon5x = -0.2;
    eqcon6x = pow (eqcon4x , eqcon5x);
    eqcon7x = eqcon3x*eqcon6x;
    
 ////Coolant Temperature calculation

    for (float Rco = sheath_thick ; Rco < coolant_rad ; Rco = Rco+0.01)
    {
temp1x = LHR/(2*pi*Rco*eqcon7x);
temp2x = aaaa4 - temp1x;
//cout << temp2 << "\n";
outputFile << Rco << "\t\t";
outputFile << temp2x << "\n";
}
break ;
case 3 :
  cout << "Manual  - Hyperlink" << endl ;
  break ;
case 4 :
  cout << "Contact by email - alokjha@npcil.co.in" << endl ;
  break ;
case 5 :
  cout << "Program Terminated. \n" ;
  user = false ;
  break ;
default :
  cout "Make valid choice \n" ;
  cin >> user ;
  break ;
}
outputFile.close();
cout << "Iterations Completed!\n";
cout<< "Done Writing!\n";
return 0;
}
}