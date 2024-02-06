#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main() {
  std::string alph = "abcdefghijklmnopqrstuvwxyz";

  std::string word;
  std::cin >> word;

  int mark = 0;
  int cnt = 0;
  for (int i = 0; i < word.length(); ++i) {
    int next = alph.find_first_of(word[i]);
    cnt += std::min(abs(next - mark), 26 - abs(mark - next));
    mark = next;
  }

  std::cout << cnt;
}
