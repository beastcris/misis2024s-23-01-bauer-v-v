#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <chrono>
#include <stackarrt/stackarrt.hpp>
#include <Complex/Complex.hpp>

template<class T>
void check_eq(StackArrT<T>& lhs, StackArrT<T>& rhs) {
  while (!lhs.IsEmpty()) {
    CHECK_EQ(lhs.Top(), rhs.Top());
    lhs.Pop();
    rhs.Pop();
  }
}

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


TEST_CASE_TEMPLATE(" ", T, int, bool, float, Complex, std::string) {
  std::vector<T> values;
  int size = 10;
  get_values(values, size);

  SUBCASE("stackarr test") {
    StackArrT<T> my_stack;
    CHECK_THROWS(my_stack.Top());
    CHECK(my_stack.IsEmpty());

    my_stack.Push(values[0]);
    my_stack.Push(values[1]);

    CHECK_EQ(my_stack.Top(), values[1]);
    my_stack.Pop();
    CHECK_EQ(my_stack.Top(), values[0]);


    StackArrT<T> my_stack2;
    my_stack2.Push(values[2]);
    StackArrT<T> a(my_stack2);
    CHECK_EQ(a.Top(), values[2]);


    my_stack.Push(values[3]);
    CHECK_EQ(my_stack.Top(), values[3]);
    my_stack.Push(values[4]);
    CHECK_EQ(my_stack.Top(), values[4]);

    StackArrT<T> eq1;
    StackArrT<T> eq2;
    eq1.Push(values[0]);
    eq1.Push(values[1]);
    eq1.Push(values[2]);
    eq2 = eq1;
    check_eq(eq1, eq2);
  }

  SUBCASE("Top method tests") {
    StackArrT<T> stack1;
    stack1.Push(values[0]);
    stack1.Top() = values[1];
    CHECK_EQ(stack1.Top(), values[1]);
  }

  SUBCASE("copy ctor") {
    StackArrT<T> a;

    a.Push(values[1]);
    a.Push(values[2]);

    StackArrT<T> b(a);

    CHECK_EQ(b.Top(), values[2]);
    b.Pop();
    CHECK_EQ(b.Top(), values[1]);
  }

  SUBCASE("move semantics") {
    StackArrT<T> a;

    for (int i = 0; i < 10000; ++i) {
      a.Push(values[i % size]);
      a.Push(values[i % size]);
    }
    StackArrT<T> b;
    b.Push(values[0]);
    b.Push(values[1]);
    b.Push(values[2]);
    StackArrT<T> c(a);
    StackArrT<T> d(a);

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
