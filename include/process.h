#ifndef PROCESS_H
#define PROCRESS_H

#include <string>
using namespace std;

struct Process{
    string id;
    int bt, at, q ,pr;
    int remaining;
    int wt=0, ct=0, rt=-1, tat=0;
};

#endif

