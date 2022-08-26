//
// Created by tapsi on 8/26/22.
//

#ifndef CPU_SIMULATION_SHLCOMMAND_HPP
#define CPU_SIMULATION_SHLCOMMAND_HPP


#include "../Command.hpp"
#include "../../logger/Logger.hpp"
#include "../../logger/LoggerFactory.hpp"

class ShlCommand : public Command {
public:
    explicit ShlCommand(Store *store) : Command(store) {
      logger = LoggerFactory::getLogger("ShlCommand");
    }

    void execute(int arg1, int arg2, int arg3) override;

private:
    Logger* logger;
};


#endif //CPU_SIMULATION_SHLCOMMAND_HPP
