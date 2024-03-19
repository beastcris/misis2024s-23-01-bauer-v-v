#pragma once
#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <iostream>
#include <cstddef>

class DynArr {
public:
  [[nodiscard]] DynArr();
  [[nodiscard]] DynArr(const std::ptrdiff_t size);
  [[nodiscard]] DynArr(const DynArr& rhs) ;
  DynArr(DynArr&& rhs) noexcept;
  ~DynArr();

  [[nodiscard]] float& operator[] (const std::ptrdiff_t idx);
  [[nodiscard]] const float& operator[] (const std::ptrdiff_t idx) const;

  DynArr& operator=(const DynArr& rhs);
  DynArr& operator=(DynArr&& rhs) noexcept;
  void Resize(const std::ptrdiff_t NewSize);

  std::ostream& writeTo(std::ostream& os) const noexcept;

  [[nodiscard]] float* getData() noexcept;
  [[nodiscard]] std::ptrdiff_t Size() const noexcept;

private:
  std::ptrdiff_t size_ = 0;
  std::ptrdiff_t capacity_ = 0;
  float* data_ = nullptr;

  void PutZero(float* data) noexcept;
};

std::ostream& operator<<(std::ostream& os, const DynArr& rhs);

#endif