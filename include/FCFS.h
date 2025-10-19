#ifndef FCFS_H
#define FCFS_H

#include "scheduler.h"
#include <algorithm>

class FCFS : public scheduler {
    std::vector<process> ready;
public:
    void add(process p) override;
    std::vector<process> execute(int &time) override;

};
#endif