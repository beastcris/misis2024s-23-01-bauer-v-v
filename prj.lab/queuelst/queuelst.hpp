
#ifndef QUEUELST_HPP
#define QUEUELST_HPP
#include <Complex/Complex.hpp>
#include <iosfwd>

class QueueLst {

public:
  [[nodiscard]] QueueLst() = default;

  [[nodiscard]] QueueLst(const QueueLst& rhs);

  ~QueueLst();

  [[nodiscard]] QueueLst& operator=(const QueueLst& rhs);

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& rhs);

  [[nodiscard]] Complex& Top();

  [[nodiscard]] const Complex& Top() const;

  void Clear() noexcept;
private:
  struct Node {
    Node() = default;
    Node(Complex& rhs) :data_(rhs) {};
    ~Node() = default;

    Complex data_ = { 0,0 };
    Node* next = nullptr;
  };

  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};
#endif 

