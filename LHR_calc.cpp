// i/o example

#include <iostream>
using namespace std;

int main ()
{
  float  Qw , Q , Nom , lin_h_r;
  cout << "Pow_value (Kw): ";
  cin >> Q;
            const double in_len = 49.53 , conv_eff = 0.95 , num = 37 , N = 12;
            Qw = conv_eff * Q * 1000;
            //cout << Qw << endl;
            Nom = in_len * num * N;
            //cout << Nom << endl;
            lin_h_r = Qw/Nom;
            //cout << lin_h_r << endl;
  cout << " Lin_h_r = " << lin_h_r << "\n";
  return 0;
}