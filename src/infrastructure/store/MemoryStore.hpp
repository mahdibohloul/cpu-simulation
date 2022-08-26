//
// Created by tapsi on 8/26/22.
//

#ifndef CPU_SIMULATION_MEMORYSTORE_HPP
#define CPU_SIMULATION_MEMORYSTORE_HPP


#include "Store.hpp"

#define MEMORY_SIZE 256

class MemoryStore : public Store {
public:
    static MemoryStore *get_instance();

    void store(int index, int value) override;

    void print(OutputWriter *output_writer) override;

private:
    void validateIndex(int index) override;

    MemoryStore();

private:
    static MemoryStore *instance;
};


#endif //CPU_SIMULATION_MEMORYSTORE_HPP
