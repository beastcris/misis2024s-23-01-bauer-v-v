#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <chrono>
#include <stackarr/stackarr.hpp>

TEST_CASE("stackarr test") {
  StackArr my_stack;
  CHECK_THROWS(my_stack.Top());
  CHECK(my_stack.IsEmpty());
  Complex first_complex(3, 5);
  Complex second_complex(2, 7);

  my_stack.Push(first_complex);
  my_stack.Push(second_complex);

  CHECK_EQ(my_stack.Top(), second_complex);
  my_stack.Pop();
  CHECK_EQ(my_stack.Top(), first_complex);

  Complex third_complex(1, 1);

  StackArr my_stack2;
  my_stack2.Push(third_complex);
  StackArr a(my_stack2);
  CHECK_EQ(a.Top(), third_complex);

  Complex fourth_complex(2.3, 7.3);

  Complex fifth_complex(2.003, 0);

  my_stack.Push(fourth_complex);
  CHECK_EQ(my_stack.Top(), fourth_complex);
  my_stack.Push(fifth_complex);
  CHECK_EQ(my_stack.Top(), fifth_complex);

  StackArr eq1;
  StackArr eq2;
  eq1.Push(first_complex);
  eq1.Push(second_complex);
  eq1.Push(third_complex);
  eq2 = eq1;
  CHECK_EQ(eq2.Top(), third_complex);
  eq1.Pop();
  eq2.Pop();
  CHECK_EQ(eq1.Top(), eq2.Top());
  eq1.Pop();
  eq2.Pop();
  CHECK_EQ(eq1.Top(), eq2.Top());
  eq1.Pop();
  eq2.Pop();
  CHECK(eq1.IsEmpty());
  CHECK(eq2.IsEmpty());
}

TEST_CASE("Top method tests") {
  Complex compl1 = Complex(2.4, 1.5);
  StackArr stack1 = StackArr();
  stack1.Push(compl1);
  stack1.Top() = Complex(0.0, 0.0);
  CHECK_EQ(stack1.Top(), Complex(0.0, 0.0));
}

TEST_CASE("copy ctor") {
  StackArr a;
  Complex first_complex(3, 5);
  Complex second_complex(2, 7);

  a.Push(first_complex);
  a.Push(second_complex);

  StackArr b(a);

  CHECK_EQ(b.Top(), second_complex);
  b.Pop();
  CHECK_EQ(b.Top(), first_complex);
}

TEST_CASE("move semantics") {
  StackArr a;

  Complex first_num = 0;
  Complex second_num = 1.5;
  Complex third_num = 3.0;

  for (int i = 0; i < 100; ++i) {
    a.Push(first_num);
    a.Push(second_num);
    a.Push(third_num);
  }
  StackArr b;
  b.Push(first_num);
  b.Push(second_num);
  b.Push(third_num);
  StackArr c(a);
  StackArr d(a);

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