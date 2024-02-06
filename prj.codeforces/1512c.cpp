#include <iostream>
#include <string>


int main() {
  int t = 0;
  std::cin >> t;

  for (t; t > 0; --t) {
    int a = 0;
    int b = 0;
    std::cin >> b >> a;

    std::string s;
    std::cin >> s;

    bool flag = true;
    int cnt = 0;
    int n = a + b;
    for (int i = 0; i < n / 2; ++i) {
      
      if (s[i] == '1') {
        if (s[n - 1 - i] != '1' && s[n - 1 - i] != '?') {
          std::cout << -1 << std::endl;
          cnt = 0;
          flag = false;
          break;
        }
        a -= 2;
        s[n - 1 - i] = '1';
      }
      else if (s[i] == '0') {
        if (s[n - 1 - i] != '0' && s[n - 1 - i] != '?') {
          std::cout << -1 << std::endl;
          flag = false;
          cnt = 0;
          break;
        }
        b -= 2;
        s[n - 1 - i] = '0';
      }
      else {
        if (s[n - 1 - i] == '1' ) {
          a -= 2;
          s[i] = '1';
        }
        else if (s[n - 1 - i] == '0') {
          b -= 2;
          s[i] = '0';
        }
        else {
          ++cnt;
        }
      }
      if (a < 0 || b < 0) {
        std::cout << -1 << std::endl;
        flag = false;
        cnt = 0;
        break;
      }
    }

    int i = 0;
    while (cnt != 0 && i<n/2) {
      if (s[i] == '?' && s[n - 1 - i] == '?') {
        if (a >= 2) {
          a -= 2;
          s[i] = '1';
          s[n - 1 - i] = '1';
        }
        else if (b>=2) {
          b -= 2;
          s[i] = '0';
          s[n - 1 - i] = '0';
        }
        else {
          flag = false;
          std::cout << -1 << std::endl;
          break;
        }
        --cnt;
      }
      ++i;
    }

    
    if (n % 2 == 1 and flag) {
      if (s[n / 2] == '?') {
        if (a == 1) {
          s[n / 2] = '1';
        }
        else {
          s[n / 2] = '0';
        }
      }
      else if (s[n / 2] == '1') {
        if (a != 1) {
          std::cout << -1 << std::endl;
          continue;
        }
      }
      else {
        if (b != 1) {
          std::cout << -1 << std::endl;
          continue;
        }
      }
    }

    if (flag) {
      std::cout << s << std::endl;
    }
  }
  
}
