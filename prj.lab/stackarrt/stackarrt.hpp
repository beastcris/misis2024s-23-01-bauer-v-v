
#ifndef STACKARR_HPP
#define STACKARR_HPP



template<class T>
class StackArrT {

public:
  [[nodiscard]] StackArrT();

  [[nodiscard]] StackArrT(const StackArrT<T>& rhs);
  StackArrT(StackArrT<T>&& rhs) noexcept;
  ~StackArrT();

  [[nodiscard]] StackArrT<T>& operator=(const StackArrT<T>& rhs);
  StackArrT<T>& operator=(StackArrT<T>&& rhs) noexcept;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const T& rhs);

  [[nodiscard]] T& Top();

  [[nodiscard]] const T& Top() const;

  void Clear() noexcept;
private:
  std::ptrdiff_t capacity_ = 1;
  T* ptr = nullptr;
  std::ptrdiff_t top_ = 0;

};

template<class T>
StackArrT<T>::StackArrT() {
  T* tmp = new T[capacity_];
  ptr = tmp;
  tmp = nullptr;
}

template<class T>
StackArrT<T>::~StackArrT() {
  delete[] ptr;
  ptr = nullptr;
}

template<class T>
StackArrT<T>::StackArrT(const StackArrT<T>& rhs) : capacity_(rhs.capacity_) {
  T* copy = new T[rhs.capacity_];
  std::copy(rhs.ptr, rhs.ptr + rhs.top_, copy);
  ptr = copy;
  copy = nullptr;
  top_ = rhs.top_;
}

template<class T>
StackArrT<T>::StackArrT(StackArrT<T>&& rhs) noexcept
  : capacity_(rhs.capacity_)
  , top_(rhs.top_)
  , ptr(rhs.ptr) {
  rhs.ptr = nullptr;
  rhs.capacity_ = 1;
  rhs.top_ = 0;
}

template<class T>
StackArrT<T>& StackArrT<T>::operator=(const StackArrT<T>& rhs) {
  if (capacity_ <= rhs.top_) {
    T* copy = new T[rhs.capacity_];
    capacity_ = rhs.capacity_;
    ptr = copy;
    copy = nullptr;
  }
  std::copy(rhs.ptr, rhs.ptr + rhs.top_, ptr);
  top_ = rhs.top_;
  return *this;
}

template<class T>
StackArrT<T>& StackArrT<T>::operator=(StackArrT<T>&& rhs) noexcept {
  if (this != &rhs) {
    std::swap(capacity_, rhs.capacity_);
    std::swap(top_, rhs.top_);
    std::swap(ptr, rhs.ptr);
  }
  return *this;
}

template<class T>
bool StackArrT<T>::IsEmpty() const noexcept {
  if (top_ == 0) {
    return true;
  }
  return false;
}

template<class T>
void StackArrT<T>::Pop() noexcept {
  top_ = std::max(static_cast<long long>(0), top_ - 1);
}

template<class T>
void StackArrT<T>::Push(const T& rhs) {
  if (top_ == capacity_) {
    T* tmp = new T[capacity_ * 2];
    capacity_ *= 2;
    std::copy(ptr, ptr + top_, tmp);
    ptr = tmp;
    tmp = nullptr;
  }
  ptr[top_] = rhs;
  ++top_;
}

template<class T>
const T& StackArrT<T>::Top() const {
  if (top_ == 0) {
    throw std::logic_error("Stack Is Empty");
  }
  return ptr[top_ - 1];
}

template<class T>
T& StackArrT<T>::Top() {
  if (top_ == 0) {
    throw std::logic_error("Stack Is Empty");
  }
  return ptr[top_ - 1];
}

template<class T>
void StackArrT<T>::Clear() noexcept {
  top_ = 0;
}

#endif 

