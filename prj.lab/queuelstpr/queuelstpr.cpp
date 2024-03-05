#include "queuelstpr.hpp"
f

bool QueueLstPr::IsEmpty() const noexcept{
  return head_ == nullptr;
}

void QueueLstPr::Pop() noexcept{
  if (tail_ != nullptr) {
    Node* tmp = tail_->next_;
    delete tail_;
    tail_ = tmp;
    tmp = nullptr;
  }
}

void QueueLstPr::Clear() {
  while (!this->IsEmpty()) {
    this->Pop();
  };
}

QueueLstPr::~QueueLstPr() {
  this->Clear();
}

void QueueLstPr::Push(const float& value) {
  Node* curr = new Node;
  curr->data_ = value;
  if (this->IsEmpty()) {
    head_ = curr;
    tail_ = curr;
  }
  else if (value <= head_->data_) {
    head_->next_ = curr;
    head_ = curr;
  }
  else if (value >= tail_->data_) {
    curr->next_ = tail_;
    tail_ = curr;
  }
  else {
    Node* Tmp = tail_->next_;
    while (value < Tmp->next_->data_) {
      Tmp = Tmp->next_;
    }
    curr->next_ = Tmp->next_;
    Tmp->next_ = curr;
    Tmp = nullptr;
  }
  curr = nullptr;
}

float& QueueLstPr::Top() {
  if (this->IsEmpty()) {
    throw std::logic_error("Queue is empty");
  }
  else {
    return head_->data_;
  }
}

const float& QueueLstPr::Top() const{
  if (this->IsEmpty()) {
    throw std::logic_error("Queue is empty");
  }
  else {
    return head_->data_;
  }
}

QueueLstPr::QueueLstPr(const QueueLstPr& rhs) {

}

QueueLstPr& QueueLstPr::operator=(const QueueLstPr& rhs) {
  if (rhs.IsEmpty()) {
    this->Clear();
    return *this;
  }


  return *this;
}
