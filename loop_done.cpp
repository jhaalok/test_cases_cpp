// i/o example

#include <iostream>
using namespace std;

int main ()
{
  float a ,b =5,c =5,d ,e =5,f =5,g;
  float h;
cout << "input h" << ("\n");
cin >> h;
REC :
a=b*b+c;
d=e*f;
g=a+d;

if (g < h) {
    b=b+1;
    goto REC;
           }
else {
    cout << "result is - " << b << ("\n");
     }
     return 0;
}

URL - cpp.sh/9lzv3