//
// Created by tapsi on 8/26/22.
//

#ifndef CPU_SIMULATION_EXECUTEREQUEST_HPP
#define CPU_SIMULATION_EXECUTEREQUEST_HPP


class ExecuteRequest {
public:
    virtual int get_first_op() = 0;

    virtual int get_second_op() = 0;

    virtual int get_third_op() = 0;

    virtual int get_command_index() = 0;

    virtual ~ExecuteRequest() {}
};


#endif //CPU_SIMULATION_EXECUTEREQUEST_HPP
