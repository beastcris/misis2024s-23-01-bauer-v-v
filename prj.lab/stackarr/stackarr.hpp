
#ifndef STACKARR_HPP
#define STACKARR_HPP
#include <iostream>
#include <Complex/Complex.hpp>

class StackArr{
 
public:
  StackArr();
  StackArr(const StackArr& rhs);
  ~StackArr() noexcept;
  [[nodiscard]] StackArr& operator=(const StackArr& rhs);
  void Push(const Complex& rhs);
  void Pop() noexcept;
  [[nodiscard]] bool IsEmpty() const noexcept;
  [[nodiscard]] Complex& Top();
  [[nodiscard]] const Complex& Top() const;
  
  void Clear() noexcept;
private:
  std::ptrdiff_t capacity_ = 1000;
  Complex* ptr = nullptr;
  std::ptrdiff_t top_ = 0;

};
#endif 

