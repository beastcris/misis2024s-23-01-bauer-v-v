#include <stackarr/stackarr.hpp>

StackArr::StackArr() {
  Complex* tmp = new Complex[capacity_];
  ptr = tmp;
  tmp = nullptr;
}

StackArr::~StackArr() noexcept{
  delete[] ptr;
  ptr = nullptr;
}

StackArr::StackArr(const StackArr& rhs) {
  Complex* copy = new Complex[rhs.capacity_];
  for (std::ptrdiff_t i = 0; i < rhs.top_; ++i) {
    copy[i] = rhs.ptr[i];
  }

  ptr = copy;
  copy = nullptr;
  top_ = rhs.top_;
}

StackArr& StackArr::operator=(const StackArr& rhs) {
  if (capacity_ <= rhs.top_) {
    Complex* copy = new Complex[rhs.capacity_];
    ptr = copy;
    copy = nullptr;
  }
  for (std::ptrdiff_t i = 0; i < rhs.top_; ++i) {
    ptr[i] = rhs.ptr[i];
  }

  top_ = rhs.top_;
  return *this;
}

bool StackArr::IsEmpty() noexcept{
  if (top_ == 0) {
    return true;
  }
  return false;
}

void StackArr::Pop() noexcept{
  ptr[top_] = 0;
  top_ = std::max(static_cast<long long>(0), top_ - 1);
}

void StackArr::Push(const Complex& rhs) {
  if (top_ == capacity_) {
    Complex* tmp = new Complex[capacity_ * 2];
    capacity_ *= 2;
    for (std::ptrdiff_t i = 0; i < top_; ++i) {
      tmp[i] = ptr[i];
    }
    ptr = tmp;
    tmp = nullptr;
  }
  ptr[top_] = rhs;
  ++top_;
}

const Complex& StackArr::Top() {
  if (top_ == 0) {
    throw std::exception("Stack is Empty");
  }
  return ptr[top_ - 1];
}