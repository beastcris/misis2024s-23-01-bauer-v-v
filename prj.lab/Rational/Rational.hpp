#pragma once
#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include <cstdint>

class Rational {

public:
  Rational() = default;
  Rational(int64_t num);
  Rational(const Rational& rhs) = default;

  Rational(int64_t num, int64_t den);

  ~Rational() = default;
  Rational& operator=(const Rational& rhs) = default;

  bool operator==(const Rational& rhs) const noexcept;
  bool operator!=(const Rational& rhs) const noexcept;

  bool operator<(const Rational& rhs) const noexcept;
  bool operator<=(const Rational& rhs) const noexcept;
  bool operator>(const Rational& rhs) const noexcept;
  bool operator>=(const Rational& rhs) const noexcept;

  [[nodiscard]] Rational operator-() noexcept;
  Rational& operator+= (const Rational& rhs) noexcept;
  Rational& operator-= (const Rational& rhs) noexcept;
  Rational& operator*= (const Rational& rhs) noexcept;
  Rational& operator/= (const Rational& rhs);
  Rational& operator+= (const int64_t& rhs) noexcept;
  Rational& operator-= (const int64_t& rhs) noexcept;
  Rational& operator*= (const int64_t& rhs) noexcept;
  Rational& operator/= (const int64_t& rhs);

  std::ostream& WriteTo(std::ostream& os) const noexcept;
  std::istream& ReadFrom(std::istream& is) noexcept;

  [[nodiscard]] int64_t num() const noexcept;
  [[nodiscard]] int64_t den() const noexcept;

private:
  int64_t num_{ 0 };
  int64_t den_{ 1 };
    
  Rational Upd();

  static const char separator = '/';
};

[[nodiscard]] Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const Rational& rhs);

[[nodiscard]] Rational operator+(const int64_t& rhs, const Rational& lhs) noexcept;
[[nodiscard]] Rational operator-(const int64_t& rhs, const Rational& lhs) noexcept;
[[nodiscard]] Rational operator*(const int64_t& rhs, const Rational& lhs) noexcept;
[[nodiscard]] Rational operator/(const int64_t& rhs, const Rational& lhs);

[[nodiscard]] Rational operator+(const Rational& rhs, const int64_t& lhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& rhs, const int64_t& lhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& rhs, const int64_t& lhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& rhs, const int64_t& lhs);

std::ostream& operator<<(std::ostream& os, const Rational& rhs) noexcept;
std::istream& operator>>(std::istream& is, Rational& rhs) noexcept;

#endif