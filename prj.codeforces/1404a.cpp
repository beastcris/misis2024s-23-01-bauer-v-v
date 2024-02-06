#include <iostream>
#include <vector>
#include <string>
#include <array>

int main() {
  
  int t = 0;
  std::cin >> t;
  for (t; t > 0; --t) {
    int n = 0;
    int k = 0;
    bool flag = true;
    
    std::cin >> n >> k;
    int OneCnt = 0;
    int ZeroCnt = 0;

    std::vector<int> Remainders(k);
    std::string s;
    std::cin >> s;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '1') {
        if (Remainders[i % k] != 2) {
          Remainders[i % k] = 1;
        }
        else {
          flag = false;
          break;
        }
      }
      else if (s[i] == '0') {
        if (Remainders[i % k] != 1) {
          Remainders[i % k] = 2;
        }
        else {
          flag = false;
          break;
        }
      }
      else {
        if (Remainders[i % k] == 2) {
          s[i] = '0';
        }
        else if (Remainders[i % k] == 1) {
          s[i] = '1';
        }
      }
    }
    
    if (flag) {
      for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '?') {
          if (Remainders[i % k] == 1) {
            s[i] = '1';
          }
          else if (Remainders[i % k] == 2) {
            s[i] = '0';
          }
        }
      }
      for (int i = 0; i < k; ++i) {
        if (s[i] == '0') {
          ZeroCnt++;
        }
        else if (s[i] == '1') {
          ++OneCnt;
        }
      }
      if (abs(ZeroCnt - OneCnt) <= (k - (ZeroCnt + OneCnt))) {
        std::cout << "YES" << "\n";
      }
      else {
        std::cout << "NO" << "\n";
      }
      
    }
    else {
      std::cout << "NO" << "\n";
    }
    
  }
}
