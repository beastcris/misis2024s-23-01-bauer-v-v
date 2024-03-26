#ifndef BITSET_HPP
#define BITSET_HPP

#include <iosfwd>
#include <cstdint>
#include <vector>

const uint32_t CEIL_NUM = 4294967295;
const uint32_t FLOOR_NUM = 0;

struct BiA;

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
      bool operator==(bool value) { return (value == this->bst_.Get(this->idx_)); }

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
  [[nodiscard]] bool Get(const int32_t idx);

  BitSet& operator&=(const BitSet& rhs);
  BitSet& operator|=(const BitSet& rhs);
  BitSet& operator^=(const BitSet& rhs);
  BitSet& operator~ ();
  
  BiA operator[](const int32_t idx);

  bool operator==(const BitSet& rhs);
  bool operator!=(const BitSet& rhs);
  
  void Arr();
  void Fill(const bool value);

private:
  std::vector<uint32_t> bits_;
  int32_t size_ = 0;
};


[[nodiscard]] BitSet operator&(const BitSet& lhs, const BitSet& rhs);

[[nodiscard]] BitSet operator|(const BitSet& lhs, const BitSet& rhs);

[[nodiscard]] BitSet operator^(const BitSet& lhs, const BitSet& rhs);

#endif // !BITSET_HPP
