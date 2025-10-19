#ifndef FCFS_H
#define FCFS_H

#include "Scheduler.h"
#include <algorithm>

class FCFS : public Scheduler {
    std::vector<Process> ready;
public:
    void add(Process p) override;
    std::vector<Process> execute(int &time) override;

};
#endif