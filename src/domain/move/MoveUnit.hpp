//
// Created by tapsi on 8/26/22.
//

#ifndef CPU_SIMULATION_MOVEUNIT_HPP
#define CPU_SIMULATION_MOVEUNIT_HPP


#include "../../infrastructure/unit/ControlUnit.hpp"
#include "../../infrastructure/logger/Logger.hpp"

class MoveUnit : public ControlUnit {
public:
    static MoveUnit *get_instance(Store *store);

    void execute(ExecuteRequest *execute_request) override;

private:
    explicit MoveUnit(Store *store);

    void register_commands() override;

    Command *get_command(int command_index) override;

private:
    static MoveUnit *instance;
    Logger *logger;
};


#endif //CPU_SIMULATION_MOVEUNIT_HPP
