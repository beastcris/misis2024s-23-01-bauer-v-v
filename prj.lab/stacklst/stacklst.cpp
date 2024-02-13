#include <stacklst/stacklst.hpp>
#include <iostream>

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

void StackLst::Pop() {
  /*node* tmp = new node;
  tmp = 
  delete head_;
  head_ = tmp;
  tmp = nullptr;*/
}