#ifndef RR_H
#define RR_H

#include "Scheduler.h"
#include <queue>

class RR : public Scheduler {
    int quantum;
    std::queue<Process> ready;
public:
    RR(int q);
    void add(Process p) override;
    std::vector<Process> execute (int &time) override;
};
#endif