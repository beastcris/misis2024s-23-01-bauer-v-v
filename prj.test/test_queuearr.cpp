#include <queuearr/queuearr.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

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
  QueueArr q3;
  q3.Push(Complex(1, 1));

  for (int i = 1; i <= 2; i++) {
    q1.Push(Complex(i, i * i));
    q2.Push(Complex(2 * i, 2 * i * 2 * i));
  }
  q2.Pop();


  q1 = q2;
  QueueArr q4(q1);
  while (!q1.IsEmpty()) {
    CHECK(&q1.Top() != &q2.Top());
    CHECK(q1.Top() == q2.Top());
    q2.Pop(); q1.Pop();
  }

  q3 = q4;
  while (!q3.IsEmpty()) {
    CHECK(&q3.Top() != &q4.Top());
    CHECK(q3.Top() == q4.Top());
    q3.Pop(); q4.Pop();
  }
}
