//
// Created by tapsi on 8/26/22.
//

#ifndef CPU_SIMULATION_OUTPUTWRITER_HPP
#define CPU_SIMULATION_OUTPUTWRITER_HPP

#include "string"

class OutputWriter {
public:
    virtual void writeOutput(std::string output) = 0;

    ~OutputWriter() = default;
};


#endif //CPU_SIMULATION_OUTPUTWRITER_HPP
