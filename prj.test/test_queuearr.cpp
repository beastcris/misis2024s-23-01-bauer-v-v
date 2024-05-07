#include <queuearr/queuearr.hpp>
#include <chrono>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>

TEST_CASE("Basic methods") {
  QueueArr q1;
  CHECK(q1.IsEmpty());
  q1.Push(Complex(1, 1));
  CHECK(!q1.IsEmpty());
  q1.Pop();
  CHECK(q1.IsEmpty());

  QueueArr q2;
  for (int i = 0; i < 3; i++) {
    q1.Push(Complex(i, i));
    q2.Push(Complex(i, i));
    CHECK(q1.Top() == q2.Top());
    q1.Pop(); q2.Pop();
  }

  CHECK(q1.IsEmpty());
  CHECK(q2.IsEmpty());

  for (int i = 1; i <= 3; i++) {
    q1.Push(Complex(i, i * i));
  }
  q1.Pop();
  q1.Pop();
  q1.Push(Complex(5, 1));
  
  QueueArr q3(q1);

  while (!q1.IsEmpty()) {
    CHECK(q1.Top() == q3.Top());
    CHECK(&q1.Top() != &q3.Top());
    q1.Pop();
    q3.Pop();
  }
  CHECK_THROWS(q1.Top());
  CHECK_THROWS(q3.Top());
}

TEST_CASE("Copying constructor and operator=") {
  QueueArr q1;
  QueueArr q2;
  
  q1.Push(1);
  q1.Push(2);

  q2 = q1;

  while (!q2.IsEmpty()) {
    CHECK_EQ(q1.Top(), q2.Top());
    q1.Pop();
    q2.Pop();
  }
  CHECK(q1.IsEmpty());

  q1.Push(1);
  q1.Push(2);
  q1.Push(1);
  q1.Push(2);
  q1.Push(1);
  q1.Push(2);
  q1.Push(1);
  q1.Push(2);

  q1.Pop();
  q1.Pop();
  q1.Pop();
  q1.Pop();
  q1.Pop();
  q1.Pop();

  q1.Push(2);
  q1.Push(1);
  q1.Push(2);
  q1.Push(1);
  q1.Push(2);

  q2 = q1;
  q2.Push(3);
  CHECK_EQ(q2.Top(), 1);

  while (!q1.IsEmpty()) {
    CHECK_EQ(q1.Top(), q2.Top());
    q1.Pop();
    q2.Pop();
  }
  CHECK(q1.IsEmpty());
  CHECK_EQ(q2.Top(), 3);
  q2.Pop();
  CHECK(q2.IsEmpty());
}


TEST_CASE("move semantics") {
  QueueArr a;

  float first_num = 0;
  float second_num = 1.5;
  float third_num = 3.0;

  for (int i = 0; i < 10000; ++i) {
    a.Push(first_num);
    a.Push(second_num);
    a.Push(third_num);
  }
  QueueArr b;
  b.Push(first_num);
  b.Push(second_num);
  b.Push(third_num);
  QueueArr c(a);
  QueueArr d(a);

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
