#include <stackarr/stackarr.hpp>

StackArr::StackArr() {
  Complex* tmp = new Complex[capacity_];
  ptr = tmp;
  tmp = nullptr;
}

StackArr::~StackArr() {
  delete[] ptr;
  ptr = nullptr;
}

StackArr::StackArr(const StackArr& rhs) {
  Complex* copy = new Complex[rhs.capacity_];
  std::copy(rhs.ptr, rhs.ptr + rhs.top_, copy);
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
  std::copy(rhs.ptr, rhs.ptr + rhs.top_, ptr);
  top_ = rhs.top_;
  return *this;
}

bool StackArr::IsEmpty() const noexcept{
  if (top_ == 0) {
    return true;
  }
  return false;
}

void StackArr::Pop() noexcept {
  top_ = std::max(static_cast<long long>(0), top_ - 1);
}

void StackArr::Push(const Complex& rhs) {
  if (top_ == capacity_) {
    Complex* tmp = new Complex[capacity_ * 2];
    capacity_ *= 2;
    std::copy(ptr, ptr + top_, tmp);
    ptr = tmp;
    tmp = nullptr;
  }
  ptr[top_] = rhs;
  ++top_;
}

const Complex& StackArr::Top() const{
  if (top_ == 0) {
    throw std::logic_error("Stack Is Empty");
  }
  return ptr[top_ - 1];
}

Complex& StackArr::Top() {
  if (top_ == 0) {
    throw std::logic_error("Stack Is Empty");
  }
  return ptr[top_ - 1];
} 

void StackArr::Clear() noexcept {
  top_ = 0;
}