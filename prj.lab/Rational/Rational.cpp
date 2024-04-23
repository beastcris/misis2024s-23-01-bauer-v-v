#include <Rational/Rational.hpp>


Rational::Rational(int64_t num) :num_(num), den_(1) { if (den_ == 0) { throw std::exception("ZERO DENUM"); } };
Rational::Rational(int64_t num, int64_t den) :num_(num), den_(den) {
  if (den_ == 0) {
    throw std::exception("ZERO DENUM");
  }
  if (den_ < 0) {
    num_ *= -1;
    den_ *= -1;
  }
  (*this).Upd();
};
Rational::Rational(Rational&& rhs) noexcept :num_(rhs.num_), den_(rhs.den_) {}

Rational& Rational::operator=(Rational&& rhs) noexcept {
  if (this != &rhs) {
    std::swap(num_, rhs.num_);
    std::swap(den_, rhs.den_);
  }
  return *this;
}

bool Rational::operator==(const Rational& rhs) const noexcept { return den_ == rhs.den_ && num_ == rhs.num_; }
bool Rational::operator!=(const Rational& rhs) const noexcept { return !operator==(rhs); }

bool Rational::operator<(const Rational& rhs) const noexcept { return num_ * rhs.den_ < rhs.num_ * den_; }
bool Rational::operator<=(const Rational& rhs) const noexcept { return num_ * rhs.den_ <= rhs.num_ * den_; }
bool Rational::operator>(const Rational& rhs) const noexcept { return num_ * rhs.den_ > rhs.num_ * den_; }
bool Rational::operator>=(const Rational& rhs) const noexcept { return num_ * rhs.den_ >= rhs.num_ * den_; }

[[nodiscard]] int64_t Rational::num() const noexcept { return num_; };
[[nodiscard]] int64_t Rational::den() const noexcept { return den_; };

[[nodiscard]] Rational Rational::operator-() noexcept {
  *this *= -1;
  return *this;
};

Rational& Rational::operator+= (const int64_t& rhs) noexcept {
  Rational a{ rhs, 1 };
  return operator+=(a);
};

Rational& Rational::operator-= (const int64_t& rhs) noexcept {
  Rational a{ rhs, 1 };
  return operator-=(a);
};

Rational& Rational::operator*= (const int64_t& rhs) noexcept {
  Rational a{ rhs, 1 };
  return operator*=(a);
};

 Rational& Rational::operator/= (const int64_t& rhs) {
  Rational a{ rhs, 1 };
  return operator/=(a);
};

 Rational& Rational::operator+= (const Rational& rhs) noexcept {
   int64_t newNum = num_ * rhs.den_ + rhs.num_ * den_;
   num_ = newNum;
   den_ *= rhs.den_;
   (*this).Upd();
   return *this;
 };

 Rational& Rational::operator-= (const Rational& rhs) noexcept {
   int64_t newNum = num_ * rhs.den_ - rhs.num_ * den_;
   num_ = newNum;
   den_ *= rhs.den_;
   (*this).Upd();
   return *this;
 };

 Rational& Rational::operator*= (const Rational& rhs) noexcept {
   num_ *= rhs.num_;
   den_ *= rhs.den_;
   (*this).Upd();
   return *this;
 };

 Rational& Rational::operator/= (const Rational& rhs) {
   if (rhs.num_ == 0) {
     throw std::exception("ZERO");
   }
   num_ *= rhs.den_;
   den_ *= rhs.num_;
   (*this).Upd();
   return *this;
 };

 [[nodiscard]] Rational operator+(const Rational& lhs, const Rational& rhs) noexcept{
   Rational temp{ 0 };
   temp += lhs;
   temp += rhs;
   temp += 0;
   return temp;
 }

 [[nodiscard]] Rational operator-(const Rational& lhs, const Rational& rhs) noexcept{
   Rational temp{ 0 };
   temp += lhs;
   temp -= rhs;
   temp += 0;

   return temp;
 }

 [[nodiscard]] Rational operator*(const Rational& lhs, const Rational& rhs) noexcept{
   Rational temp{ 1 };
   temp *= lhs;
   temp *= rhs;
   temp += 0;

   return temp;
 }

 [[nodiscard]] Rational operator/(const Rational& lhs, const Rational& rhs) {
   Rational temp{ 1 };
   temp *= lhs;
   temp /= rhs;
   temp += 0;

   return temp;
 }

 [[nodiscard]] Rational operator+(const Rational& lhs, const int64_t& rhs) noexcept {
   Rational Rhs{ rhs, 1 };
   Rational temp{ 0 };
   temp += lhs;
   temp += Rhs;
   temp += 0;

   return temp;
 }

 [[nodiscard]] Rational operator-(const Rational& lhs, const int64_t& rhs) noexcept {
   Rational Rhs{ rhs, 1 };
   Rational temp{ 0 };
   temp += lhs;
   temp -= Rhs;
   temp += 0;

   return temp;
 }

 [[nodiscard]] Rational operator*(const Rational& lhs, const int64_t& rhs) noexcept {
   Rational Rhs{ rhs, 1 };
   Rational temp{ 1 };
   temp *= lhs;
   temp *= Rhs;
   temp += 0;

   return temp;
 }

 [[nodiscard]] Rational operator/(const Rational& lhs, const int64_t& rhs) {
   Rational Rhs{ rhs, 1 };
   Rational temp{ 1 };
   temp *= lhs;
   temp /= Rhs;
   temp += 0;

   return temp;
 }

 [[nodiscard]] Rational operator+(const int64_t& lhs, const Rational& rhs) noexcept {
   Rational Lhs{ lhs, 1 };
   Rational temp{ 0 };
   temp += Lhs;
   temp += rhs;
   return temp;
 }

 [[nodiscard]] Rational operator-(const int64_t& lhs, const Rational& rhs) noexcept {
   Rational Lhs{ lhs, 1 };
   Rational temp{ 0 };
   temp += Lhs;
   temp -= rhs;
   temp += 0;

   return temp;
 }

 [[nodiscard]] Rational operator*(const int64_t& lhs, const Rational& rhs) noexcept {
   Rational Lhs{ lhs, 1 };
   Rational temp{ 1 };
   temp *= Lhs;
   temp *= rhs;
   temp += 0;

   return temp;
 }

 [[nodiscard]] Rational operator/(const int64_t& lhs, const Rational& rhs) {
   Rational Lhs{ lhs, 1 };
   Rational temp{ 1 };
   temp *= Lhs;
   temp /= rhs;
   temp += 0;
   return temp;
 }

Rational Rational::Upd() {
  if (num_ == den_) {
    num_ = 1;
    den_ = 1;
  }
  else if (num_ == 0) {
    den_ = 1;
  }
  else {
    for (int i = 2; i <= abs(den_) / 2 + 1; ++i) {
      if (den_ % i == 0 && num_ % i == 0) {
        num_ /= i;
        den_ /= i;
        break;
      }
    }
  }

  return *this;
}

std::ostream& operator<<(std::ostream& os, const Rational& rhs) noexcept{
  return rhs.WriteTo(os);
}

std::istream& operator>>(std::istream& is, Rational& rhs) noexcept{
  return rhs.ReadFrom(is);
}

std::ostream& Rational::WriteTo(std::ostream& os) const noexcept{
  os << num_ << separator << den_;
  return os;
}

std::istream& Rational::ReadFrom(std::istream& is) noexcept{
  char separator{ 0 };
  int64_t num{ 0 };
  int64_t den{ 0 };

  is >> num >> separator >> den;
  if (is.good() || (is.eof() && !is.bad())) {
    if (Rational::separator == separator && den != 0) {
      num_ = num;
      den_ = den;
      if (den < 0) {
        num_ *= -1;
        den_ *= -1;
      }
    }
    else {
      is.setstate(std::ios_base::failbit);
    }
  }
  return is;
}