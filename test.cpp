#include <iostream>
#include "basarlibs/bmath.cpp"
using namespace std;
using namespace BasarMath;

int main(void) {
  int a,b;
  cin >> a >> b;
  cout << nroot_exp(a,b) << " = " << nroot(a,b) << endl;
}
