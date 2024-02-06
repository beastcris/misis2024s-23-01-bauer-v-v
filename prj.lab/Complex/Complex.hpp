#pragma once
#ifndef COMPLEX_HPP
#define COMPLEX_HPP



#include <sstream>
#include <iostream>

struct Complex {
  //constructors and destructor
  Complex() = default;
  Complex(const double real);
  Complex(const double real, const double imaginary);
  Complex(const Complex& rhs) = default;
  ~Complex() = default;

  //assignment operator
  Complex& operator=(const Complex& rhs) = default;

  //logical operators
  [[nodiscard]] bool operator==(const Complex& cmp) const noexcept;
  [[nodiscard]] bool operator==(const double cmp) const noexcept;
  [[nodiscard]] bool operator!=(const Complex& cmp) const noexcept;
  [[nodiscard]] bool operator!=(const double cmp) const noexcept;

  //assignment opearations
  Complex& operator+= (const Complex& comp) noexcept;
  Complex& operator+= (const double ins) noexcept;
  Complex& operator-= (const Complex& comp) noexcept;
  Complex& operator-= (const double ins) noexcept;
  Complex& operator*= (const Complex& comp) noexcept;
  Complex& operator*= (const double ins) noexcept;
  Complex& operator/= (const Complex& comp);
  Complex& operator/= (const double ins);

  [[nodiscard]] Complex operator-() const noexcept;
  //fields
  double re{ 0.0 };
  double im{ 0.0 };

  //input-output methods
  std::ostream& WriteTo(std::ostream& ostrm) const noexcept;
  std::istream& ReadFrom(std::istream& istrm) noexcept;

  static const char leftBrace{ '{' };
  static const char separator{ ',' };
  static const char rightBrace{ '}' };
};



//add operator
[[nodiscard]] Complex operator+(const Complex& lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator+ (const Complex& lhs, const double& rhs) noexcept;
[[nodiscard]] Complex operator+ (const double lhs, const Complex& rhs) noexcept;

//sub operator
[[nodiscard]] Complex operator-(const Complex& lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator- (const Complex& lhs, const double& rhs) noexcept;
[[nodiscard]] Complex operator- (const double lhs, const Complex& rhs) noexcept;

//multiple ooperator
[[nodiscard]] Complex operator* (const Complex& lhs, const Complex rhs) noexcept;
[[nodiscard]] Complex operator* (const Complex& lhs, const double& rhs) noexcept;
[[nodiscard]] Complex operator* (const double lhs, const Complex& rhs) noexcept;

//div operator
[[nodiscard]] Complex operator/ (const Complex& lhs, const Complex rhs);
[[nodiscard]] Complex operator/ (const Complex& lhs, const double& rhs);
[[nodiscard]] Complex operator/ (const double lhs, const Complex& rhs);

//input-output operators
std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) noexcept;
std::istream& operator>>(std::istream& is, Complex& comp) noexcept;

#endif