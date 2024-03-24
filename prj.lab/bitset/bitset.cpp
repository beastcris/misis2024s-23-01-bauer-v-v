#include <bitset/bitset.hpp>
#include <iostream>
#include <algorithm>


int32_t BitSet::Size() const noexcept{
  return size_;
}

BitSet::BitSet(const int32_t cnt):size_(cnt) {
  bits_.insert(bits_.begin(), (cnt - 1) / 32 + 1, 0);
}

BitSet::BitSet(BitSet&& rhs) noexcept :size_(rhs.size_) {
  std::swap(bits_, rhs.bits_);
}

BitSet& BitSet::operator=(BitSet&& rhs) noexcept {
  if (this != &rhs) {
    std::swap(size_, rhs.size_);
    std::swap(bits_, rhs.bits_);
  }
  return *this;
}

void BitSet::Resize(const int32_t size) {
  if (size > size_) {
    bits_.insert(bits_.end(), (size - 1) / 32 + 1 - size_, 0);
  }
  else {
    bits_.erase(bits_.begin() + (size - 1) / 32 + 1, bits_.end());
  }
  size_ = size;
}

void BitSet::Set(const int32_t idx, const bool value) {
  if (this->Get(idx) != value) {
    int32_t pos = idx / 32;
    if (value) {
      bits_[pos] += (1 << (idx % 32));
    }
    else {
      bits_[pos] -= (1 << (idx % 32));
    }
  }
}

bool BitSet::Get(const int32_t idx) {
  int32_t pos = idx / 32;
  int32_t pow = idx % 32;
  int32_t num = bits_[pos];

  while (pow != 0) {
    --pow;
    num /= 2;
  }
  return num % 2;
}

void BitSet::Fill(const bool value) {
  if (value) {
    std::fill(bits_.begin(), bits_.end(), CEIL_NUM);
  }
  else {
    std::fill(bits_.begin(), bits_.end(), 0);
  }
}

bool BitSet::operator==(const BitSet& rhs) {
  return (bits_ == rhs.bits_) && (size_ == rhs.size_);
}

bool BitSet::operator!=(const BitSet& rhs) {
  return !operator==(rhs);
}
void BitSet::Arr() {
  for (int32_t i = 0; i < bits_.size(); ++i) {
    std::cout << bits_[i] << std::endl;
  }
}