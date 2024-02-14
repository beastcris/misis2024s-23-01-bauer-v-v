#ifndef STACKLST_HPP
#define STACKLST_HPP

#include <iosfwd>
#include <Complex/Complex.hpp>

class StackLst {
public:
  StackLst() = default;
  StackLst(const StackLst& rhs);
  ~StackLst();
  StackLst& operator=(const StackLst& rhs);

  [[nodiscard]] bool IsEmpty() const noexcept;
  void Push(Complex& rhs);
  void Pop() noexcept;
  [[nodiscard]] const Complex& Top() const;
  [[nodiscard]] Complex& Top();
  
  void Clear() noexcept;
private:

  struct Node{
    Node() = default;
    Node(Complex& rhs):data_(rhs) {};
    ~Node() = default;

    Complex data_ = { 0,0 };
    Node* next = nullptr;
  };
  
  Node* head_ = nullptr;
};

#endif // !STACKLST_HPP
