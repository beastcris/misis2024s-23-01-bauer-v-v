#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main() {
  int t = 0;
  std::cin >> t;

  while (t--) {
    int n = 0;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    bool flag = true;
    int Rcnt = 0;
    int Bcnt = 0;
    char lst = 'W';
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'W') {
        if (lst == 'W') {
          continue;
        }
        else {
          if (Rcnt != 1 || Bcnt != 1) {
            std::cout << "NO" << '\n';
            flag = false;
            break;
          }
          Rcnt = 0;
          Bcnt = 0;
        }
      }
      else if (s[i] == 'B') {
        Bcnt = 1;
      }
      else {
        Rcnt = 1;
      }
      lst = s[i];
    }

    if (lst!='W' && (Rcnt != 1 || Bcnt != 1) && flag) {
      std::cout << "NO" << '\n';
      flag = false;
    }
    if (flag) {
      std::cout << "YES" << '\n';
    }
  }
}
