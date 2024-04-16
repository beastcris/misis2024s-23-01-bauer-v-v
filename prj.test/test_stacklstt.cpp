#include <stacklstt/stacklstt.hpp>
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


TEST_CASE_TEMPLATE("based", T, int, double, Complex, std::string, bool) {
  std::vector<T> values;
  int size = 10;
  get_values(values, size);
  SUBCASE("operator=") {
    StackLstT<T> a;
    
    for (int i = 0; i < values.size(); ++i) {
      a.Push(values[i]);
    }

    StackLstT<T> b;
    b = a;

    while (!a.IsEmpty()) {
      CHECK_EQ(a.Top(), b.Top());
      a.Pop();
      b.Pop();
    }
  }

  SUBCASE("move semantics") {
    StackLstT<T> a;


    for (int i = 0; i < 10000; ++i) {
      a.Push(values[i % 10]);
      a.Push(values[i % 10]);
    }
    StackLstT<T> b;
    b.Push(values[0]);
    b.Push(values[1]);
    b.Push(values[2]);
    StackLstT<T> c(a);
    StackLstT<T> d(a);

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