#include "ShiftUnit.hpp"
#include "../../infrastructure/command/shift/ShrCommand.hpp"
#include "../../infrastructure/command/shift/ShlCommand.hpp"
#include "../../infrastructure/command/shift/ShrArithCommand.hpp"

ShiftUnit *ShiftUnit::instance = nullptr;

ShiftUnit *ShiftUnit::get_instance(Store *store) {
  if (instance == nullptr) {
    instance = new ShiftUnit(store);
    instance->register_commands();
  }
  return instance;
}

ShiftUnit::ShiftUnit(Store *store) : ControlUnit(store) {
  logger = LoggerFactory::getLogger("ShiftUnit");
}

void ShiftUnit::register_commands() {
  logger->info("register commands");
  commands.insert(std::make_pair(0, new ShlCommand(store)));
  commands.insert(std::make_pair(1, new ShrCommand(store)));
  commands.insert(std::make_pair(2, new ShrArithCommand(store)));
  logger->info("registered commands");
}

Command *ShiftUnit::get_command(int command_index) {
  logger->info("get command" + std::to_string(command_index));
  return commands[command_index];
}

void ShiftUnit::execute(ExecuteRequest *execute_request) {
  auto command = get_command(execute_request->get_command_index());
  int arg1 = execute_request->get_first_op();
  logger->info("arg1: " + std::to_string(arg1));
  int arg2 = execute_request->get_second_op();
  logger->info("arg2: " + std::to_string(arg2));
  int arg3 = execute_request->get_third_op();
  logger->info("arg3: " + std::to_string(arg3));
  command->execute(arg1, arg2, arg3);
  logger->info("executed command");
}





