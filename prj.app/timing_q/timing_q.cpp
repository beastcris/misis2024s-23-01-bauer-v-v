#include <queuelstt/queuelstt.hpp>

#include <chrono>

#include <iostream>

template<class T>
void Fill(QueueLstT<T>& rhs) {
  for (int i = 0; i < 100000; ++i) {
    rhs.Push(1);
  }
}

template<class T>
void FillZero(QueueLstT<T>& rhs) {
  for (int i = 0; i < 100000; ++i) {
    rhs.Push(0);
  }
}

int main() {
  auto start = std::chrono::high_resolution_clock::now();
  QueueLstT<int> Test;
  auto end = std::chrono::high_resolution_clock::now();
  auto res = std::chrono::duration<float>{ end - start };
  std::cout << "Empty constructing  time: " << res << '\n';

  start = std::chrono::high_resolution_clock::now();
  Test.Push(1);
  end = std::chrono::high_resolution_clock::now();
  res = std::chrono::duration<float>{ end - start };
  std::cout << "Push time: " << res << '\n';

  int a = 0;
  start = std::chrono::high_resolution_clock::now();
  a = Test.Top();
  end = std::chrono::high_resolution_clock::now();
  res = std::chrono::duration<float>{ end - start };
  std::cout << "Top time: " << res << '\n';

  Fill(Test);
  start = std::chrono::high_resolution_clock::now();
  Test.Clear();
  end = std::chrono::high_resolution_clock::now();
  res = std::chrono::duration<float>{ end - start };
  std::cout << "Clear 100000 elems time: " << res << '\n';

  Fill(Test);
  QueueLstT<int> copy;
  start = std::chrono::high_resolution_clock::now();
  copy = Test;
  end = std::chrono::high_resolution_clock::now();
  res = std::chrono::duration<float>{ end - start };
  std::cout << "Assign 100000 elems to Empty queue time: " << res << '\n';

  copy.Clear();
  FillZero(copy);
  start = std::chrono::high_resolution_clock::now();
  copy = Test;
  end = std::chrono::high_resolution_clock::now();
  res = std::chrono::duration<float>{ end - start };
  std::cout << "Assign 100000 elems to 100000 elems queue time: " << res << '\n';

  QueueLstT<int> copy2;
  start = std::chrono::high_resolution_clock::now();
  copy = copy2;
  end = std::chrono::high_resolution_clock::now();
  res = std::chrono::duration<float>{ end - start };
  std::cout << "Assign empty queue to 100000 elems queue time: " << res << '\n';

  start = std::chrono::high_resolution_clock::now();
  QueueLstT<int> copy3(copy);
  end = std::chrono::high_resolution_clock::now();
  res = std::chrono::duration<float>{ end - start };
  std::cout << "Copy Constructor for empty queue time: " << res << '\n';


  start = std::chrono::high_resolution_clock::now();
  QueueLstT<int> copy4(Test);
  end = std::chrono::high_resolution_clock::now();
  res = std::chrono::duration<float>{ end - start };
  std::cout << "Copy Constructor for 100000 elems time: " << res << '\n';
}