//
// Created by tapsi on 8/26/22.
//

#ifndef CPU_SIMULATION_SHRARITHCOMMAND_HPP
#define CPU_SIMULATION_SHRARITHCOMMAND_HPP


#include "../Command.hpp"
#include "../../logger/Logger.hpp"
#include "../../logger/LoggerFactory.hpp"

class ShrArithCommand : public Command {
public:
    explicit ShrArithCommand(Store *store) : Command(store) {
      logger = LoggerFactory::getLogger("ShrArithCommand");
    }

    void execute(int arg1, int arg2, int arg3) override;

private:
    Logger *logger;
};


#endif //CPU_SIMULATION_SHRARITHCOMMAND_HPP
