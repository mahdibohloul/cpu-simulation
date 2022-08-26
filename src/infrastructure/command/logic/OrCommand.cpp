//
// Created by tapsi on 8/26/22.
//

#include "OrCommand.hpp"

void OrCommand::execute(int arg1, int arg2, int arg3) {
  int val1 = store->load(arg1);
  logger->info("Loaded value: " + std::to_string(val1) + " from register: " + std::to_string(arg1));
  int val2 = store->load(arg2);
  logger->info("Loaded value: " + std::to_string(val2) + " from register: " + std::to_string(arg2));
  int result = val1 | val2;
  logger->info("Result: " + std::to_string(result));
  store->store(arg3, result);
  logger->info("Stored value: " + std::to_string(result) + " in register: " + std::to_string(arg3));
}
