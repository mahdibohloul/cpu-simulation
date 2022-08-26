#include <cstring>
#include "ArithUnit.hpp"
#include "../../infrastructure/command/arith/AddCommand.hpp"
#include "../../infrastructure/command/arith/SubCommand.hpp"
#include "../../infrastructure/command/arith/MulCommand.hpp"
#include "../../infrastructure/command/arith/DivCommand.hpp"


ArithUnit *ArithUnit::instance = nullptr;


ArithUnit::ArithUnit(Store *store) : ControlUnit(store) {
  logger = LoggerFactory::getLogger("ArithUnit");
}

void ArithUnit::register_commands() {
  logger->info("register commands");
  commands.insert(std::make_pair(0, new AddCommand(store)));
  commands.insert(std::make_pair(1, new SubCommand(store)));
  commands.insert(std::make_pair(2, new MulCommand(store)));
  commands.insert(std::make_pair(3, new DivCommand(store)));
  logger->info("registered commands");
}

Command *ArithUnit::get_command(int command_index) {
  logger->info("get command" + std::to_string(command_index));
  return commands[command_index];
}

ArithUnit *ArithUnit::get_instance(Store *store) {
  if (instance == nullptr) {
    instance = new ArithUnit(store);
    instance->register_commands();
  }
  return instance;
}

void ArithUnit::execute(ExecuteRequest *execute_request) {
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



