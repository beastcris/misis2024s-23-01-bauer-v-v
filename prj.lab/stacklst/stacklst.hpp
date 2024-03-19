#ifndef STACKLST_HPP
#define STACKLST_HPP

#include <iosfwd>
#include <Complex/Complex.hpp>

class StackLst {
public:
  [[nodiscard]] StackLst() = default;

  [[nodiscard]] StackLst(const StackLst& rhs);
  StackLst(StackLst&& rhs) noexcept;

  ~StackLst();

  [[nodiscard]] StackLst& operator=(const StackLst& rhs);
  StackLst& operator=(StackLst&& rhs) noexcept;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& rhs);

  [[nodiscard]] Complex& Top();

  [[nodiscard]] const Complex& Top() const;

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
