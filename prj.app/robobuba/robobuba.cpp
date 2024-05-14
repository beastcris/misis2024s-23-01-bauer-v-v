#include "robobuba.hpp"

void Right::execute(int value, Buffer& buf) {
  buf.idx = (buf.idx + value) % buf.values.size();
}

void Left::execute(int value, Buffer& buf) {
  buf.idx = (buf.idx - value) % buf.values.size();
  if (buf.idx < 0) {
    buf.idx = buf.values.size() - buf.idx;
  }
}

void Add::execute(int value, Buffer& buf) {
  buf.values[buf.idx] += value;
}

void Sub::execute(int value, Buffer& buf) {
  buf.values[buf.idx] -= value;
}