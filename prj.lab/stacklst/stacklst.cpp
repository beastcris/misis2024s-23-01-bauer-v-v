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
  Node *tmp = head_->next;
  delete head_;
  head_ = tmp;
  tmp = nullptr;
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