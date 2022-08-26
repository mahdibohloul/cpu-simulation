#ifndef CPU_SIMULATION_CONTROLUNIT_HPP
#define CPU_SIMULATION_CONTROLUNIT_HPP


#include "../store/Store.hpp"
#include "../command/Command.hpp"
#include "ExecuteRequest.hpp"

//abstract class for control unit
class ControlUnit {
public:
    virtual void execute(ExecuteRequest *execute_request) = 0;
    virtual void change_store(Store *_store);

protected:
    ControlUnit(Store *store) : store(store) {
      commands.clear();
    }

    virtual void register_commands() = 0;

    virtual Command *get_command(int command_index) = 0;

protected:
    Store *store;
    std::map<int, Command *> commands;
};


#endif //CPU_SIMULATION_CONTROLUNIT_HPP
