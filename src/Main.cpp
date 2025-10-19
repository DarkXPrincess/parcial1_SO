#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

#include "RoundRobin.h"
#include "FCFS.h"
#include "MLQ.h"

using namespace std;

int main() {
    vector<Process> processes;
    ifstream file("mlq001.txt");
    if (!file.is_open()) {
        cerr << "Error: no se pudo abrir mlq001.txt\n";
        return 1;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        stringstream ss(line);
        string id; int bt, at, q, pr;
        char sep;
        getline(ss, id, ';');
        ss >> bt >> sep >> at >> sep >> q >> sep >> pr;
        processes.push_back({id, bt, at, q, pr, bt});
    }

    RoundRobin rr3(3);
    RoundRobin rr5(5);
    FCFS fcfs;
    MLQ mlq({&rr3, &rr5, &fcfs});

    auto result = mlq.execute(processes);

    double avgWT = 0, avgCT = 0, avgRT = 0, avgTAT = 0;
    for (auto &p : result) {
        avgWT += p.wt;
        avgCT += p.ct;
        avgRT += (p.rt == -1 ? 0 : p.rt);
        avgTAT += p.tat;
    }
    int n = result.size();
    avgWT /= n; avgCT /= n; avgRT /= n; avgTAT /= n;

    ofstream out("salida.txt");
    out << "# etiqueta; BT; AT; Q; Pr; WT; CT; RT; TAT\n";
    for (auto &p : result) {
        out << p.id << ";" << p.bt << ";" << p.at << ";" << p.q << ";" << p.pr << ";"
            << p.wt << ";" << p.ct << ";" << p.rt << ";" << p.tat << "\n";
    }

    out << fixed << setprecision(2);
    out << "\nWT=" << avgWT << "; CT=" << avgCT
        << "; RT=" << avgRT << "; TAT=" << avgTAT << ";\n";
    out.close();

    cout << "Simulación MLQ (RR3, RR5, FCFS) completada.\n";
    cout << "Resultados guardados en salida.txt\n";
    return 0;
}
