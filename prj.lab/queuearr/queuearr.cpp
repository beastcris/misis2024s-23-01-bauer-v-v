#include <queuearr/queuearr.hpp>


bool QueueArr::IsEmpty() const noexcept {
  return (head_ == -1);
}

void QueueArr::Pop() noexcept {
  if (head_ == tail_) {
    this->Clear();
  }
  else {
    head_ = (head_ + 1) % size_;
  }
}

void QueueArr::Clear() noexcept {
  head_ = -1;
  tail_ = -1;
}

Complex& QueueArr::Top() {
  if (head_ == -1) {
    throw std::logic_error("Queue Is Empty");
  }
  return data_[head_];
}

const Complex& QueueArr::Top() const{
  if (head_ == -1) {
    throw std::logic_error("Queue Is Empty");
  }
  return data_[head_];
}

QueueArr::~QueueArr() {
  delete data_;
  data_ = nullptr;
}

void QueueArr::Push(const Complex& rhs) {
  if (data_ == nullptr) {
    size_ = 5;
    Complex* tmp = new Complex[size_];
    data_ = tmp;
    tmp = nullptr;
    head_ = 0;
    tail_ = 0;
    data_[head_] = rhs;
  } else if (tail_ + 1 == head_) {
    Complex* tmp = new Complex[size_ * 2];
    std::copy(data_ + head_, data_ + size_ , tmp);
    std::copy(data_, data_ + head_, tmp + size_ - head_ + 1);
    head_ = 0;
    tail_ = size_;
    tmp[size_] = rhs;
    size_ *= 2;
    data_ = tmp;
    tmp = nullptr;
  }
  else {
    tail_ = (tail_ + 1) % size_;
    data_[tail_] = rhs;
    if (head_ == -1) {
      head_ = tail_;
    }
  }
}

QueueArr::QueueArr(const QueueArr& rhs) :size_(rhs.size_), head_(rhs.head_), tail_(rhs.tail_) {
  Complex* tmp = new Complex[rhs.size_];
  std::copy(rhs.data_, rhs.data_ + size_, tmp);
  data_ = tmp;
  tmp = nullptr;
}

QueueArr& QueueArr::operator=(const QueueArr& rhs) {
  if (rhs.IsEmpty()) {
    this->Clear();
    return *this;
  }

  if (size_ < rhs.size_) {
    delete[] data_;
    Complex* tmp = new Complex[rhs.size_];
    data_ = tmp;
    tmp = nullptr;
    size_ = rhs.size_;
  }
  
  if (rhs.tail_ < rhs.head_) {
    tail_ = rhs.size_ - rhs.size_ + rhs.tail_;
    head_ = 0;
    std::copy(rhs.data_ + rhs.head_, rhs.data_ + rhs.size_, data_);
    std::copy(rhs.data_, rhs.data_ + rhs.tail_ + 1, data_ + rhs.size_ - rhs.head_);
  }
  else {
    tail_ = rhs.tail_ - rhs.head_;
    head_ = 0;
    std::copy(rhs.data_ + rhs.head_, rhs.data_ + rhs.tail_ + 1, data_);
  }
  return *this;
}

