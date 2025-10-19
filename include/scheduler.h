#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "process.h"

class scheduler{
    public:
        virtual void add(process p)=0
        virtual std::vector<process> execute(int &currentTime)=0;
        virtual ~scheduler(){}

} ;

#endif