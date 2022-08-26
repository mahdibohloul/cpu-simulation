#ifndef CPU_SIMULATION_DEFAULTEXECUTEREQUEST_HPP
#define CPU_SIMULATION_DEFAULTEXECUTEREQUEST_HPP


#include "ExecuteRequest.hpp"

class DefaultExecuteRequest : public ExecuteRequest {
public:
    int get_first_op() override {
      return operand1;
    }

    int get_second_op() override {
      return operand2;
    }

    int get_third_op() override {
      return operand3;
    }

    int get_command_index() override {
      return command_index;
    }

    DefaultExecuteRequest(int command_index, int operand1, int operand2, int operand3) {
      this->operand1 = operand1;
      this->operand2 = operand2;
      this->operand3 = operand3;
      this->command_index = command_index;
    }

private:
    int operand1;
    int operand2;
    int operand3;
    int command_index;
};


#endif //CPU_SIMULATION_DEFAULTEXECUTEREQUEST_HPP
