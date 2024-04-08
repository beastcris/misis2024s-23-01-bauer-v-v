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

TEST_CASE("operator[]") {
  BitSet a(20);
  a[1] = 1;
  CHECK_EQ(1, a.Get(1));

  CHECK_EQ(1, a[1]);
  if (a[1]) {
    a[1] = 0;
  }
  CHECK(!a[1]);
  while (!a[1]) {
    a[1] = 1;
  }

  bool fl1 = a[1];
  bool fl2;
  CHECK(fl1);
  fl1 = fl2 = a[1];
  CHECK_EQ(fl1, fl2);
  CHECK_EQ(fl2, a[1]);

  if (a[1] == 1) {
    CHECK(a[1] == 1);
    a[1] = 0;
  }
  CHECK(!a[1]);

  int32_t tm = 189;
  a[1] = tm;
  CHECK_EQ(a[1], 1);
}

TEST_CASE("ctor") {
  const std::int32_t num = 125;
  BitSet bs(num);
}

TEST_CASE("get | set") {
  BitSet bss;
  CHECK_THROWS(bss.Get(0));
  BitSet bs(11);
  CHECK_THROWS(bs.Get(15));
  CHECK_THROWS(bs.Get(11));
  CHECK(bs.Get(0) == 0);

  for (int i = 0; i < 11; i++) {
    bs.Set(i, 1);
  }
  BitSet bsss = BitSet(11);
  bsss.Fill(1);
  CHECK(bs == bsss);
}

TEST_CASE("operator==") {
  BitSet bs(120);
  BitSet bs2(120);
  CHECK(bs == bs2);
  CHECK_FALSE(bs == BitSet(123));
  BitSet bs3(120);
  CHECK(bs3 == bs);
  bs3.Set(119, 1);
  bool f = bs3 != bs;
  CHECK(f);
}

TEST_CASE("Fill && Get") {
  BitSet bs(32);
  bs.Fill(1);
  CHECK(bs.Get(30) == 1);
}

TEST_CASE("Edge case for size = 32 | Fill 'n' Set") {
  BitSet b1(32);
  b1.Fill(1);
  b1.Set(31, 0);
  BitSet b2(32);
  b2.Fill(1);
  b2.Set(30, 0);
  CHECK(b2 != b1);
  b2.Set(30, 1);
  b2.Set(31, 0);
  bool f = b1 == b2;
  // CHECK(f);
}

TEST_CASE("Resize") {
  // write resize properly (set requires elements to false)
  BitSet b1(110);
  b1.Fill(1);
  b1.Resize(98);
  BitSet b2(98);
  b2.Fill(1);
  CHECK(b1 == b2);
  b1.Resize(200);
}

TEST_CASE("Output") {
  BitSet a(39);

  a[0] = 1;
  a[4] = 1;
  a[11] = 1;
  std::cout << a;

  a[35] = 1;
  a[19] = 1;
  std::cout << a;

  BitSet b(7528);

  for (int32_t i = 0; i < b.Size(); ++i) {
    if (i % 3 == 0) {
      b[i] = 1;
    }
  }

  std::cout << b;
}

TEST_CASE("Input") {
  BitSet a(17);
  std::cin >> a;
  std::cout << a;
}