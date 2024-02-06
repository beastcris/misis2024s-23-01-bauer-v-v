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

    char sym;
    std::cin >> sym;

    std::string s;
    std::cin >> s;

    if (sym == 'g') {
      std::cout << 0 << '\n';
      continue;
    }

    int mx = -1;
    bool found = false;
    int fstIn = -1;
    int pos = -1;
    for (int i = 0; i < n; ++i) {
      if (!found && s[i] == sym) {
        pos = i;
        found = true;
      }
      else if (s[i] == 'g') {
        if (pos != -1) {
          mx = std::max(mx, i - pos);
        }
        
        if (fstIn == -1) {
          fstIn = i;
        }
        pos = -1;
        found = false;
      }
    }

    if (pos != -1) {
      mx = std::max(mx, n - pos + fstIn);
    }

    std::cout << mx << '\n';
  }
}
