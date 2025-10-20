#ifndef PROCESS_H
#define PROCESS_H
#include <string>
struct Process {
    std::string id;
    int bt, at, q, pr;
    int remaining;
    int wt = 0, ct = 0, rt = -1, tat = 0;
};
#endif
