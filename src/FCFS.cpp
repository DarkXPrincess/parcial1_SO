#include "FCFS.h"
using namespace std;

void FCFS::add(Process p) {
    ready.push_back(p);
}

vector<Process> FCFS::execute(int &time) {
    vector<Process> completed;
    sort(ready.begin(), ready.end(), [](Process &a, Process &b) {
        return a.at < b.at;
    });

    for (auto &p : ready) {
        if (time < p.at) time = p.at;
        if (p.rt == -1) p.rt = time - p.at;
        time += p.bt;
        p.ct = time;
        p.tat = p.ct - p.at;
        p.wt = p.tat - p.bt;
        completed.push_back(p);
    }
    return completed;
}
