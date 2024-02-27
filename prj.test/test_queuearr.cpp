#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queuearr/queuearr.hpp>

TEST_CASE("base") {
  QueueArr a;
  
  Complex first_complex = { 3.4, 2.9 };
  Complex second_complex = { 0,0 };

  a.Push(first_complex);
  CHECK_EQ(a.Top(), first_complex);
  a.Push(second_complex);
  a.Push(second_complex);
  CHECK_EQ(a.Top(), first_complex);
  a.Pop();
  CHECK_EQ(a.Top(), second_complex);
  a.Push(first_complex);
  a.Push(first_complex);
  a.Push(second_complex);

  a.Push(second_complex);

  CHECK_EQ(a.Top(), second_complex);
  a.Pop();
  CHECK_EQ(a.Top(), second_complex);
  a.Pop();
  CHECK_EQ(a.Top(), first_complex);
  a.Pop();
  CHECK_EQ(a.Top(), first_complex);
  a.Pop();
  CHECK_EQ(a.Top(), second_complex);
  a.Pop();
  CHECK_EQ(a.Top(), second_complex);
  a.Pop();
  CHECK(a.IsEmpty());

  a.Push(first_complex);
  a.Push(second_complex);
  a.Push(first_complex);
  a.Push(second_complex);
  a.Push(first_complex);
  a.Push(second_complex);
  QueueArr b(a);

  while (!a.IsEmpty()) {
    CHECK_EQ(a.Top(), b.Top());
    a.Pop();
    b.Pop();
  }

  a.Push(first_complex);
  a.Push(second_complex);
  a.Pop();
  a.Push(first_complex);
  a.Push(second_complex);
  a.Push(first_complex);
  QueueArr c(a);

  while (!a.IsEmpty()) {
    CHECK_EQ(a.Top(), c.Top());
    a.Pop();
    c.Pop();
  }

  a.Push(first_complex);
  a.Push(second_complex);
  a.Pop();
  a.Push(first_complex);
  a.Push(second_complex);
  a.Push(first_complex);
  b = a;

  while (!a.IsEmpty()) {
    CHECK_EQ(a.Top(), b.Top());
    a.Pop();
    b.Pop();
  }

  b.Push(first_complex);
  b.Clear();
  CHECK(b.IsEmpty());

  CHECK_THROWS(a.Top());
}