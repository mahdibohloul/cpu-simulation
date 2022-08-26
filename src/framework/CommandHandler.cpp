//
// Created by tapsi on 8/26/22.
//

#include <cstring>
#include "CommandHandler.hpp"
#include "../infrastructure/logger/LoggerFactory.hpp"
#include "../domain/arith/ArithUnit.hpp"
#include "../domain/logic/LogicUnit.hpp"
#include "../domain/shift/ShiftUnit.hpp"
#include "../domain/move/MoveUnit.hpp"

CommandHandler *CommandHandler::instance = nullptr;

CommandHandler *CommandHandler::get_instance() {
  if (instance == nullptr) {
    instance = new CommandHandler();
  }
  return instance;
}

CommandHandler::CommandHandler() {
  logger = LoggerFactory::getLogger("CommandHandler");
  logger->info("Setting up CommandHandler");
  input_reader = new StdInputReader();
  logger->info("Input reader instantiated");
  output_writer = new StdOutputWriter();
  logger->info("Output writer instantiated");
  this->initialize_stores();
  this->initialize_control_units();
  logger->info("CommandHandler setup complete");
}

CommandHandler::~CommandHandler() {
  delete input_reader;
  delete output_writer;
  delete current_control_unit;
}

void CommandHandler::handle() {
  logger->info("CommandHandler handling");
  while (input_reader->has_more_input()) {
    std::string input = input_reader->read_input();
    if (is_unit_command(input)) {
      change_control_unit(input);
    } else if (is_store_command(input)) {
      change_store(input);
    } else if (is_end_of_commands(input)) {
      run_end_of_commands_routine();
    } else if (input == "exit" || input.empty()) {
      break;
    } else {
      auto execute_request = get_execute_request(input);
      current_control_unit->execute(execute_request);
    }
  }
}

bool CommandHandler::is_unit_command(const std::string &input) {
  if (this->control_unit_map.find(input) != this->control_unit_map.end()) {
    return true;
  }
  return false;
}

void CommandHandler::initialize_stores() {
  store_map[MEMORY_STORE_TYPE] = MemoryStore::get_instance();
  logger->info("Memory store instantiated");
  store_map[REGISTER_STORE_TYPE] = RegisterStore::get_instance();
  logger->info("Register store instantiated");
  current_store = store_map[REGISTER_STORE_TYPE];
  logger->info("Current store set to register store");
  logger->info("Stores initialized");
}

void CommandHandler::initialize_control_units() {
  control_unit_map[ARITH_CONTROL_UNIT] = ArithUnit::get_instance(current_store);
  logger->info("Arith unit instantiated");
  control_unit_map[LOGIC_CONTROL_UNIT] = LogicUnit::get_instance(current_store);
  logger->info("Logic unit instantiated");
  control_unit_map[SHIFT_CONTROL_UNIT] = ShiftUnit::get_instance(current_store);
  logger->info("Shift unit instantiated");
  control_unit_map[MOVE_CONTROL_UNIT] = MoveUnit::get_instance(current_store);
  logger->info("Move unit instantiated");
  current_control_unit = control_unit_map[ARITH_CONTROL_UNIT];
  logger->info("Current control unit set to arith unit");
  logger->info("Control units initialized");
}

bool CommandHandler::is_store_command(const std::string &input) {
  if (this->store_map.find(input) != this->store_map.end()) {
    return true;
  }
  return false;
}

void CommandHandler::change_control_unit(const std::string &unit_name) {
  this->current_control_unit = this->control_unit_map[unit_name];
  logger->info("Current control unit set to " + unit_name);
}

void CommandHandler::change_store(const std::string &store_name) {
  this->current_store = this->store_map[store_name];
  for (const auto &item: this->control_unit_map) {
    item.second->change_store(this->current_store);
  }
  logger->info("Current store set to " + store_name);
}

std::vector<int> CommandHandler::get_operands(const std::string &input, int num_operands, const char *delimiter) {
  std::vector<int> operands;
  char *input_cstr = new char[input.length() + 1];
  strcpy(input_cstr, input.c_str());
  char *token = strtok(input_cstr, delimiter);
  while (token != nullptr) {
    operands.push_back(atoi(token));
    token = strtok(nullptr, delimiter);
  }
  return operands;
}

DefaultExecuteRequest *CommandHandler::get_execute_request(const std::string &input) {
  auto operands = get_operands(input, OPERANDS_NUMBER, OPERANDS_SEPARATOR);
  int command_index = operands[0];
  auto execute_request = new DefaultExecuteRequest(command_index, operands[1], operands[2], operands[3]);
  return execute_request;
}

bool CommandHandler::is_end_of_commands(const std::string &input) {
  return input == END_OF_COMMANDS;
}

void CommandHandler::run_end_of_commands_routine() {
  logger->info("End of commands routine started");
  store_map[REGISTER_STORE_TYPE]->print(output_writer);
  for (const auto &item: store_map) {
    item.second->clear();
  }
  logger->info("End of commands routine ended");

}


