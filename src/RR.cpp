#include "RR.h"
using namespace std;

// Constructor
RR::RR(int q) {
    quantum = q;
}

// Método add: agrega un proceso a la cola
void RR::add(Process p) {
    ready.push(p);
}

// Método execute: ejecuta todos los procesos en Round Robin
vector<Process> RR::execute(int &time) {
    vector<Process> completed;
    while (!ready.empty()) {
        Process p = ready.front();
        ready.pop();

        if (p.rt == -1)
            p.rt = max(0, time - p.at);

        int execTime = min(quantum, p.remaining);
        time = max(time, p.at);
        p.remaining -= execTime;
        time += execTime;

        if (p.remaining > 0)
            ready.push(p);
        else {
            p.ct = time;
            p.tat = p.ct - p.at;
            p.wt = p.tat - p.bt;
            completed.push_back(p);
        }
    }
    return completed;
}
