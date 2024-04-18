
#ifndef QUEUELSTT_HPP
#define QUEUELSTT_HPP
#include <iosfwd>
#include <stdexcept>

template <class T>
class QueueLstT {

public:
  [[nodiscard]] QueueLstT() = default;

  [[nodiscard]] QueueLstT(const QueueLstT<T>& rhs);
  QueueLstT(QueueLstT<T>&& rhs) noexcept;

  ~QueueLstT();

  [[nodiscard]] QueueLstT<T>& operator=(const QueueLstT<T>& rhs);
  QueueLstT<T>& operator=(QueueLstT<T>&& rhs) noexcept;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const T& rhs);

  [[nodiscard]] T& Top();

  [[nodiscard]] const T& Top() const;

  void Clear() noexcept;
private:
  struct Node {
    Node() = default;
    Node(T& rhs) :data_(rhs) {};
    ~Node() = default;

    T data_ = { 0 };
    Node* next = nullptr;
  };

  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};

template<class T>
bool QueueLstT<T>::IsEmpty() const noexcept {
  return (head_ == nullptr);
}

template<class T>
void QueueLstT<T>::Push(const T& rhs) {
  Node* tmp = new Node;
  tmp->data_ = rhs;
  if (tail_ != nullptr) {
    tail_->next = tmp;
    tail_ = tmp;
  }
  else {
    tail_ = tmp;
    head_ = tmp;
  }
  tmp = nullptr;
}

template<class T>
void QueueLstT<T>::Pop() noexcept {
  if (!(this->IsEmpty())) {
    Node* tmp = head_->next;
    delete head_;
    head_ = tmp;
    tmp = nullptr;
    if (head_ == nullptr) {
      tail_ = nullptr;
    }
  }
}

template<class T>
T& QueueLstT<T>::Top() {
  if (head_ == nullptr) {
    throw std::logic_error("Stack is empty");
  }
  return head_->data_;
}

template<class T>
const T& QueueLstT<T>::Top() const {
  if (head_ == nullptr) {
    throw std::logic_error("Stack is empty");
  }
  return head_->data_;
}

template<class T>
void QueueLstT<T>::Clear() noexcept {
  while (head_ != nullptr) {
    this->Pop();
  }
}

template<class T>
QueueLstT<T>::~QueueLstT() {
  this->Clear();
}

template<class T>
QueueLstT<T>::QueueLstT(const QueueLstT<T>& rhs) {
  Node* ptr = rhs.head_;
  Node* last = nullptr;
  while (ptr != nullptr) {
    Node* curr = new Node;
    if (last != nullptr) {
      last->next = curr;
    }
    else {
      head_ = curr;
    }
    curr->data_ = ptr->data_;
    last = curr;
    ptr = ptr->next;

  }
  tail_ = last;
  last = nullptr;
}

template<class T>
QueueLstT<T>::QueueLstT(QueueLstT<T>&& rhs) noexcept
  :head_(rhs.head_)
  , tail_(rhs.tail_) {
  rhs.tail_ = nullptr;
  rhs.head_ = nullptr;
}

template<class T>
QueueLstT<T>& QueueLstT<T>::operator=(const QueueLstT<T>& rhs) {
  if (rhs.IsEmpty()) {
    this->Clear();
    return *this;
  }
  Node* ptrMain = rhs.head_;
  Node* ptrCopy = head_;
  Node* last = head_;

  while (ptrMain != nullptr) {
    if (ptrCopy != nullptr) {
      ptrCopy->data_ = ptrMain->data_;
      last = ptrCopy;
      ptrCopy = ptrCopy->next;

    }
    else {
      Node* node = new Node;
      node->data_ = ptrMain->data_;
      if (last != nullptr) {
        last->next = node;
        last = node;
      }
      else {
        last = node;
        head_ = node;
      }
    }
    ptrMain = ptrMain->next;
  }
  tail_ = last;
  last->next = nullptr;
  last = nullptr;
  Node* Next = nullptr;
  while (ptrCopy != nullptr) {

    Next = ptrCopy->next;
    delete ptrCopy;
    ptrCopy = Next;
  }
  return *this;
}

template <class T>
QueueLstT<T>& QueueLstT<T>::operator=(QueueLstT<T>&& rhs) noexcept {
  if (this != &rhs) {
    std::swap(tail_, rhs.tail_);
    std::swap(head_, rhs.head_);
  }
  return *this;
}
#endif 

