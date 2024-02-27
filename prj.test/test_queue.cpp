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