#include "bmath.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <set>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

namespace BasarMath {
  //
  double nroot(double number, double root) { return exp(log(number) / root); }

  //
  std::string nroot_exp(int number, int root) {
    int frnum = number;
    int res_int = 1;
    std::multiset<int> fac;
    for (int i = 2; i <= number; i++) {
      while (number % i == 0) {
        number /= i;
        fac.insert(i);
      }
    }
    std::set<int> fin;
    for (auto item : fac) {
      fin.insert(fin.end(), item);
    }
    for (auto elem : fin) {
      int cou = fac.count(elem);
      if (pow(elem, (((cou - (cou % root)) / root))) != 0)
        res_int *= pow(elem, (((cou - (cou % root)) / root)));
    }
    int res_root = (int)frnum / pow(res_int, root);
    if (res_root == 0 || res_root == 1) {
      return to_string(res_int);
    } else if (res_int == 1) {
      return "(" + to_string(root) + "k)" + to_string(res_root);
    } else {
      return to_string(res_int) + "(" + to_string(root) + "k)" +
             to_string(res_root);
    }
  }

  //
  std::string factorial(int n)
  {
      std::string str;
      int res[10000];
      res[0] = 1;
      int res_size = 1;
      for (int x=2; x<=n; x++){
          int carry = 0;
          for (int i=0; i<res_size; i++)
          {
              int prod = res[i] * x + carry;
              res[i] = prod % 10;
              carry  = prod/10;
          }
          while (carry)
          {
              res[res_size] = carry%10;
              carry = carry/10;
              res_size++;
          }
        }
      for (int i=res_size-1; i>=0; i--)
          str.append(to_string(res[i]));
      return str;
  }

}
