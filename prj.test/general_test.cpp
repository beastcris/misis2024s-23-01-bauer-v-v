#include <iostream>
#include <vector>

enum class KeyWord: int {
  kAsm,
  kAuto,
  kbreak
};

enum A {
  F,
  C
};

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  
  
  if (c < 0) {
    std::cout << "NO SOLUTION";
  }
  else if (a == 0) {
    if (b == c * c) {
      std::cout << "MANY SOLUTIONS";
    }
    else {
      std::cout << "NO SOLUTIONS";
    }
  }
  else {
    if ((c * c - b) % a == 0) {
      std::cout << (c * c - b) / a;
    }
    else {
      std::cout << "NO SOLUTIONS";
    }
  }
}