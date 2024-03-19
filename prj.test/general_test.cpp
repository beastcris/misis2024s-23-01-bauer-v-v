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
  
  int v = 5;
  for (int i = 0; i < 10; ++i) {
    int&& tmp = v + 5;

    std::cout << i << ' ' << tmp << '\n';
  }
}