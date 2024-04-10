#include <bitset/bitset.hpp>
#include <iostream>
#include <algorithm>
#include <string>
#include <sys/stat.h>

int32_t BitSet::Size() const noexcept{
  return size_;
}

BitSet::BitSet(const int32_t cnt):size_(cnt) {
  if (cnt <= 0) {
    throw std::logic_error("Size cannot be negative");
  }
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
  if (size <= 0) {
    throw std::logic_error("Size cannot be negative");
  }

  if (size > size_) {
    bits_.insert(bits_.end(), (size - 1) / 32 + 1 - ((size_ - 1) / 32 + 1), 0);
  }
  else {
    bits_.erase(bits_.begin() + (size - 1) / 32 + 1, bits_.end());
  }

  int32_t old_size = size_;
  for (int32_t i = size; i < old_size; ++i) {
    this->Set(i, 0);
  }
  size_ = size;
}

void BitSet::Set(const int32_t idx, const bool value) {
  if (idx < 0 || idx >= size_) {
    throw std::out_of_range("Index Out of Range");
  }

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

bool BitSet::Get(const int32_t idx) const {
  if (idx < 0 || idx >= size_) {
    throw std::out_of_range("Index Out of Range");
  }

  int32_t pos = idx / 32;
  int32_t pow = idx % 32;
  uint32_t num = bits_[pos];

  while (pow != 0) {
    --pow;
    num /= 2;
  }
  return num % 2;
}

void BitSet::Fill(const bool value) {
  if (value) {
    std::fill(bits_.begin(), bits_.end(), CEIL_NUM);
    if (size_ % 32 != 0) {
      bits_[bits_.size() - 1] = (1 << (size_ % 32)) - 1;
    }
  }
  else {
    std::fill(bits_.begin(), bits_.end() , FLOOR_NUM);
  }
}

bool BitSet::operator==(const BitSet& rhs) {
  return (bits_ == rhs.bits_) && (size_ == rhs.size_);
}

bool BitSet::operator!=(const BitSet& rhs) {
  return !operator==(rhs);
}

BitSet::BiA BitSet::operator[](const int32_t idx) {
  if (idx < 0 || idx >= this->Size()) {
    throw std::out_of_range("Out Of Range");
  }
  return {*this, idx};
}

BitSet& BitSet::operator&=(const BitSet& rhs) {
  if (this->size_ != rhs.size_) {
    throw std::logic_error("Different Sizes");
  }
  for (int32_t i = 0; i < bits_.size(); ++i) {
    bits_[i] &= rhs.bits_[i];
  }

  return *this;
}

BitSet& BitSet::operator|=(const BitSet& rhs) {
  if (this->size_ != rhs.size_) {
    throw std::logic_error("Different Sizes");
  }
  for (int32_t i = 0; i < bits_.size(); ++i) {
    bits_[i] |= rhs.bits_[i];
  }

  return *this;
}

BitSet& BitSet::operator^=(const BitSet& rhs) {
  if (this->size_ != rhs.size_) {
    throw std::logic_error("Different Sizes");
  }
  for (int32_t i = 0; i < bits_.size(); ++i) {
    bits_[i] ^= rhs.bits_[i];
  }

  return *this;
}

BitSet& BitSet::operator~() {
  for (int32_t i = 0; i < bits_.size(); ++i) {
    bits_[i] = ~bits_[i];
  }

  return *this;
}

[[nodiscard]] BitSet operator&(const BitSet& lhs, const BitSet& rhs) {
  if (lhs.Size() != rhs.Size()) {
    throw std::logic_error("Different Sizes");
  }

  BitSet tmp(lhs);
  return tmp &= (rhs);
};

[[nodiscard]] BitSet operator|(const BitSet& lhs, const BitSet& rhs) {
  if (lhs.Size() != rhs.Size()) {
    throw std::logic_error("Different Sizes");
  }

  BitSet tmp(lhs);
  return tmp |= (rhs);
};

[[nodiscard]] BitSet operator^(const BitSet& lhs, const BitSet& rhs) {
  if (lhs.Size() != rhs.Size()) {
    throw std::logic_error("Different Sizes");
  }

  BitSet tmp(lhs);
  return tmp ^= (rhs);
};

const bool BitSet::operator[](const int32_t idx) const {
  if (idx < 0 || idx >=this->Size()) {
    throw std::out_of_range("Out Of Range");
  }
  return this->Get(idx);
};

std::ostream& BitSet::WriteTxt(std::ostream& os) const {
  static long long cnt = 0;
  std::ofstream myfile;
  if (cnt == 0) {
    myfile.open(PATH_OUTPUT);
  }
  else {
    myfile.open(PATH_OUTPUT, std::ios_base::app);
  }

  int32_t str_num = 1;
  int32_t vec_idx = 0;
  while (vec_idx < (this->Size() - 1) / 32 + 1) {
    int32_t i = vec_idx * 32;
    for (int32_t idx = i; idx < i + 32; ++idx) {
      if (idx >= this->Size()) {
        vec_idx = (this->Size() - 1) / 32 + 1;
        break;
      }
      myfile << (*this)[idx];
      if ((idx + 1) % 16 == 0) {
        myfile << " |" << str_num << std::endl;
        ++str_num;
      }
      else if ((idx + 1) % 4 == 0) {
        myfile << ' ';
      }
    }
    ++vec_idx;
  }
  for (int32_t i = 0; i < 16 - (this->Size()) % 16 + (16 - (this->Size()) % 16)/4 + 1; ++i) {
    myfile << ' ';
  }
  myfile << '|' << str_num;
  myfile << std::endl << "====================" << std::endl;
  ++cnt;
  return os;
}