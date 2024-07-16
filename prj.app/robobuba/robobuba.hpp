
#ifndef A_HPP
#define A_HPP

#include <vector>
#include <fstream>
#include <string>

inline int Calculate(std::string& str) {
  int num = 0;
  for (int i = 0; i < str.length(); ++i) {
    if (str[i] > 57 || str[i] < 48) {
      return -1;
    }
    num += (str[i] - 48) * std::pow(10, str.length() - i - 1);
  }
  return num;
}


class Command;

struct Buffer {
  Buffer() = delete;
  Buffer(int size) { std::vector<int> a(size);  std::swap(values, a); };

  std::vector<int> values;
  int64_t idx = 0;
};

class Command {
public:
  virtual void execute(Buffer& buf) = 0;
  virtual std::unique_ptr<Command> Create(std::string& str) = 0 ;
};

class Right : public Command {
public:
  Right() = default;
  Right(int value) : value_(value) {};
  void execute(Buffer& buf) override final;
  std::unique_ptr<Command> Create(std::string& str) override final {
    return nullptr;
  };
private:
  int value_ = 0;
};

class Left : public Command {
public:
  Left() = default;
  Left(std::string& str) { if (str[0] == 'L') { value_ = 1; } };
  Left(int value) : value_(value) {};
  void execute(Buffer& buf) override final;
  std::unique_ptr<Command> Create(std::string& str) override final { 
    auto pos = str.find(' ');
    std::string token = str.substr(0, pos);
    std::string num = str.substr(pos + 1, str.length() - pos);
    
    if (token == "LEFT") {
      return std::make_unique<Left>(Calculate(num));
    } else {
      return nullptr; 
    } 
  };
  int value_ = 0; 
};

class Add : public Command {
public:
  Add() = default;
  Add(int value) : value_(value) {};
  void execute(Buffer& buf) override final;
  std::unique_ptr<Command> Create(std::string& str) override final { return nullptr; };
private:
  int value_ = 0;
};

class Sub : public Command {

public:
  Sub() = default;
  Sub(int value) : value_(value) {};

  void execute(Buffer& buf) override final;
  std::unique_ptr<Command> Create(std::string& str) override final { 
    if (str[0] == 'S') {
      return std::make_unique<Sub>(5);
    }
    else {
      return nullptr;
    }
  };

private:
  int value_ = 0;
};


#endif 
