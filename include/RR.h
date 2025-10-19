#ifndef RR_H
#define RR_H

#include "scheduler.h"
#include <queue>

class RR : public scheduler {
    int quantum;
    std::queue<process> ready;
public:
    RR(int q);
    void add(process p) override;
    std::vector<process> execute(int &time) override;
};
#endif