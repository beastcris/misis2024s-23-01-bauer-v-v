#include <iostream>

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
  

  const int a = 10;
  const int& r = a;
  const_cast<int&> (r) = 4;

  std::cout << a;
}