#include <bitset/bitset.hpp>
#include <iostream>
#include <algorithm>
#include <string>

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
  return this->Get(idx);
};

std::ostream& operator<<(std::ostream& os,const BitSet& rhs) noexcept {
  int32_t str_num = 1;
  int32_t vec_idx = 0;
  while (vec_idx < (rhs.Size() - 1)/32 + 1) {
    int32_t i = vec_idx * 32;
    for (int32_t idx = i; idx < i + 32; ++idx) {
      if (idx >= rhs.Size()) {
        vec_idx = (rhs.Size() - 1) / 32 + 1;
        break;
      }
      os << rhs[idx];
      if ((idx + 1) % 16 == 0) {
        os << " |" << str_num << std::endl;
        ++str_num;
      } else if ((idx + 1) % 4 == 0) {
        os << ' ';
      }
    }
    ++vec_idx;
  } 
  os << std::endl << "====================" << std::endl;
  return os;
}

std::istream& operator>>(std::istream& is, BitSet& rhs) noexcept {
  std::string input = " ";
  int32_t idx = 0;
  while (idx < rhs.Size()) {
    std::string first_four = "";
    std::string second_four = "";
    std::string third_four = "";
    std::string fourth_four = "";

    is >> first_four >> second_four >> third_four >> fourth_four;
    if (is.good() || is.eof()) {
      std::vector<std::string> bits{ first_four, second_four, third_four, fourth_four };
      if (first_four.length() == 4 && second_four.length() == 4 && third_four.length() == 4 && fourth_four.length() == 4) {
        for (auto elem : bits) {
          for (int32_t i = 0; i < elem.length(); ++i) {
            if (elem[i] == '0') {
              rhs[idx] = 0;
            }
            else {
              rhs[idx] = 1;
            }
            ++idx;
            if (idx >= rhs.Size()) {
              break;
            }
          }
        }
      }
      else {
        bool flag = false;
        for (int32_t i = 0; i < 4; ++i) {
          if (flag && bits[i].length() != 0) {
            is.setstate(std::ios::failbit);
          }
          else if (!flag) {
            if (bits[i].length() != 4) {
              flag = true;
            } 
            for (int32_t j = 0; j < bits[i].length();  ++j) {
              if (bits[i][j] == '0') {
                rhs[idx] = 0;
              }
              else {
                rhs[idx] = 1;
              }
              ++idx;
              if (idx >= rhs.Size()) {
                break;
              }
            }
          }
          if (idx >= rhs.Size()) {
            break;
          }
        }
      }
    }            
  }
  
  return is;
}