#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queuelstpr/queuelstpr.hpp>

TEST_CASE("BASE METHODS") {
  QueueLstPr a;
  float first_num = 0;
  float second_num = 1.5;
  float third_num = 3.0;

  CHECK(a.IsEmpty());
  a.Push(first_num);
  CHECK_EQ(a.Top(), first_num);
  a.Pop();
  CHECK(a.IsEmpty());

  a.Push(third_num);
  a.Push(first_num);
  CHECK_EQ(a.Top(), first_num);
  a.Pop();
  CHECK_EQ(a.Top(), third_num);
  a.Pop();
  a.IsEmpty();
  CHECK_THROWS(a.Top());

  a.Push(third_num);
  a.Push(first_num);
  a.Push(second_num);
  CHECK_EQ(a.Top(), first_num);
  a.Pop();
  CHECK_EQ(a.Top(), second_num);
  a.Pop();
  CHECK_EQ(a.Top(), third_num);
  a.Pop();
  a.IsEmpty();

  a.Push(third_num);
  a.Push(first_num);
  a.Push(second_num);
  a.Clear();
  a.IsEmpty();
}

TEST_CASE("operator=") {
  QueueLstPr a;

  float first_num = 0;
  float second_num = 1.5;
  float third_num = 3.0;

  a.Push(first_num);
  a.Push(first_num);
  a.Push(second_num);

  QueueLstPr b;
  b.Push(third_num);
  b = a;


  while (!a.IsEmpty()) {
    CHECK_EQ(a.Top(), b.Top());
    a.Pop();
    b.Pop();
  }

  b.Push(first_num);
  b = a;
  CHECK(b.IsEmpty());

  a.Push(first_num);
  b.Push(second_num);
  b.Push(second_num);
  b = a;
  while (!a.IsEmpty()) {
    CHECK_EQ(a.Top(), b.Top());
    a.Pop();
    b.Pop();
  }
}

TEST_CASE("copy ctor") {
  QueueLstPr a;

  float first_num = 0;
  float second_num = 1.5;
  float third_num = 3.0;

  a.Push(first_num);
  a.Push(first_num);
  a.Push(second_num);

  QueueLstPr b(a);

  while (!a.IsEmpty()) {
    CHECK_EQ(a.Top(), b.Top());
    a.Pop();
    b.Pop();
  }
  CHECK(b.IsEmpty());
  
  QueueLstPr c(b);
  CHECK(c.IsEmpty());
}

