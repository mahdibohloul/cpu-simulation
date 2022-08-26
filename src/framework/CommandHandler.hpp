//
// Created by tapsi on 8/26/22.
//

#ifndef CPU_SIMULATION_COMMANDHANDLER_HPP
#define CPU_SIMULATION_COMMANDHANDLER_HPP


#include "../infrastructure/io/input/InputReader.hpp"
#include "../infrastructure/io/output/OutputWriter.hpp"
#include "../infrastructure/io/input/StdInputReader.hpp"
#include "../infrastructure/io/output/StdOutputWriter.hpp"
#include "../infrastructure/logger/Logger.hpp"
#include "../infrastructure/store/MemoryStore.hpp"
#include "../infrastructure/store/RegisterStore.hpp"
#include "../infrastructure/unit/ControlUnit.hpp"
#include "vector"
#include "../infrastructure/unit/DefaultExecuteRequest.hpp"

#define ARITH_CONTROL_UNIT "arith"
#define LOGIC_CONTROL_UNIT "logic"
#define SHIFT_CONTROL_UNIT "shift"
#define MOVE_CONTROL_UNIT "move"
#define MEMORY_STORE_TYPE "mem"
#define REGISTER_STORE_TYPE "reg"
#define OPERANDS_SEPARATOR " "
#define OPERANDS_NUMBER 4
#define END_OF_COMMANDS "$"

class CommandHandler {
public:
    static CommandHandler *get_instance();

    void handle();

private:
    CommandHandler();

    virtual ~CommandHandler();

    bool is_unit_command(const std::string &input);

    bool is_store_command(const std::string &input);

    void initialize_stores();

    void initialize_control_units();

    void change_control_unit(const std::string &unit_name);

    void change_store(const std::string &store_name);

    void run_end_of_commands_routine();

    static std::vector<int> get_operands(const std::string &input, int num_operands, const char *delimiter);

    static DefaultExecuteRequest *get_execute_request(const std::string &input);

    static bool is_end_of_commands(const std::string &input);


private:
    static CommandHandler *instance;
    InputReader *input_reader;
    OutputWriter *output_writer;
    Logger *logger;
    ControlUnit *current_control_unit;
    Store *current_store;
    std::map<std::string, ControlUnit *> control_unit_map;
    std::map<std::string, Store *> store_map;

};


#endif //CPU_SIMULATION_COMMANDHANDLER_HPP
