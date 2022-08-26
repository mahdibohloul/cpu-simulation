//
// Created by tapsi on 8/26/22.
//

#ifndef CPU_SIMULATION_NOTCOMMAND_HPP
#define CPU_SIMULATION_NOTCOMMAND_HPP


#include "../Command.hpp"
#include "../../logger/Logger.hpp"
#include "../../logger/LoggerFactory.hpp"

class NotCommand : public Command {
public:
    explicit NotCommand(Store *store) : Command(store) {
      logger = LoggerFactory::getLogger("NotCommand");
    }

    void execute(int arg1, int arg2, int arg3) override;

private:
    Logger *logger;
};


#endif //CPU_SIMULATION_NOTCOMMAND_HPP
