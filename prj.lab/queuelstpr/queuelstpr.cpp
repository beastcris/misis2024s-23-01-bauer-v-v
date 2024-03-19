#include <queuelstpr/queuelstpr.hpp>

QueueLstPr::QueueLstPr(QueueLstPr&& rhs) noexcept
  :head_(rhs.head_) {
  rhs.head_ = nullptr;
}

QueueLstPr& QueueLstPr::operator=(QueueLstPr&& rhs) noexcept {
  if (this != &rhs) {
    std::swap(head_, rhs.head_);
  }
  return *this;
}

bool QueueLstPr::IsEmpty() const noexcept {
  return head_ == nullptr;
}

void QueueLstPr::Clear() noexcept {
  while (head_!=nullptr) {
    this->Pop();
  }
}

QueueLstPr::~QueueLstPr() {
  this->Clear();
}

void QueueLstPr::Pop() noexcept {
  if (head_ != nullptr) {
    Node* tmp = head_->next_;
    delete head_;
    head_ = tmp;
    tmp = nullptr;
  }
}

float& QueueLstPr::Top() {
  if (head_ == nullptr) {
    throw std::logic_error("Queue Is Empty");
  }
  return head_->data_;
}

const float& QueueLstPr::Top() const{
  if (head_ == nullptr) {
    throw std::logic_error("Queue Is Empty");
  }
  return head_->data_;
}

void QueueLstPr::Push(const float& value) {
  Node* New = new Node;
  New->data_ = value;
  
  if (head_ == nullptr) {
    head_ = New;
    New = nullptr;
  }
  else {
    Node* ptr = head_;
    while (ptr->next_!=nullptr) {
      ptr = ptr->next_;
    }

    if (ptr->next_ == nullptr) {
      ptr->next_ = New;
    }
    else {
      New->next_ = ptr->next_->next_;
      ptr->next_ = New;
    }
  }
  New = nullptr;
}