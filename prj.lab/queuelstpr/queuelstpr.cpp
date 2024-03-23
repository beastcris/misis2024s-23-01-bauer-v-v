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

QueueLstPr& QueueLstPr::operator=(const QueueLstPr& rhs) {
  if (this != &rhs) {
    if (rhs.IsEmpty()) {
      this->Clear();
    }
    else {
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

QueueLstPr::QueueLstPr(const QueueLstPr& rhs) {
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