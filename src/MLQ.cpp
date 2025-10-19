#include "MLQ.h"
using namespace std;

MLQ::MLQ(vector<Scheduler*> q) : queues(q) {}

vector<Process> MLQ::execute(vector<Process> &processes) {
    vector<Process> completed;
    int time = 0;
    for (int i = 0; i < queues.size(); ++i) {
        for (auto &p : processes)
            if (p.q == i + 1) {
                p.remaining = p.bt;
                queues[i]->add(p);
            }
        auto done = queues[i]->execute(time);
        completed.insert(completed.end(), done.begin(), done.end());
    }
    return completed;
}
