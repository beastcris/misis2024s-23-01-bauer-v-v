#include <stackarr/stackarr.hpp>

StackArr::StackArr() {
  Complex* beg = new Complex[capacity_];
  ptr = beg;
  beg = nullptr;
}

StackArr::~StackArr() noexcept{
  delete[] ptr;
  ptr = nullptr;
}

StackArr::StackArr(const StackArr& rhs) {
  Complex* copy = new Complex[rhs.capacity_];
  for (std::ptrdiff_t i = 0; i <= rhs.top_; ++i) {
    copy[i] = rhs.ptr[i];
  }

  ptr = copy;
  copy = nullptr;
  top_ = rhs.top_;
}

StackArr& StackArr::operator=(const StackArr& rhs) {
  if (capacity_ < rhs.top_) {
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

bool StackArr::IsEmpty() {
  if (top_ == 0) {
    return true;
  }
  return false;
}

void StackArr::Pop() {
  ptr[top_] = 0;
  top_ = std::max(static_cast<long long>(0), top_ - 1);
}

void StackArr::Push(const Complex& rhs) {
    
}
