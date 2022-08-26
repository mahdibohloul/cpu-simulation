#ifndef CPU_SIMULATION_COMMAND_HPP
#define CPU_SIMULATION_COMMAND_HPP


#include "../store/Store.hpp"

class Command {
public:
    Command(Store *store) : store(store) {}

    virtual void execute(int arg1, int arg2, int arg3) = 0;

protected:
    Store *store;
};


#endif //CPU_SIMULATION_COMMAND_HPP
