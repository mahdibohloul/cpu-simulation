#include <stdexcept>
#include <sstream>
#include "MemoryStore.hpp"

MemoryStore::MemoryStore() : Store(MEMORY_SIZE) {}

MemoryStore *MemoryStore::instance = nullptr;

MemoryStore *MemoryStore::get_instance() {
  if (instance == nullptr) {
    instance = new MemoryStore();
  }
  return instance;
}

void MemoryStore::store(int index, int value) {
  validateIndex(index);
  memory[index] = value;
}

void MemoryStore::validateIndex(int index) {
  if (index < 0 || index >= MEMORY_SIZE) {
    throw std::out_of_range("Index out of range");
  }
}

void MemoryStore::print(OutputWriter *output_writer) {
  std::string delim;
  std::stringstream ss;
  for (int i = 0; i < MEMORY_SIZE; i++) {
    ss << delim << memory[i];
    delim = " ";
  }
  output_writer->writeOutput(ss.str());
}
