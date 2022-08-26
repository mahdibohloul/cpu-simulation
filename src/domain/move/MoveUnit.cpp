//
// Created by tapsi on 8/26/22.
//

#include "MoveUnit.hpp"
#include "../../infrastructure/command/move/Mv2MemCommand.hpp"
#include "../../infrastructure/command/move/Mv2RegCommand.hpp"
#include "../../infrastructure/command/move/LdimmCommand.hpp"
#include "../../infrastructure/logger/LoggerFactory.hpp"

MoveUnit *MoveUnit::instance = nullptr;

MoveUnit *MoveUnit::get_instance(Store *store) {
  if (instance == nullptr) {
    instance = new MoveUnit(store);
    instance->register_commands();
    instance->logger->info("MoveUnit instantiated");
  }
  return instance;
}

MoveUnit::MoveUnit(Store *store) : ControlUnit(store) {
  logger = LoggerFactory::getLogger("MoveUnit");
}

void MoveUnit::register_commands() {
  logger->info("Registering commands");
  commands.insert(std::make_pair(0, new Mv2RegCommand(store)));
  commands.insert(std::make_pair(1, new Mv2MemCommand(store)));
  commands.insert(std::make_pair(2, new LdimmCommand(store)));
  logger->info("Registering commands complete");
}

Command *MoveUnit::get_command(int command_index) {
  logger->info("Getting command: " + std::to_string(command_index));
  return commands[command_index];
}

void MoveUnit::execute(ExecuteRequest *execute_request) {
  logger->info("Executing command: " + std::to_string(execute_request->get_command_index()));
  auto command = get_command(execute_request->get_command_index());
  int arg1 = execute_request->get_first_op();
  logger->info("Arg1: " + std::to_string(arg1));
  int arg2 = execute_request->get_second_op();
  logger->info("Arg2: " + std::to_string(arg2));
  int arg3 = execute_request->get_third_op();
  logger->info("Arg3: " + std::to_string(arg3));
  command->execute(arg1, arg2, arg3);
  logger->info("Executing command complete");
}
