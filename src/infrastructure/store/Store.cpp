#include "Store.hpp"

using namespace std;

Store::Store(long memory_size) {
  this->memory_size = memory_size;
  for (int i = 0; i < memory_size; i++) {
    this->memory[i] = 0;
  }
}

void Store::clear() {
  for (int i = 0; i < memory_size; i++) {
    this->memory[i] = 0;
  }
}

int Store::load(int index) {
  validateIndex(index);
  return memory[index];
}
