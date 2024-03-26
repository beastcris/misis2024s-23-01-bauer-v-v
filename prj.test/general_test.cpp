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
  
  std::vector<int> a = { 1,1,1 };
  std::vector<int> b = { 2,1 };
  std::cout << (a == b) << '\n';

  int32_t i = 2000000000;
            /*4294967295*/
  std::cout << i;
}