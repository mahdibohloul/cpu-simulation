//
// Created by tapsi on 8/26/22.
//

#ifndef CPU_SIMULATION_MV2REGCOMMAND_HPP
#define CPU_SIMULATION_MV2REGCOMMAND_HPP


#include "../Command.hpp"
#include "../../logger/Logger.hpp"
#include "../../logger/LoggerFactory.hpp"

class Mv2RegCommand : public Command {
public:
    explicit Mv2RegCommand(Store *store) : Command(store) {
      logger = LoggerFactory::getLogger("Mv2RegCommand");
    }

    void execute(int arg1, int arg2, int arg3) override;

private:
    Logger *logger;
};


#endif //CPU_SIMULATION_MV2REGCOMMAND_HPP
