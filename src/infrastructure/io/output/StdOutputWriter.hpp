//
// Created by tapsi on 8/26/22.
//

#ifndef CPU_SIMULATION_STDOUTPUTWRITER_HPP
#define CPU_SIMULATION_STDOUTPUTWRITER_HPP


#include "OutputWriter.hpp"
#include "iostream"

class StdOutputWriter : public OutputWriter {
    void writeOutput(std::string output) override;
};


#endif //CPU_SIMULATION_STDOUTPUTWRITER_HPP
