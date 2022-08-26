//
// Created by tapsi on 8/26/22.
//

#ifndef CPU_SIMULATION_INPUTREADER_HPP
#define CPU_SIMULATION_INPUTREADER_HPP

#include "string"

class InputReader {
public:
    virtual std::string read_input() = 0;

    virtual bool has_more_input() = 0;

    virtual ~InputReader() = default;
};


#endif //CPU_SIMULATION_INPUTREADER_HPP
