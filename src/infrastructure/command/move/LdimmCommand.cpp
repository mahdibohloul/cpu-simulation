//
// Created by tapsi on 8/26/22.
//

#include "LdimmCommand.hpp"

void LdimmCommand::execute(int arg1, int arg2, int arg3) {
  logger->info("Store value: " + std::to_string(arg1) + " in register: " + std::to_string(arg2));
  store->store(arg2, arg1);
  logger->info("Stored value: " + std::to_string(arg1) + " in register: " + std::to_string(arg2));
}
