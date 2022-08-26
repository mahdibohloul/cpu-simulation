//
// Created by tapsi on 8/26/22.
//

#ifndef CPU_SIMULATION_ARITHUNIT_HPP
#define CPU_SIMULATION_ARITHUNIT_HPP


#include "../../infrastructure/unit/ControlUnit.hpp"
#include "../../infrastructure/logger/Logger.hpp"

class ArithUnit : public ControlUnit {
public:
    static ArithUnit *get_instance(Store *store);

    void execute(ExecuteRequest *execute_request) override;

private:
    ArithUnit(Store *store);

    void register_commands() override;

    Command *get_command(int command_index) override;
private:
    static ArithUnit *instance;
    Logger *logger;
};


#endif //CPU_SIMULATION_ARITHUNIT_HPP
