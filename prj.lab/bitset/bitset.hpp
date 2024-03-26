#ifndef BITSET_HPP
#define BITSET_HPP

#include <iosfwd>
#include <cstdint>
#include <vector>

const uint32_t CEIL_NUM = 4294967295;
const uint32_t FLOOR_NUM = 0;

class BitSet {

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
