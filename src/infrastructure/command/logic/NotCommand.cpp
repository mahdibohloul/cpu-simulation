//
// Created by tapsi on 8/26/22.
//

#include "NotCommand.hpp"

void NotCommand::execute(int arg1, int arg2, int arg3) {
  int val1 = store->load(arg1);
  logger->info("Loaded value: " + std::to_string(val1) + " from register: " + std::to_string(arg1));
  int result = ~val1;
  logger->info("Result: " + std::to_string(result));
  store->store(arg2, result);
  logger->info("Stored value: " + std::to_string(result) + " in register: " + std::to_string(arg2));
}
