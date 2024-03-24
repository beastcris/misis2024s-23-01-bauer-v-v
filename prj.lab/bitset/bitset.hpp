#ifndef BITSET_HPP
#define BITSET_HPP

#include <iosfwd>
#include <cstdint>
#include <vector>

const int32_t CEIL_NUM = 4294967296;

class BitSet {

public:
  BitSet() = default;
  BitSet(const int32_t cnt);
  BitSet(const BitSet& rhs);
  BitSet(BitSet&& rhs) noexcept;
  BitSet& operator=(const BitSet& rhs);
  BitSet& operator=(BitSet&& rhs) noexcept;
  ~BitSet() = default;

  int32_t Size() const noexcept;
  void Resize(const int32_t size);
  
  void Set(const int32_t idx, const bool value);
  bool Get(const int32_t idx);

  BitSet& operator&=(const BitSet& rhs);
  BitSet& operator|=(const BitSet& rhs);
  BitSet& operator^=(const BitSet& rhs);
  BitSet& operator~ ();

  bool operator==(const BitSet& rhs);
  bool operator!=(const BitSet& rhs);

  void Arr();
  void Fill(const bool value);

private:
  std::vector<uint32_t> bits_;
  int32_t size_ = 0;
};

#endif // !BITSET_HPP
