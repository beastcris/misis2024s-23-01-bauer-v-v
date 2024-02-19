
#ifndef STACKARR_HPP
#define STACKARR_HPP
#include <Complex/Complex.hpp>


class StackArr{
 
public:
  [[nodiscard]] StackArr() ;

  [[nodiscard]] StackArr(const StackArr& rhs);

  ~StackArr();

  [[nodiscard]] StackArr& operator=(const StackArr& rhs) ;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& rhs);

  [[nodiscard]] Complex& Top();

  [[nodiscard]] const Complex& Top() const;

  void Clear() noexcept;
private:
  std::ptrdiff_t capacity_ = 1000;
  Complex* ptr = nullptr;
  std::ptrdiff_t top_ = 0;

};
#endif 

