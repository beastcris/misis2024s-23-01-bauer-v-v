#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queuelst/queuelst.hpp>
#include <iostream>
#include <chrono>

TEST_CASE("base") {
  QueueLst a;

  Complex first_complex(3, 5);
  Complex second_complex(2, 7);
  
  a.Push(second_complex);
  a.Push(first_complex);
  a.Push(first_complex);


  CHECK_EQ(a.Top(), second_complex);
  a.Pop();
  CHECK_EQ(a.Top(), first_complex);
  a.Pop();
  CHECK_EQ(a.Top(), first_complex);


  a.Push(second_complex);
  a.Push(second_complex);
  QueueLst b(a);
  CHECK_EQ(a.Top(), first_complex);
  a.Pop();
  CHECK_EQ(a.Top(), second_complex);
  a.Push(first_complex);
  CHECK_EQ(a.Top(), second_complex);
  a.Pop();
  a.Pop();
  CHECK_EQ(a.Top(), first_complex);


  a.Clear();
  a.Push(second_complex);
  a.Push(second_complex);
  b.Clear();
  b = a;
  CHECK_EQ(a.Top(), second_complex);
  a.Pop();
  b.Pop();
  CHECK_EQ(a.Top(), second_complex);
  a.Push(first_complex);
  b.Push(second_complex);
  a.Pop();
  b.Pop();
  CHECK((a.Top() == b.Top()) == false);

  a.Push(first_complex);
  a.Push(first_complex);
  a.Push(first_complex);
  a = b;
  CHECK_EQ(a.Top(), b.Top());
  b.Clear();
  CHECK(b.IsEmpty());
  a.Clear();
  a.Push(second_complex);
  a.Push(first_complex);
  a.Push(first_complex);


  CHECK_EQ(a.Top(), second_complex);
  a.Pop();
  CHECK_EQ(a.Top(), first_complex);
  a.Pop();
  CHECK_EQ(a.Top(), first_complex);

  a.Clear();
  a.Push(first_complex);
  a.Pop();
  CHECK(a.IsEmpty());


  a.Push(first_complex);
  a.Push(first_complex);
  a.Push(first_complex);
  a.Push(first_complex);
  b.Push(second_complex);
  a = b;
  CHECK_EQ(a.Top(), b.Top());
  a.Push(first_complex);
  CHECK_EQ(second_complex, a.Top());
  a.Pop();
  CHECK_EQ(first_complex, a.Top());

  QueueLst c;
  c = b;
  CHECK_EQ(c.Top(), b.Top());
  c.Push(first_complex);
  CHECK_EQ(second_complex, c.Top());
  c.Pop();
  CHECK_EQ(first_complex, c.Top());

  a.Clear();
  CHECK_THROWS(a.Top());
  std::cout << 1;
}

TEST_CASE("move semantics") {
  QueueLst a;

  float first_num = 0;
  float second_num = 1.5;
  float third_num = 3.0;

  for (int i = 0; i < 10000; ++i) {
    a.Push(first_num);
    a.Push(second_num);
    a.Push(third_num);
  }
  QueueLst b;
  b.Push(first_num);
  b.Push(second_num);
  b.Push(third_num);
  QueueLst c(a);
  QueueLst d(a);

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
