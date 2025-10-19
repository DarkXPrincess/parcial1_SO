#ifndef MLQ_H
#define MLQ_H

#include "Scheduler.h"
#include <vector>

class MLQ{
    std::vector<Scheduler*>queues;
public:
    MLQ(std::vector<Scheduler*> q);
    std::vector<Process> execute(std::vector<Process> &processes);

};
#endif