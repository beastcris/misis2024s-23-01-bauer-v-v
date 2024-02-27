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
  int* a = new int[6];
  for (int i = 0; i < 6 ; ++i) {
    a[i] = i;
  }
  int* b= new int[6];

  std::copy(a,a+2 , b);
  std::copy(a + 2, a + 4, b + 2);

  for (std::ptrdiff_t i = 0; i < 6; ++i) {
    std::cout << *(b + i);
  }
}