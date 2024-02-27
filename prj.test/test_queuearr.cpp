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
}