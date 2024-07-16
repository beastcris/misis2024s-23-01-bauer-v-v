#include "robobuba.hpp"

void Right::execute(Buffer& buf) {
  buf.idx = (buf.idx + this->value_) % buf.values.size();
}

void Left::execute(Buffer& buf) {
  buf.idx = (buf.idx - this->value_) % buf.values.size();
  if (buf.idx < 0) {
    buf.idx = buf.values.size() - buf.idx;
  }
}

void Add::execute(Buffer& buf) {
  buf.values[buf.idx] += this->value_;
}

void Sub::execute(Buffer& buf) {
  buf.values[buf.idx] -= this->value_;
}
