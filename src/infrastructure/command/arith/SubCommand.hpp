#ifndef CPU_SIMULATION_SUBCOMMAND_HPP
#define CPU_SIMULATION_SUBCOMMAND_HPP


#include "../Command.hpp"
#include "../../logger/Logger.hpp"
#include "../../logger/LoggerFactory.hpp"

class SubCommand : public Command {
public:
    SubCommand(Store *store) : Command(store) {
      logger = LoggerFactory::getLogger("SubCommand");
    }

    void execute(int arg1, int arg2, int arg3) override;

private:
    Logger *logger;
};


#endif //CPU_SIMULATION_SUBCOMMAND_HPP
