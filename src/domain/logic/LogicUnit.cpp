#include "LogicUnit.hpp"
#include "../../infrastructure/command/logic/NotCommand.hpp"
#include "../../infrastructure/command/logic/AndCommand.hpp"
#include "../../infrastructure/command/logic/OrCommand.hpp"
#include "../../infrastructure/command/logic/SltCommand.hpp"

LogicUnit *LogicUnit::instance = nullptr;

LogicUnit::LogicUnit(Store *store) : ControlUnit(store) {
  logger = LoggerFactory::getLogger("LogicUnit");
}

LogicUnit *LogicUnit::get_instance(Store *store) {
  if (instance == nullptr) {
    instance = new LogicUnit(store);
    instance->register_commands();
  }
  return instance;
}

void LogicUnit::register_commands() {
  logger->info("register commands");
  commands.insert(std::make_pair(0, new NotCommand(store)));
  commands.insert(std::make_pair(1, new AndCommand(store)));
  commands.insert(std::make_pair(2, new OrCommand(store)));
  commands.insert(std::make_pair(3, new SltCommand(store)));
  logger->info("registered commands");
}

Command *LogicUnit::get_command(int command_index) {
  logger->info("get command" + std::to_string(command_index));
  return commands[command_index];
}

void LogicUnit::execute(ExecuteRequest *execute_request) {
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
