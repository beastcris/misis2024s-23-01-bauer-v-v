


#ifndef QUEUELSTPR_HPP
#define QUEUELSTPR_HPP

#include <algorithm>
#include <stdexcept>
#include <iosfwd>

class QueueLstPr {

public:
  QueueLstPr() = default;
  QueueLstPr(const QueueLstPr& rhs);
  QueueLstPr(QueueLstPr&& rhs) noexcept;
  QueueLstPr& operator=(const QueueLstPr& rhs);
  QueueLstPr& operator=(QueueLstPr&& rhs) noexcept;
  ~QueueLstPr();

  void Push(const float& value);
  void Pop() noexcept;

  float& Top();
  const float& Top() const;

  bool IsEmpty() const noexcept;
  void Clear() noexcept;
private:
  struct Node {

    Node* next_ = nullptr;
    float data_ = 0;
  };

  Node* head_ = nullptr;
};

#endif // !QUEUELSTPR_HPP
