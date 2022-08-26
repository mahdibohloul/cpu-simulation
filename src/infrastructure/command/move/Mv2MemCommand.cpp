//
// Created by tapsi on 8/26/22.
//

#include "Mv2MemCommand.hpp"
#include "../../store/MemoryStore.hpp"

void Mv2MemCommand::execute(int arg1, int arg2, int arg3) {
  // move arg1 to memory location arg2
  auto value = this->store->load(arg1);
  logger->info("Loaded value: " + std::to_string(value) + " from register: " + std::to_string(arg1));
  auto memory_store = MemoryStore::get_instance();
  logger->info("Memory store loaded");
  memory_store->store(arg2, value);
  logger->info("Stored value: " + std::to_string(value) + " in memory location: " + std::to_string(arg2));
}
