#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <chrono>
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
  b.Push(1);

  b = a;
  while (!b.IsEmpty()) {
    CHECK_EQ(a.Top(), b.Top());
    a.Pop();
    b.Pop();
  }
  CHECK(a.IsEmpty());
  CHECK(b.IsEmpty());
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

TEST_CASE("move semantics") {
  QueueLstPr a;

  float first_num = 0;
  float second_num = 1.5;
  float third_num = 3.0;

  for (int i = 0; i < 10000; ++i) {
    a.Push(first_num);
    a.Push(second_num);
    a.Push(third_num);
  }
  QueueLstPr b;
  b.Push(first_num);
  b.Push(second_num);
  b.Push(third_num);
  QueueLstPr c(a);
  QueueLstPr d(a);

  auto start1 = std::chrono::high_resolution_clock::now();
  b = std::move(a);
  auto end1 = std::chrono::high_resolution_clock::now();

  auto res1 = std::chrono::duration<float> {end1 - start1};

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

