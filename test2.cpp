#include <iostream>
#include <utility>

std::pair<int, int> getFraction(int a[], int size)
{
   int n = 1;
   int d = a[size-1];
   for(int i = size - 2; i >= 0; i--)
   {
      int nextd = d*a[i] + n;
      n = d;
      d = nextd;
   }
   return std::make_pair(d, n);
}

int main()
{
   int a[] = {1, 2, 3, 4};
   int size = sizeof(a)/sizeof(a[0]);
   std::pair<int, int> f = getFraction(a, size);
   std::cout
      << "Numerator: " << f.first
      << ", Denominator: " << f.second << std::endl;
}
