//
// Created by tapsi on 8/26/22.
//

#ifndef CPU_SIMULATION_LDIMMCOMMAND_HPP
#define CPU_SIMULATION_LDIMMCOMMAND_HPP


#include "../Command.hpp"
#include "../../logger/Logger.hpp"
#include "../../logger/LoggerFactory.hpp"

class LdimmCommand : public Command {
public:
    explicit LdimmCommand(Store *store) : Command(store) {
      logger = LoggerFactory::getLogger("LdimmCommand");
    }

    void execute(int arg1, int arg2, int arg3) override;

private:
    Logger *logger;
};


#endif //CPU_SIMULATION_LDIMMCOMMAND_HPP
