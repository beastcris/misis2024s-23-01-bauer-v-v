#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main() {
  int n = 0;
  int k = 0;

  int mx = -1;

  std::cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int tmp = 0;
    std::cin >> tmp;
    if (k % tmp == 0) {
      mx = std::max(mx, tmp);
    }
  }
  
  std::cout << k / mx;
}
