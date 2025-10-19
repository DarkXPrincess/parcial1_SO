#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "Process.h"

class Scheduler {
public:
    virtual void add(Process p) = 0;
    virtual std::vector<Process> execute(int &currentTime) = 0;
    virtual ~Scheduler() {}
};

#endif
