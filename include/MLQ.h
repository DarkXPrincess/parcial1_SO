#ifndef MLQ_H
#define MLQ_H

#include "scheduler.h"
#include <vector>

class MLQ{
    std::vector<scheduler*>queues;
public:
    MLQ(std::vector<scheduler*> q);
    std::vector<process> execute(std::vector<process> &processes);

};
#endif