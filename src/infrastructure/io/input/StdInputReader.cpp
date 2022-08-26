#include "StdInputReader.hpp"

std::string StdInputReader::read_input() {
  std::string input;
  getline(std::cin, input);
  return input;
}

bool StdInputReader::has_more_input() {
  return true;
}
