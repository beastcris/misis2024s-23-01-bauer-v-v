#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main() {

  long long a = 0;
  long long c = 0;

  std::cin >> a >> c;
  long long end = 0;
  long long i = 1;

  while (a != 0 and c != 0) {
    long long low = a % 3;
    long long high = c % 3;
    a /= 3;
    c /= 3;
    end += ((3 + (high - low)) % 3) * i;
    i *= 3;
  }
  while (a!=0 or c!=0) { 
    if (c != 0 and a==0) {
      end += i * (c % 3);
      c /= 3; 
    }
    else if (c==0 and a!=0) {
      end += i * ((3 - a % 3) %3);
      a /= 3;
    }
    i *= 3;
  }

  std::cout << end;
}
