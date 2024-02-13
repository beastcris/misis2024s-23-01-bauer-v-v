#include <dynarr/dynarr.hpp>


[[nodiscard]] DynArr::DynArr() {};
[[nodiscard]] DynArr::DynArr(const std::ptrdiff_t size) :size_(size), capacity_(2 * size) {
  if (size <= 0) {
    throw std::invalid_argument("INVALID ARRAY SIZE");
  }
  float* arr = new float[capacity_];
  data_ = arr;
  this->PutZero(this->data_);
};
[[nodiscard]] DynArr::DynArr(const DynArr& rhs) :size_(rhs.size_) {
  if (rhs.size_ > capacity_) {
    capacity_ = 2 * rhs.size_;
  }
  float* arr = new float[capacity_];
  data_ = arr;
  this->PutZero(this->data_);
  for (std::ptrdiff_t i = 0; i < size_; ++i) {
    *(data_ + i) = *(rhs.data_ + i);
  }
}
DynArr::~DynArr() { delete[] data_; }

DynArr& DynArr::operator=(const DynArr& rhs) {
  if (rhs.size_ > size_) {
    if (rhs.size_ > capacity_) {
      capacity_ = 2 * rhs.size_;
    }
    size_ = rhs.size_;
    float* arr = new float[capacity_];
    delete[] data_;
    data_ = arr;
    this->PutZero(this->data_);
    for (std::ptrdiff_t i = 0; i < size_; ++i) {
      *(data_ + i) = *(rhs.data_ + i);
    }
  }
  else {
    size_ = rhs.size_;
    for (std::ptrdiff_t i = 0; i < size_; ++i) {
      *(data_ + i) = *(rhs.data_ + i);
    }
  }
  return *this;
}

[[nodiscard]] float& DynArr::operator[] (const std::ptrdiff_t idx) {
  if (idx >= size_ || idx <0) {
    throw std::out_of_range("OUT OF RANGE");
  }
  return *(data_ + idx);
}

[[nodiscard]] const float& DynArr::operator[] (const std::ptrdiff_t idx) const{
  if (idx >= size_ || idx < 0) {
    throw std::out_of_range("OUT OF RANGE");
  }
  return *(data_ + idx);
}

void DynArr::Resize(const std::ptrdiff_t NewSize) {
  if (NewSize <= 0) {
    throw std::invalid_argument("INVALID ARRAY SIZE");
  }
  if (NewSize > size_) {
    if (NewSize > capacity_) {
      capacity_ = 2 * NewSize;
    }
    
    float* arr = new float[capacity_];
    for (std::ptrdiff_t i = 0; i < capacity_; ++i) {
      if (i < size_) {
        arr[i] = data_[i];
      }
      else {
        arr[i] = 0;
      }
    }
    size_ = NewSize;
    delete[] data_;
    data_ = arr;
  }
  else {
    size_ = NewSize;
  }
}

[[nodiscard]] float* DynArr::getData() noexcept { return data_; }
std::ptrdiff_t DynArr::Size() const noexcept { return size_; }

[[nodiscard]] void DynArr::PutZero(float* data) noexcept {
  for (std::ptrdiff_t i = 0; i < size_; ++i) {
    *(data + i) = 0;
  }
}

std::ostream& DynArr::writeTo(std::ostream& os) const noexcept {
  os << '{';
  for (float* i = data_; i < data_ + size_; ++i) {
    os << *(i);
    if (i + 1 != data_ + size_) {
      os << ", ";
    }
  }
  os << '}' << '\n';
  return os;
}

std::ostream& operator<<(std::ostream& os, const DynArr& rhs) {
  return rhs.writeTo(os);
}

