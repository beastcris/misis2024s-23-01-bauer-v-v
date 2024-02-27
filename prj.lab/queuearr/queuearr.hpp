
#ifndef QUEUEARR_HPP
#define QUEUEARR_HPP
#include <Complex/Complex.hpp>


class QueueArr {

public:
  [[nodiscard]] QueueArr() = default;

  [[nodiscard]] QueueArr(const QueueArr& rhs);

  ~QueueArr();

  [[nodiscard]] QueueArr& operator=(const QueueArr& rhs);

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& rhs);

  [[nodiscard]] Complex& Top();

  [[nodiscard]] const Complex& Top() const;

  void Clear() noexcept;
private:
  std::ptrdiff_t head_ = -1;
  std::ptrdiff_t size_ = 0;
  std::ptrdiff_t tail_ = -1;

  Complex* data_ = nullptr;
};
#endif 
