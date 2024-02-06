#include <Complex/Complex.hpp>

static const double eps = 2 * std::numeric_limits<double>::epsilon();

Complex::Complex(const double real) :Complex(real, 0.0) {}
Complex::Complex(const double real, const double imaginary) :re(real), im(imaginary) {}

[[nodiscard]] bool Complex::operator==(const Complex& cmp) const noexcept { return ((abs(cmp.re - re) <= eps) && (abs(cmp.im - im) <= eps)); }
[[nodiscard]] bool Complex::operator==(const double cmp) const noexcept { return operator==(Complex(cmp)); }
[[nodiscard]] bool Complex::operator!=(const Complex& cmp) const noexcept { return (!operator==(cmp)); }
[[nodiscard]] bool Complex::operator!=(const double cmp) const noexcept { return operator!=(Complex(cmp)); }

Complex& Complex::operator+= (const double ins) noexcept { return operator+=(Complex(ins)); };
Complex& Complex::operator-= (const double ins) noexcept { return operator-=(Complex(ins)); };
Complex& Complex::operator*= (const double ins) noexcept { return operator*=(Complex(ins)); };
Complex& Complex::operator/= (const double ins) { return operator/=(Complex(ins)); };

[[nodiscard]] Complex Complex::operator-() const noexcept {
  return (*this) * (-1);
};

[[nodiscard]] Complex operator+(const Complex& lhs, const Complex& rhs) noexcept {
  return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}

[[nodiscard]] Complex operator+ (const Complex& lhs, const double& rhs) noexcept {
  return operator+(lhs, Complex(rhs));
}

[[nodiscard]] Complex operator+ (const double lhs, const Complex& rhs) noexcept {
  return operator+(rhs, Complex(lhs));
}

[[nodiscard]] Complex operator-(const Complex& lhs, const Complex& rhs) noexcept {
  return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

[[nodiscard]] Complex operator- (const Complex& lhs, const double& rhs) noexcept {
  return operator-(lhs, Complex(rhs));
}

[[nodiscard]] Complex operator- (const double lhs, const Complex& rhs) noexcept {
  return operator-(rhs, Complex(lhs));
}

[[nodiscard]] Complex operator* (const Complex& lhs, const Complex rhs) noexcept {
  return Complex(lhs.re * rhs.re - lhs.im * rhs.im, lhs.re * rhs.im + rhs.re * lhs.im);
}

[[nodiscard]] Complex operator* (const Complex& lhs, const double& rhs) noexcept {
  return operator*(lhs, Complex(rhs));
}

[[nodiscard]] Complex operator* (const double lhs, const Complex& rhs) noexcept {
  return operator*(rhs, Complex(lhs));
}

[[nodiscard]] Complex operator/ (const Complex& lhs, const Complex rhs) {
  if (rhs.im * rhs.im + rhs.re * rhs.re == 0) {
    throw std::exception("ZERO");
  }
  
  double x = (lhs.im * rhs.im + lhs.re * rhs.re) / (rhs.im * rhs.im + rhs.re * rhs.re);
  double y = (rhs.re * lhs.im - lhs.re * rhs.im) / (rhs.im * rhs.im + rhs.re * rhs.re);
  
  return Complex(x, y);
}

[[nodiscard]] Complex operator/ (const Complex& lhs, const double& rhs) {

  return operator/(lhs, Complex(rhs));
}

[[nodiscard]] Complex operator/ (const double lhs, const Complex& rhs) {
  return operator/(rhs, Complex(lhs));
}

Complex& Complex::operator+=(const Complex& comp) noexcept {
  re += comp.re;
  im += comp.im;
  return *this;
}

Complex& Complex::operator-=(const Complex& comp) noexcept {
  re -= comp.re;
  im -= comp.im;
  return *this;
}

Complex& Complex::operator*=(const Complex& comp) noexcept {
  double x = re * comp.re - im * comp.im;
  double y = re * comp.im + comp.re * im;
  re = x;
  im = y;
  return *this;
}

Complex& Complex::operator/=(const Complex& comp) {
  if (comp.im * comp.im + comp.re * comp.re == 0) {
    throw std::exception("ZERO");
  }

  double x = (im * comp.im + re * comp.re) / (comp.im * comp.im + comp.re * comp.re);
  double y = (comp.re * im - re * comp.im) / (comp.im * comp.im + comp.re * comp.re);

  re = x;
  im = y;
  return *this;
}

std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) noexcept {
  return rhs.WriteTo(ostrm);
}

std::ostream& Complex::WriteTo(std::ostream& ostrm) const noexcept{
  ostrm << leftBrace << re << separator << im << rightBrace;
  return ostrm;
}

std::istream& operator>>(std::istream& istrm, Complex& rhs) noexcept {
  return rhs.ReadFrom(istrm);
}

std::istream& Complex::ReadFrom(std::istream& is) noexcept{
  char leftBrace{ 0 };
  double real{ 0.0 };
  char comma{ 0 };
  double imaginary{ 0.0 };
  char rightBrace{ 0 };

  is >> leftBrace >> real >> comma >> imaginary >> rightBrace;
  if (is.good()) {
    if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) && (Complex::rightBrace == rightBrace)) {
      re = real;
      im = imaginary;
    }
    else {
      is.setstate(std::ios_base::failbit);
    }
  }
  return is;
}