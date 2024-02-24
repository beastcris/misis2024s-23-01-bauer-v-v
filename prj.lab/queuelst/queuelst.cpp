#include <queuelst/queuelst.hpp>


bool QueueLst::IsEmpty() const noexcept {
  return (head_ == nullptr);
}

void QueueLst::Push(const Complex& rhs) {
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

void QueueLst::Pop() noexcept{
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

Complex& QueueLst::Top() {
  return head_->data_;
}

const Complex& QueueLst::Top() const {
  return head_->data_;
}

void QueueLst::Clear() noexcept {
  while (head_!=nullptr) {
    this->Pop();
  }
}

QueueLst::~QueueLst() {
  this->Clear();
}

QueueLst::QueueLst(const QueueLst& rhs) {
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

QueueLst& QueueLst::operator=(const QueueLst& rhs) {
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