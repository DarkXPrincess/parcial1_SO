#include "RR.h"
using namespace std;

RR:RR(int q) :quantum(q){}

void RR::add(process p){
    ready.push(p);
}

vector<process> RR::execute(int &time){
    vector<process> completed;
    while(!ready.empty()){
        process p=ready.front();
        ready.pop();

        if(p.rt==-1)
            p.rt=max(0, time - p.at);
        
        int execTime= min(quantum, p.remaining);
        time =max(time, p.at);
        p.remaining -=execTime;
        time +=exectTime;

        if(p.remaining>0)
            ready.push(p);
        else{
            p.ct=time;
            p.tat=p.ct - p.at;
            p.wt = p.tat - p.bt;
            completed.push_back(p);
        }
    }
    return completed;
}