#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queuelst/queuelst.hpp>

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
  QueueLst b = a;
  CHECK_EQ(a.Top(), first_complex);
  a.Pop();
  CHECK_EQ(a.Top(), second_complex);
  a.Push(first_complex);
  CHECK_EQ(a.Top(), second_complex);
  a.Pop();
  a.Pop();
  CHECK_EQ(a.Top(), first_complex);
}