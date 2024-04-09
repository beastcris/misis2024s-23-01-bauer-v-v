



#ifndef STACKLSTT_HPP
#define STACKLSTT_HPP

#include <iosfwd>
#include <stdexcept>


template<class T>
class StackLstT {
public:
  [[nodiscard]] StackLstT() = default;

  [[nodiscard]] StackLstT(const StackLstT<T>& rhs);
  StackLstT(StackLstT<T>&& rhs) noexcept;

  ~StackLstT();

  [[nodiscard]] StackLstT& operator=(const StackLstT<T>& rhs);
  StackLstT& operator=(StackLstT<T>&& rhs) noexcept;

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

    T data_ = { 0,0 };
    Node* next = nullptr;
  };

  Node* head_ = nullptr;
};

template <class T>
bool StackLstT<T>::IsEmpty() const noexcept {
  return (head_ == nullptr);
}


template <class T>
void StackLstT<T>::Push(const T& rhs) {
  Node* curr = new Node;
  curr->data_ = rhs;
  curr->next = head_;
  head_ = curr;
  curr = nullptr;
}

template <class T>
const T& StackLstT<T>::Top() const {
  if (this->IsEmpty()) {
    throw std::logic_error("Stack Is Empty");
  }

  return head_->data_;
}

template <class T>
T& StackLstT<T>::Top() {
  if (this->IsEmpty()) {
    throw std::logic_error("Stack Is Empty");
  }

  return head_->data_;
}

template <class T>
void StackLstT<T>::Pop() noexcept {
  if (!(this->IsEmpty())) {
    Node* tmp = head_->next;
    delete head_;
    head_ = tmp;
    tmp = nullptr;
  }
}

template <class T>
void StackLstT<T>::Clear() noexcept {
  while (!(this->IsEmpty())) {
    this->Pop();
  }
}

template <class T>
StackLstT<T>::~StackLstT() {
  this->Clear();
}

template <class T>
StackLstT<T>& StackLstT<T>::operator=(const StackLstT<T>& rhs) {
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
StackLstT<T>& StackLstT<T>::operator=(StackLstT<T>&& rhs) noexcept {
  if (this != &rhs) {
    std::swap(head_, rhs.head_);
  }
  return *this;
}

template<class T>
StackLstT<T>::StackLstT(const StackLstT<T>& rhs) {
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
  last = nullptr;
}

template<class T>
StackLstT<T>::StackLstT(StackLstT<T>&& rhs) noexcept :head_(rhs.head_) {
  rhs.head_ = nullptr;
}



#endif 

