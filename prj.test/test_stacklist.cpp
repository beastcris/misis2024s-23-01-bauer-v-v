

#include <stacklst/stacklst.hpp>
#include <iostream>

int main() {
  StackLst a;

  Complex first_complex = { 1.0, 1.1 };
  Complex second_complex = { 2.5, 7.1 };
  Complex third_complex = { 2.0, 0.0 };

  
  StackLst b;
  a.Push(first_complex);
  a.Push(second_complex);
  b = a;
  std::cout << b.IsEmpty();
  std::cout << b.Top();

  StackLst c(b);
  std::cout << c.Top();
  c.Pop();
  std::cout << c.Top();
}