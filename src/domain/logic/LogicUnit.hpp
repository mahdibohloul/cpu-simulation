//
// Created by tapsi on 8/26/22.
//

#ifndef CPU_SIMULATION_LOGICUNIT_HPP
#define CPU_SIMULATION_LOGICUNIT_HPP


#include "../../infrastructure/unit/ControlUnit.hpp"
#include "../../infrastructure/logger/Logger.hpp"

class LogicUnit : public ControlUnit {
public:
    static LogicUnit *get_instance(Store *store);

    void execute(ExecuteRequest *execute_request) override;

private:
    explicit LogicUnit(Store *store);

    void register_commands() override;

    Command *get_command(int command_index) override;

private:
    static LogicUnit *instance;
    Logger* logger;
};


#endif //CPU_SIMULATION_LOGICUNIT_HPP
