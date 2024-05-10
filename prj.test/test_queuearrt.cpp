#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN


#include <queuearrt/queuearrt.hpp>
#include <Complex/Complex.hpp>
#include <chrono>
#include "doctest.h"
#include <iostream>

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
void check_eq(QueueArrT<T>& lhs, QueueArrT<T>& rhs) {
  while (!lhs.IsEmpty()) {
    CHECK_EQ(lhs.Top(), rhs.Top());
    lhs.Pop();
    rhs.Pop();
  }
}

TEST_CASE_TEMPLATE("", T, int, double, Complex) {
  std::vector<T> values;
  int size = 10;
  get_values(values, size);

  SUBCASE("Basic methods") {
    QueueArrT<T> q1;
    CHECK(q1.IsEmpty());
    q1.Push(values[0]);
    CHECK_EQ(q1.Top(), values[0]);
    q1.Pop();
    CHECK(q1.IsEmpty());

    QueueArrT<T> q2;
    for (int i = 0; i < 3; i++) {
      q1.Push(values[i]);
      q2.Push(values[i]);
      CHECK(q1.Top() == q2.Top());
      q1.Pop(); q2.Pop();
    }

    CHECK(q1.IsEmpty());
    CHECK(q2.IsEmpty());

    for (int i = 1; i <= 3; i++) {
      q1.Push(values[i]);
    }
    q1.Pop();
    q1.Pop();
    q1.Push(values[5]);

    QueueArrT<T> q3(q1);

    while (!q1.IsEmpty()) {
      CHECK(q1.Top() == q3.Top());
      CHECK(&q1.Top() != &q3.Top());
      q1.Pop();
      q3.Pop();
    }
    CHECK_THROWS(q1.Top());
    CHECK_THROWS(q3.Top());
  }

  SUBCASE("Copying constructor and operator=") {
    QueueArrT<T> q1;
    QueueArrT<T> q2;

    q1.Push(values[0]);
    q1.Push(values[1]);

    q2 = q1;

    while (!q2.IsEmpty()) {
      CHECK_EQ(q1.Top(), q2.Top());
      q1.Pop();
      q2.Pop();
    }
    CHECK(q1.IsEmpty());

    q1.Push(values[0]);
    q1.Push(values[1]);
    q1.Push(values[0]);
    q1.Push(values[1]);
    q1.Push(values[0]);
    q1.Push(values[1]);
    q1.Push(values[0]);
    q1.Push(values[1]);

    q1.Pop();
    q1.Pop();
    q1.Pop();
    q1.Pop();
    q1.Pop();
    q1.Pop();

    q1.Push(values[1]);
    q1.Push(values[0]);
    q1.Push(values[1]);
    q1.Push(values[0]);
    q1.Push(values[1]);


    q2 = q1;
    q2.Push(values[3]);

    while (!q1.IsEmpty()) {
      CHECK_EQ(q1.Top(), q2.Top());
      q1.Pop();
      q2.Pop();
    }
    CHECK(q1.IsEmpty());
    q2.Pop();
    CHECK(q2.IsEmpty());
  }


  SUBCASE("move semantics") {
    QueueArrT<T> a;


    for (int i = 0; i < 10000; ++i) {
      a.Push(values[0]);
      a.Push(values[1]);
      a.Push(values[2]);
    }
    QueueArrT<T> b;
    b.Push(values[0]);
    b.Push(values[1]);
    b.Push(values[2]);
    QueueArrT<T> c(a);
    QueueArrT<T> d(a);

    auto start1 = std::chrono::high_resolution_clock::now();
    b = std::move(a);
    auto end1 = std::chrono::high_resolution_clock::now();

    auto res1 = std::chrono::duration<float>{ end1 - start1 };

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
}


