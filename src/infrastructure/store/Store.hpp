#ifndef CPU_SIMULATION_STORE_HPP
#define CPU_SIMULATION_STORE_HPP

#include "map"
#include "../io/output/OutputWriter.hpp"

class Store {
public:
    virtual void store(int index, int value) = 0;

    virtual int load(int index);

    void clear();

    virtual void print(OutputWriter *output_writer) = 0;

protected:
    Store(long memory_size);

    virtual void validateIndex(int index) = 0;

protected:

    long memory_size;
    std::map<int, int> memory;
};


#endif //CPU_SIMULATION_STORE_HPP
