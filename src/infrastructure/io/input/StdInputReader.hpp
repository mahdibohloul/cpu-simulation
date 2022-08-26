//
// Created by tapsi on 8/26/22.
//

#ifndef CPU_SIMULATION_STDINPUTREADER_HPP
#define CPU_SIMULATION_STDINPUTREADER_HPP


#include "InputReader.hpp"
#include "iostream"

class StdInputReader : public InputReader {
public:
    std::string read_input() override;

    bool has_more_input() override;
};


#endif //CPU_SIMULATION_STDINPUTREADER_HPP
