

#ifndef QUEUELSTPR_HPP
#define QUEUELSTPR_HPP

#include <iosfwd>
#include <stdexcept>

class QueueLstPr {

public:
  [[nodiscard]] QueueLstPr() = default;
  QueueLstPr(const QueueLstPr& rhs);
  QueueLstPr& operator=(const QueueLstPr& rhs);
  ~QueueLstPr();

  void Push(const float& value);

  void Pop() noexcept;

  [[nodiscard]] bool IsEmpty() const noexcept;

  [[nodiscard]] float& Top();
  [[nodiscard]] const float& Top() const;

  void Clear() noexcept;

private:
  struct Node {
    float data_ = 0;
    Node* next_= nullptr;
   };

  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};


#endif