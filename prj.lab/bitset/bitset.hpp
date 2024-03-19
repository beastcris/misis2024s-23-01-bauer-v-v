

#ifndef BITSET_HPP
#define BITSET_HPP

#include <vector>

class BitSet {

public:
  BitSet();
  BitSet(const int32_t);
  BitSet(const BitSet& rhs);
  BitSet(BitSet&& rhs);
  BitSet& operator=(const BitSet& rhs);
  BitSet& operator=(BitSet&& rhs);
  ~BitSet();

  int32_t Size() const noexcept;
  void Resize(const int32_t size);
  
  void Set(const int32_t idx, const bool value);
  bool Get(const int32_t idx);

  void Fill(const bool value);

private:
  std::vector<uint32_t> bits_;
  int32_t size_ = 0;
};

#endif // !BITSET_HPP
