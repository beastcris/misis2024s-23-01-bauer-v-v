
#ifndef A_HPP
#define A_HPP

#include <vector>

class Command;

struct Buffer {
  Buffer() = delete;
  Buffer(int size) { std::vector<int> a(size);  std::swap(values, a); };

  std::vector<int> values;
  int64_t idx = 0;
};

class Command {
public:
  virtual void execute(int value, Buffer& buf) {};
private:

};

class Right : public Command {
public:
  void execute(int value, Buffer& buf) override final;
private:

};

class Left : public Command {
public:
  void execute(int value, Buffer& buf) override final;
private:

};

class Add : public Command {
public:
  void execute(int value, Buffer& buf) override final;
private:

};

class Sub : public Command {
public:
  void execute(int value, Buffer& buf) override final;
private:

};


#endif // !A_HPP
