#include <iostream>
#include <vector>
#include <string>
#include <cmath>


int main() {
  int t = 0;
  std::cin >> t;
  for (t; t > 0; --t) {
    int n = 0;
    int k = 0;
    std::cin >> n >> k;


    std::string s;
    std::cin >> s;

    int i = 0;
    int cnt = 0;
    while (i<n) {
      if (s[i] == 'B') {
        cnt += 1;
        i += k;
      }
      else {
        ++i;
      }
    }
    std::cout << cnt << "\n";

  }
}

