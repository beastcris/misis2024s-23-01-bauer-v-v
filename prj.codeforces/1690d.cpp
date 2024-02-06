#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    int n = 0;
    int k = 0;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    int BlackCnt = 0;
    int mn = 10e6;
    for (int i = 0; i < n; ++i) {
      if (i < k) {
        if (s[i] == 'B') {
          ++BlackCnt;
        }
      }
      else {
        mn = std::min(k - BlackCnt, mn);
        if (s[i - k] == 'B') {
          --BlackCnt;
        }
        if (s[i] == 'B') {
          ++BlackCnt;
        }
      }
    }

    std::cout << std::min(mn, k - BlackCnt) << '\n';
  }
}
