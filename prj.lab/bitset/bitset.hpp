

#ifndef BITSET_HPP
#define BITSET_HPP

#include <iosfwd>
#include <fstream>
#include <cstdint>
#include <vector>
#include <stdexcept>

const uint32_t CEIL_NUM = 4294967295;
const uint32_t FLOOR_NUM = 0;
const std::string PATH_OUTPUT = "C:/Users/Huawei/source/repos/misis2024s-23-01-bauer-v-v/prj.test/output.txt";

class BitSet {

public:
  class BiA {
    public:
      BiA() = delete;
      BiA(BitSet& rhs, const int32_t idx) :bst_(rhs), idx_(idx) {};

      ~BiA() = default;
      BiA& operator=(const bool value) {
        bst_.Set(idx_, value);
        return *this;
      }
      BiA& operator=(BiA rhs) {
        bst_.Set(idx_, rhs.bst_.Get(rhs.idx_));
        return *this;
      }
      bool operator==(BiA rhs) {return (rhs.bst_.Get(rhs.idx_) == this->bst_.Get(this->idx_)); }

      operator bool() const noexcept {
        return bst_.Get(idx_);
      };
  private:
      int32_t idx_ = 0;
      BitSet& bst_;
  };

public:
  BitSet() = default;
  BitSet(const int32_t cnt);
  BitSet(const BitSet& rhs) = default;
  BitSet(BitSet&& rhs) noexcept;
  BitSet& operator=(const BitSet& rhs) = default;
  BitSet& operator=(BitSet&& rhs) noexcept;
  ~BitSet() = default;

  [[nodiscard]] int32_t Size() const noexcept;
  void Resize(const int32_t size);
  
  void Set(const int32_t idx, const bool value);
  [[nodiscard]] bool Get(const int32_t idx) const;

  BitSet& operator&=(const BitSet& rhs);
  BitSet& operator|=(const BitSet& rhs);
  BitSet& operator^=(const BitSet& rhs);
  BitSet& operator~();
  
  BiA operator[](const int32_t idx);
  const bool operator[](const int32_t idx) const;

  bool operator==(const BitSet& rhs);
  bool operator!=(const BitSet& rhs);
  
  void Fill(const bool value);

  std::ostream& WriteTxt(std::ostream&) const;
  std::ostream& WriteBinary(std::ostream&) const;
  std::istream& ReadTxt(std::istream&);
  std::istream& RaadBinary(std::istream&);

private:
  std::vector<uint32_t> bits_;
  int32_t size_ = 0;
};

//std::istream& operator>>(std::istream& is, BitSet& rhs) noexcept ;
//std::ostream& operator<<(std::ostream& is, const BitSet& rhs) noexcept;

[[nodiscard]] BitSet operator&(const BitSet& lhs, const BitSet& rhs);
[[nodiscard]] BitSet operator|(const BitSet& lhs, const BitSet& rhs);
[[nodiscard]] BitSet operator^(const BitSet& lhs, const BitSet& rhs);
#endif // !BITSET_HPP
