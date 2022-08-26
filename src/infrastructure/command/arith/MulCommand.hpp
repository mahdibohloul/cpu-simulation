#ifndef CPU_SIMULATION_MULCOMMAND_HPP
#define CPU_SIMULATION_MULCOMMAND_HPP


#include "../Command.hpp"
#include "../../logger/Logger.hpp"
#include "../../logger/LoggerFactory.hpp"

class MulCommand : public Command {
public:
    MulCommand(Store *store) : Command(store) {
      logger = LoggerFactory::getLogger("MulCommand");
    }

    void execute(int arg1, int arg2, int arg3) override;

private:
    Logger *logger;
};


#endif //CPU_SIMULATION_MULCOMMAND_HPP
