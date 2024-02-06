#include <iostream>
#include <vector>
#include <string>
#include <cmath>


int main() {
  int t = 0;
  std::cin >> t;
  for (t; t > 0; --t) {

    int Cnt = 0;
    for (int tmp = 0; tmp < 10; ++tmp) {
      std::string s;
      std::cin >> s;

      for (int i = 0; i < 10; ++i) {
        if (s[i] == 'X') {
          Cnt += std::min(std::min(9 - i, i) + 1, std::min(9 - tmp, tmp) + 1);
        }
      }
    }
    std::cout << Cnt << "\n";
  }
}
