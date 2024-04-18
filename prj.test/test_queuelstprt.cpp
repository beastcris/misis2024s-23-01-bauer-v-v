#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <chrono>
#include <queuelstprt/queuelstprt.hpp>

template<class T>
void get_values(std::vector<T>& values, int& size) {
  for (int i = 0; i < 10; ++i) {
    values.push_back(i);
  }
}
template<>
void get_values(std::vector<std::string>& values, int& size) {
  for (int i = 0; i < 10; ++i) {
    values.push_back(std::to_string(i));
  }
}
template<>
void get_values(std::vector<bool>& values, int& size) {
  for (int i = 0; i < 10; ++i) {
    if (i % 2 == 0) {
      values.push_back(1);
    }
    else {
      values.push_back(0);
    }
  }
}

template<class T>
void check_eq(QueueLstPrT<T>& lhs, QueueLstPrT<T>& rhs) {
  while (!lhs.IsEmpty()) {
    CHECK_EQ(lhs.Top(), rhs.Top());
    lhs.Pop();
    rhs.Pop();
  }
}

TEST_CASE_TEMPLATE("test", T, int, float, double, long long) {
  std::vector<T> values;
  int size = 10;
  get_values(values, size);

  SUBCASE("BASE METHODS") {
    QueueLstPrT<T> a;

    CHECK(a.IsEmpty());
    a.Push(values[0]);
    CHECK_EQ(a.Top(), values[0]);
    a.Pop();
    CHECK(a.IsEmpty());

    a.Push(values[2]);
    a.Push(values[1]);
    CHECK_EQ(a.Top(), values[1]);
    a.Pop();
    CHECK_EQ(a.Top(), values[2]);
    a.Pop();
    a.IsEmpty();
    CHECK_THROWS(a.Top());

    a.Push(values[2]);
    a.Push(values[0]);
    a.Push(values[1]);
    CHECK_EQ(a.Top(), values[0]);
    a.Pop();
    CHECK_EQ(a.Top(), values[1]);
    a.Pop();
    CHECK_EQ(a.Top(), values[2]);
    a.Pop();
    a.IsEmpty();

    a.Push(values[2]);
    a.Push(values[0]);
    a.Push(values[1]);
    a.Clear();
    a.IsEmpty();
  }

  SUBCASE("operator=") {
    QueueLstPrT<T> a;

    a.Push(values[0]);
    a.Push(values[0]);
    a.Push(values[1]);

    QueueLstPrT<T> b;
    b.Push(values[5]);

    b = a;
    check_eq(a, b);
    CHECK(a.IsEmpty());
    CHECK(b.IsEmpty());
  }

  SUBCASE("copy ctor") {
    QueueLstPrT<T> a;

    a.Push(values[0]);
    a.Push(values[0]);
    a.Push(values[1]);

    QueueLstPrT<T> b(a);

    check_eq(a, b);
    CHECK(b.IsEmpty());

    QueueLstPrT<T> c(b);
    CHECK(c.IsEmpty());
  }
  SUBCASE("move semantics") {
    QueueLstPrT<T> a;

    for (int i = 0; i < 10000; ++i) {
      a.Push(values[i % size]);
      a.Push(values[i % size]);
    }
    QueueLstPrT<T> b;
    b.Push(values[0]);
    b.Push(values[1]);
    b.Push(values[2]);
    QueueLstPrT<T> c(a);
    QueueLstPrT<T> d(a);

    auto start1 = std::chrono::high_resolution_clock::now();
    b = std::move(a);
    auto end1 = std::chrono::high_resolution_clock::now();

    auto res1 = std::chrono::duration<float>{ end1 - start1 };

    std::cout << res1 << '\n';

    check_eq(c, b);

    auto start2 = std::chrono::high_resolution_clock::now();
    a = d;
    auto end2 = std::chrono::high_resolution_clock::now();

    auto res2 = std::chrono::duration<float>{ end2 - start2 };

    std::cout << res2;

    check_eq(d, a);
  }
}