#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <bitset/bitset.hpp>

TEST_CASE("Based") {
  BitSet a(32);

  for (int32_t i = 0; i < a.Size(); ++i) {
    CHECK_EQ(false, a.Get(i));
  }

  std::vector<int32_t> idxes = { 0, 7, 17, 31 };
  for (int32_t i = 0; i < idxes.size(); ++i) {
    a.Set(idxes[i], 1);
  }
  for (int32_t i = 0; i < idxes.size(); ++i) {
    CHECK_EQ(1, a.Get(idxes[i]));
  }

  BitSet b(17);
  BitSet c(13);
  BitSet d(17);
  CHECK(!(c == b));
  CHECK(b == d);
  b.Set(13, 1);
  d.Set(13, 1);
  CHECK(b == d);
  d.Set(13, 0);
  CHECK(!(b == d));
  d.Set(13, 1);
  d.Set(13, 1);
  CHECK(b == d);


  d.Fill(1);
  for (int32_t i = 0; i < d.Size(); ++i) {
    CHECK_EQ(1, d.Get(i));
  }
  d.Fill(0);
  for (int32_t i = 0; i < d.Size(); ++i) {
    CHECK_EQ(0, d.Get(i));
  }

  int32_t Size = a.Size() + 10;
  CHECK_THROWS(a.Get(-5));
  CHECK_THROWS(a.Get(Size));
  CHECK_THROWS(a.Set(-5, 1));
  CHECK_THROWS(a.Set(Size, 1));
  CHECK_THROWS(a.Resize(0));
  CHECK_THROWS(a.Resize(-1));
}