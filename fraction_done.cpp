#include <iostream>
using namespace std;

int main ()
{
  float a,fr;
cout << "input a" << ("\n");
cin >> a;
if (a < 1400){fr = 0.05;
    cout << "result is - " << fr << ("\n");
    }else if (a <= 1500 ){ fr = 0.10;
        cout << "result is - " << fr << ("\n");
     }  else if (a <= 1600 ){ fr = 0.20;
        cout << "result is - " << fr << ("\n");
      }     else if (a <= 1700 ){ fr = 0.40;
        cout << "result is - " << fr << ("\n");
       }        else if (a <= 1800 ) { fr = 0.60;
        cout << "result is - " << fr << ("\n");
        }           else if (a <= 2000) { fr = 0.80;
        cout << "result is - " << fr << ("\n");
         }              else if (2000 <= a ) { fr = 0.98;
        cout << "result is - " << fr << ("\n");
                       }
          
}
