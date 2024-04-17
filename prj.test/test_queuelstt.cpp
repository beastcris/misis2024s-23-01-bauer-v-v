#include <queuelstt/queuelstt.hpp>
#include <Complex/Complex.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <chrono>

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
void check_eq(QueueLstT<T>& lhs, QueueLstT<T>& rhs) {
  while (!lhs.IsEmpty()) {
    CHECK_EQ(lhs.Top(), rhs.Top());
    lhs.Pop();
    rhs.Pop();
  }
}

TEST_CASE_TEMPLATE("based", T, int, double, Complex, std::string, bool) {
  std::vector<T> values;
  int size = 10;
  get_values(values, size);

  SUBCASE("base") {
    QueueLstT<T> a;
    QueueLstT<T> b;

    a.Push(values[2]);
    a.Push(values[1]);
    a.Push(values[1]);


    CHECK_EQ(a.Top(), values[2]);
    a.Pop();
    CHECK_EQ(a.Top(), values[1]);
    a.Pop();
    CHECK_EQ(a.Top(), values[1]);



    a.Clear();
    CHECK(a.IsEmpty());

    a.Push(values[2]);
    a.Push(values[2]);
    a.Clear();
    b = a;
    CHECK(b.IsEmpty());
    CHECK_THROWS(b.Top());
    a.Push(values[2]);
    a.Push(values[2]);
    CHECK_EQ(a.Top(), values[2]);
    a.Pop();
    CHECK_EQ(a.Top(), values[2]);
  }
  SUBCASE("copy ctor") {
    QueueLstT<T> a;

    for (int i = 0; i < size; ++i) {
      a.Push(values[i]);
      if (i % 5 == 0) {
        a.Pop();
      }
    }

    QueueLstT<T> b(a);

    check_eq(a, b);
  }

  SUBCASE("operator=") {
    QueueLstT<T> a;


    for (int i = 0; i < size; ++i) {
      a.Push(values[i]);
      if (i % 5 == 0) {
        a.Pop();
      }
    }

    QueueLstT<T> b;
    b = a;

    check_eq(a, b);

    for (int i = 0; i < size; ++i) {
      a.Push(values[i]);
      if (i % 5 == 0) {
        a.Pop();
      }
    }

    b.Push(values[1]);
    b.Push(values[1]);

    b = a;
    check_eq(a, b);
  }

  SUBCASE("move semantics") {
    QueueLstT<T> a;

    for (int i = 0; i < 10000; ++i) {
      a.Push(values[i % size]);
      a.Push(values[i % size]);
    }
    QueueLstT<T> b;
    b.Push(values[0]);
    b.Push(values[1]);
    b.Push(values[2]);
    QueueLstT<T> c(a);
    QueueLstT<T> d(a);

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