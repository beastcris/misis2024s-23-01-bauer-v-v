#include <stacklst/stacklst.hpp>

bool StackLst::IsEmpty() const noexcept {
  return (head_ == nullptr);
}

void StackLst::Push(Complex& rhs) {
  Node* curr = new Node;
  curr->data_ = rhs;
  curr->next = head_;
  head_ = curr;
  curr = nullptr;
}

const Complex& StackLst::Top() const{
  if (this->IsEmpty()) {
    throw std::logic_error("Stack Is Empty");
  }

  return head_->data_;
}

Complex& StackLst::Top() {
  if (this->IsEmpty()) {
    throw std::logic_error("Stack Is Empty");
  }

  return head_->data_;
}

void StackLst::Pop() noexcept{
  if (!(this->IsEmpty())) {
    Node *tmp = head_->next;
    delete head_;
    head_ = tmp;
    tmp = nullptr;
  }
}

void StackLst::Clear() noexcept{
  while (!(this->IsEmpty())) {
    this->Pop();
  }
}

StackLst::~StackLst() {
  this->Clear();
}

StackLst& StackLst::operator=(const StackLst& rhs) {
  if (rhs.IsEmpty()) {
    this->Clear();
    return *this;
  }
  Node* ptrMain = rhs.head_;
  Node* ptrCopy = head_;
  Node* last = head_;

  while (ptrMain!=nullptr) {
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
  Node *Next = nullptr;
  while (ptrCopy!=nullptr) {

    Next = ptrCopy->next;
    delete ptrCopy;
    ptrCopy = Next;
  }
  return *this;
}

StackLst::StackLst(const StackLst& rhs) {
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