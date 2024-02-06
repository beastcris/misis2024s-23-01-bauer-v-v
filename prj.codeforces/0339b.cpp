#include <iostream>
#include <vector>
#include <string>
#include <cmath>


int main() {
  int n = 0;
  int m = 0;
  int last = 1;
  int current = 0;
  long long time = 0;

  std::cin >> n >> m;
  std::vector <int> deals;
  for (int i = m; i > 0; --i) {
    std::cin >> current;
    if (current >= last) {
      time += current - last;
    }
    else {
      time += n - abs(current - last);
    }
    last = current;
  }
  std::cout << time;
}

