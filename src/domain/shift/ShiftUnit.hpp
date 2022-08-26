//
// Created by tapsi on 8/26/22.
//

#ifndef CPU_SIMULATION_SHIFTUNIT_HPP
#define CPU_SIMULATION_SHIFTUNIT_HPP


#include "../../infrastructure/unit/ControlUnit.hpp"
#include "../../infrastructure/logger/Logger.hpp"

class ShiftUnit : public ControlUnit {
public:
    static ShiftUnit *get_instance(Store *store);

    void execute(ExecuteRequest *execute_request) override;

private:
    explicit ShiftUnit(Store *store);

    void register_commands() override;

    Command *get_command(int command_index) override;

private:
    static ShiftUnit *instance;
    Logger *logger;
};


#endif //CPU_SIMULATION_SHIFTUNIT_HPP
