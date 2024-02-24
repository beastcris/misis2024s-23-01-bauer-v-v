#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


#include <stacklst/stacklst.hpp>

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