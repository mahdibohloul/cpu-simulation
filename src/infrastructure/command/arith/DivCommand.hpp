//
// Created by tapsi on 8/26/22.
//

#ifndef CPU_SIMULATION_DIVCOMMAND_HPP
#define CPU_SIMULATION_DIVCOMMAND_HPP


#include "../Command.hpp"
#include "../../logger/Logger.hpp"
#include "../../logger/LoggerFactory.hpp"

class DivCommand : public Command {
public:
    DivCommand(Store *store) : Command(store) {
      logger = LoggerFactory::getLogger("DivCommand");
    }

    void execute(int arg1, int arg2, int arg3) override;
private:
    Logger *logger;
};


#endif //CPU_SIMULATION_DIVCOMMAND_HPP
