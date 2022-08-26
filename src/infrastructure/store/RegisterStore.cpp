#include <stdexcept>
#include "sstream"
#include "RegisterStore.hpp"

RegisterStore *RegisterStore::instance = nullptr;

RegisterStore::RegisterStore() : Store(REGISTER_SIZE) {}

void RegisterStore::store(int index, int value) {
  validateIndex(index);
  this->memory[index] = value;
}

void RegisterStore::validateIndex(int index) {
  if (index > REGISTER_SIZE || index < 0)
    throw std::out_of_range("Register index out of range");
}

RegisterStore *RegisterStore::get_instance() {
  if (instance == nullptr) {
    instance = new RegisterStore();
  }
  return instance;
}

void RegisterStore::print(OutputWriter *output_writer) {
  std::string delim;
  std::stringstream ss;
  for (int i = 0; i < REGISTER_SIZE; i++) {
    ss << delim << this->memory[i];
    delim = " ";
  }
  output_writer->writeOutput(ss.str());
}
