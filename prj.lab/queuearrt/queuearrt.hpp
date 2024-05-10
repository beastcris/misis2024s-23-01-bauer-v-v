
#ifndef QUEUEARRT_HPP
#define QUEUEARRT_HPP

#include <cstddef>
#include <stdexcept>

template<class T>
class QueueArrT {

public:
  [[nodiscard]] QueueArrT() = default;

  [[nodiscard]] QueueArrT(const QueueArrT<T>& rhs);
  QueueArrT(QueueArrT<T>&& rhs) noexcept;

  ~QueueArrT();

  [[nodiscard]] QueueArrT<T>& operator=(const QueueArrT<T>& rhs);
  QueueArrT<T>& operator=(QueueArrT<T>&& rhs) noexcept;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const T& rhs);

  [[nodiscard]] T& Top();

  [[nodiscard]] const T& Top() const;

  void Clear() noexcept;
private:
  std::ptrdiff_t head_ = -1;
  std::ptrdiff_t size_ = 0;
  std::ptrdiff_t tail_ = -1;

  T* data_ = nullptr;
};

template<class T>
bool QueueArrT<T>::IsEmpty() const noexcept {
  return (head_ == -1);
}

template<class T>
void QueueArrT<T>::Pop() noexcept {
  if (head_ == tail_) {
    this->Clear();
  }
  else {
    head_ = (head_ + 1) % size_;
  }
}

template<class T>
void QueueArrT<T>::Clear() noexcept {
  head_ = -1;
  tail_ = -1;
}

template<class T>
T& QueueArrT<T>::Top() {
  if (head_ == -1) {
    throw std::logic_error("Queue Is Empty");
  }
  return data_[head_];
}

template<class T>
const T& QueueArrT<T>::Top() const {
  if (head_ == -1) {
    throw std::logic_error("Queue Is Empty");
  }
  return data_[head_];
}

template<class T>
QueueArrT<T>::~QueueArrT() {
  delete data_;
  data_ = nullptr;
}

template<class T>
void QueueArrT<T>::Push(const T& rhs) {
  if (data_ == nullptr) {
    size_ = 5;
    T* tmp = new T[size_];
    data_ = tmp;
    tmp = nullptr;
    head_ = 0;
    tail_ = 0;
    data_[head_] = rhs;
  }
  else if ((tail_ + 1) % size_ == head_) {
    T* tmp = new T[size_ * 2];
    std::copy(data_ + head_, data_ + size_, tmp);
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

template<class T>
QueueArrT<T>::QueueArrT(const QueueArrT<T>& rhs) :size_(rhs.size_), head_(rhs.head_), tail_(rhs.tail_) {
  T* tmp = new T[rhs.size_];
  std::copy(rhs.data_, rhs.data_ + size_, tmp);
  data_ = tmp;
  tmp = nullptr;
}

template<class T>
QueueArrT<T>::QueueArrT(QueueArrT<T>&& rhs) noexcept
  :head_(rhs.head_)
  , size_(rhs.size_)
  , tail_(rhs.tail_)
  , data_(rhs.data_) {
  rhs.data_ = nullptr;
  rhs.head_ = -1;
  rhs.tail_ = -1;
  rhs.size_ = 0;
}

template<class T>
QueueArrT<T>& QueueArrT<T>::operator=(const QueueArrT<T>& rhs) {
  if (rhs.IsEmpty()) {
    this->Clear();
    return *this;
  }

  if (size_ < rhs.size_) {
    delete[] data_;
    T* tmp = new T[rhs.size_];
    data_ = tmp;
    tmp = nullptr;
    size_ = rhs.size_;
  }

  if (rhs.tail_ < rhs.head_) {
    tail_ = rhs.size_ - rhs.head_ + rhs.tail_;
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

template<class T>
QueueArrT<T>& QueueArrT<T>::operator=(QueueArrT<T>&& rhs) noexcept {
  if (this != &rhs) {
    std::swap(head_, rhs.head_);
    std::swap(tail_, rhs.tail_);
    std::swap(size_, rhs.size_);
    std::swap(data_, rhs.data_);
  }
  return *this;
}

#endif 
