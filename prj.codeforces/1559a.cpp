#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main() {
  
  int t = 0;
  std::cin >> t;

  while (t) {
    int n = 0;
    std::vector <int> nums;
    std::cin >> n;

    long long mn = 10e15;
    int last = 0;
    for (int i = 0; i < n; ++i) {
      int tmp = 0;
      std::cin >> tmp;
      if (i == 0) {
        last = tmp;
        continue;
      }
      last = tmp&last;
    }


    std::cout << last << "\n";
    --t;
  }
}

