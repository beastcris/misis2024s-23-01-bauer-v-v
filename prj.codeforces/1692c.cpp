#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main() {
  int t = 0;
  std::cin >> t;
  
  
  while (t--) {
    bool flag = true;
    for (int i = 0; i < 8; ++i) {
      std::string tmp;
      std::cin >> tmp;

      if (flag) {
        std::vector <int> pos;
        int cnt = 0;
        for (int j = 1; j < 7; ++j) {
          if (tmp[j] == '.' and tmp[j - 1] == '#' and tmp[j + 1] == '#') {
            std::cout << i + 2 << ' ' << j + 1 << '\n';
            flag = false;
          }
        }
      }
    }
  }
}
