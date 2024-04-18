
#ifndef QUEUELSTPRT_HPP
#define QUEUELSTPRT_HPP

#include <algorithm>
#include <stdexcept>
#include <iosfwd>

template<class T>
class QueueLstPrT {

public:
  QueueLstPrT() = default;
  QueueLstPrT(const QueueLstPrT<T>& rhs);
  QueueLstPrT(QueueLstPrT<T>&& rhs) noexcept;
  QueueLstPrT<T>& operator=(const QueueLstPrT<T>& rhs);
  QueueLstPrT<T>& operator=(QueueLstPrT<T>&& rhs) noexcept;
  ~QueueLstPrT();

  void Push(const T& value);
  void Pop() noexcept;  

  T& Top();
  const T& Top() const;

  bool IsEmpty() const noexcept;
  void Clear() noexcept;
private:
  struct Node {

    Node* next_ = nullptr;
    T data_ = 0;
  };

  Node* head_ = nullptr;
};

template<class T>
QueueLstPrT<T>::QueueLstPrT(QueueLstPrT<T>&& rhs) noexcept
  :head_(rhs.head_) {
  rhs.head_ = nullptr;
}


template<class T>
QueueLstPrT<T>& QueueLstPrT<T>::operator=(QueueLstPrT<T>&& rhs) noexcept {
  if (this != &rhs) {
    std::swap(head_, rhs.head_);
  }
  return *this;
}

template<class T>
bool QueueLstPrT<T>::IsEmpty() const noexcept {
  return head_ == nullptr;
}

template<class T>
void QueueLstPrT<T>::Clear() noexcept {
  while (head_!=nullptr) {
    this->Pop();
  }
}

template<class T>
QueueLstPrT<T>::~QueueLstPrT() {
  this->Clear();
}

template<class T>
void QueueLstPrT<T>::Pop() noexcept {
  if (head_ != nullptr) {
    Node* tmp = head_->next_;
    delete head_;
    head_ = tmp;
    tmp = nullptr;
  }
}

template<class T>
T& QueueLstPrT<T>::Top() {
  if (head_ == nullptr) {
    throw std::logic_error("Queue Is Empty");
  }
  return head_->data_;
}

template<class T>
const T& QueueLstPrT<T>::Top() const{
  if (head_ == nullptr) {
    throw std::logic_error("Queue Is Empty");
  }
  return head_->data_;
}

template<class T>
void QueueLstPrT<T>::Push(const T& value) {
  Node* New = new Node;
  New->data_ = value;
  
  if (head_ == nullptr) {
    head_ = New;
    New = nullptr;
  }
  else {
    Node* ptr = head_;
    Node* last = nullptr;
    
    while (ptr!=nullptr) {
      if (ptr->data_ > value) {
        New->next_ = ptr;
        if (last == nullptr) {
          head_ = New;
        }
        else {
          last->next_ = New;
        }
        break;
      }
      last = ptr;
      ptr = ptr->next_;
      if (ptr == nullptr) {
        last->next_ = New;
      }
    }
  }
  New = nullptr;
}

template<class T>
QueueLstPrT<T>& QueueLstPrT<T>::operator=(const QueueLstPrT<T>& rhs) {
  if (this != &rhs) {
    if (rhs.IsEmpty()) {
      this->Clear();
    }
    else {
      if (this->IsEmpty()) {
        this->Push(0);
      }
      Node* ptr = rhs.head_;
      Node* curr = head_;
      Node* last = nullptr;

      while (curr != nullptr && ptr!=nullptr) {
        curr->data_ = ptr->data_;
        last = curr;
        curr = curr->next_;
        ptr = ptr->next_;
      }

      if (curr == nullptr) {
        curr = last;
        while (ptr != nullptr) {
          Node* New = new Node;
          New->data_ = ptr->data_;
          curr->next_ = New;
          curr = New;
          New = nullptr;
          ptr = ptr->next_;
        }
      }
      else {
        if (last != nullptr) {
          last->next_ = nullptr;
        }
        while (curr != nullptr) {
          Node* tmp = curr->next_;
          delete curr;
          curr = tmp;
        }
      }
      curr = nullptr;
    }
  }
  return *this;
}

template<class T>
QueueLstPrT<T>::QueueLstPrT(const QueueLstPrT<T>& rhs) {
  if (!rhs.IsEmpty()) {
    Node* ptr = rhs.head_;
    Node* last = nullptr;
    while (ptr!=nullptr) {
      Node* New = new Node;
      New->data_ = ptr->data_;
      if (last != nullptr) {
        last->next_ = New;
      }
      else {
        head_ = New;
      }
      last = New;
      ptr = ptr->next_;
    }
  }
}
#endif // !QUEUELSTPR_HPP
