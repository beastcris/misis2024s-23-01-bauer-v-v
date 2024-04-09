#include <stacklstt/stacklstt.hpp>
#include <Complex/Complex.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <chrono>


using StackLst = StackLstT<Complex>;

TEST_CASE("operator=") {
  StackLst a;
  Complex first = { 1,0 };
  Complex sec = { 3,4 };
  Complex third = { 0,0 };

  a.Push(first);
  a.Push(sec);
  a.Push(third);

  StackLst b;
  b = a;
  CHECK_EQ(a.Top(), b.Top());
  a.Pop();
  b.Pop();
  CHECK_EQ(a.Top(), b.Top());
  a.Pop();
  b.Pop();
  CHECK_EQ(a.Top(), b.Top());
  a.Pop();
  b.Pop();

  a.Push(first);
  a.Push(first);
  a.Push(first);
  b.Push(first);
  b.Push(sec);
  b.Push(third);
  b.Push(sec);
  b = a;
  CHECK_EQ(a.Top(), b.Top());
  a.Pop();
  b.Pop();
  CHECK_EQ(a.Top(), b.Top());
  a.Pop();
  b.Pop();
  CHECK_EQ(a.Top(), b.Top());
  a.Pop();
  b.Pop();
}


TEST_CASE("move semantics") {
  StackLst a;

  float first_num = 0;
  float second_num = 1.5;
  float third_num = 3.0;

  for (int i = 0; i < 10000; ++i) {
    a.Push(first_num);
    a.Push(second_num);
    a.Push(third_num);
  }
  StackLst b;
  b.Push(first_num);
  b.Push(second_num);
  b.Push(third_num);
  StackLst c(a);
  StackLst d(a);

  auto start1 = std::chrono::high_resolution_clock::now();
  b = std::move(a);
  auto end1 = std::chrono::high_resolution_clock::now();

  auto res1 = std::chrono::duration<float>{ end1 - start1 };

  std::cout << res1 << '\n';

  while (!c.IsEmpty()) {
    CHECK_EQ(c.Top(), b.Top());
    c.Pop();
    b.Pop();
  }

  auto start2 = std::chrono::high_resolution_clock::now();
  a = d;
  auto end2 = std::chrono::high_resolution_clock::now();

  auto res2 = std::chrono::duration<float>{ end2 - start2 };

  std::cout << res2;

  while (!d.IsEmpty()) {
    CHECK_EQ(a.Top(), d.Top());
    d.Pop();
    a.Pop();
  }
}