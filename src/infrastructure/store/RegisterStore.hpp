//
// Created by tapsi on 8/26/22.
//

#ifndef CPU_SIMULATION_REGISTERSTORE_HPP
#define CPU_SIMULATION_REGISTERSTORE_HPP


#include "Store.hpp"

#define REGISTER_SIZE 16

class RegisterStore : public Store {
public:
    static RegisterStore *get_instance();

    void store(int index, int value) override;

    void print(OutputWriter *output_writer) override;

private:
    RegisterStore();

    void validateIndex(int index) override;

private:
    static RegisterStore *instance;
};


#endif //CPU_SIMULATION_REGISTERSTORE_HPP
