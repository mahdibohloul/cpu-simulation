//
// Created by tapsi on 8/26/22.
//

#include "Mv2RegCommand.hpp"
#include "../../store/RegisterStore.hpp"

void Mv2RegCommand::execute(int arg1, int arg2, int arg3) {
  auto value = this->store->load(arg1);
  logger->info("Loaded value: " + std::to_string(value) + " from register: " + std::to_string(arg1));
  auto register_store = RegisterStore::get_instance();
  logger->info("Register store loaded");
  register_store->store(arg2, value);
  logger->info("Stored value: " + std::to_string(value) + " in register: " + std::to_string(arg2));
}
