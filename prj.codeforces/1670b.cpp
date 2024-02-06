#include <iostream>
#include <vector>
#include <string>

int main() {
  int t = 0;
  std::cin >> t;
  for (t; t > 0; --t) {
    int n = 0;
    std::vector <int> check (125);

    std::cin >> n;
    std::string s;
    std::cin >> s;

    int k = 0;
    std::cin >> k;
    char c;
    for (int i = k; i > 0; --i) {
      std::cin >> c;
      check[c] = 1;
    }

    int last = 0;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      if (check[int(s[i])] == 1) {
        mx = std::max(mx, i - last);
        last = i;
      }
    }

    std::cout << mx << std::endl;
  }
}
